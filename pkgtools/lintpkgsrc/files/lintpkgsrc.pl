#!@PERL5@

# $NetBSD: lintpkgsrc.pl,v 1.44 2022/08/03 19:22:34 rillig Exp $

# Written by David Brownlee <abs@netbsd.org>.
#
# Caveats:
#	The 'Makefile parsing' algorithm used to obtain package versions and
#	DEPENDS information is geared towards speed rather than perfection,
#	though it has gotten somewhat better over time, it only parses the
#	simpler Makefile conditionals.
#
# TODO: Handle fun DEPENDS like avifile-devel with
#			{qt2-designer>=2.2.4,qt2-designer-kde>=2.3.1nb1}

use locale;
use strict;
use warnings;
use Getopt::Std;
use File::Find;
use File::Basename;
use IPC::Open3;
use Cwd 'realpath', 'getcwd';

# PkgVer is a PKGBASE + PKGVERSION, including some of the variables that
# have been extracted from the package Makefile.
#
package PkgVer;

sub new($$$) {
	my ($class, $pkgbase, $pkgversion) = @_;
	my $self = {
	    pkgbase    => $pkgbase,
	    pkgversion => $pkgversion,
	    vars       => {},
	};
	bless $self, $class;
	return $self;
}

sub pkg($) {
	my ($self) = @_;

	$self->{pkgbase};
}

sub ver($) {
	my ($self) = @_;

	$self->{pkgversion};
}

sub pkgname($) {
	my $self = shift;

	$self->pkg . '-' . $self->ver;
}

sub var($$$) {
	my ($self, $key, $val) = @_;

	(defined $val)
	    ? ($self->{vars}->{$key} = $val)
	    : $self->{vars}->{$key};
}

sub vars($) {
	my ($self) = @_;

	keys %{$self->{vars}};
}

sub store($) {
	my $self = shift;

	my $name = $self->pkg;
	my $ver = $self->ver;

	$name =~ /\s/ and die "cannot store package name '$name'\n";
	$ver =~ /\s/ and die "cannot store package version '$ver'\n";
	printf("package\t%s\t%s\n", $name, $ver);

	foreach my $varname (sort $self->vars) {
		my $value = $self->{$varname};
		$varname =~ /\s/ and die "cannot store variable name '$varname'\n";
		$value =~ /\n/ and die "cannot store variable value '$value'\n";
		printf("var\t%s\t%s\n", $varname, $value);
	}
}

# Pkgs collects all versions of a given PKGBASE, e.g. apache-1.3.27 and
# apache-2.0.46.
#
package Pkgs;

sub add($@) {
	my $self = shift;

	$self->{_pkgver}{$_[1]} = new PkgVer @_;
}

sub new($@) {
	my $class = shift;
	my $self = {};

	bless $self, $class;
	$self->{_pkg} = $_[0];
	return $self;
}

# Returns all available versions of the package, in decreasing
# alphabetical(!) order.
sub versions($) {
	my $self = shift;

	return sort { $b cmp $a } keys %{$self->{_pkgver}};
}

sub pkg($) {
	my $self = shift;
	$self->{_pkg};
}

# Returns all available versioned packages of this PKGBASE, in decreasing
# alphabetical(!) order.
sub pkgver($@) {
	my $self = shift;

	my $pkgvers = $self->{_pkgver};
	if (@_) {
		if ($pkgvers->{$_[0]}) {
			return ($pkgvers->{$_[0]});
		}
		return;
	}
	return sort { $b->ver cmp $a->ver } values %{$pkgvers};
}

sub latestver($) {
	my $self = shift;

	($self->pkgver())[0];
}

sub store($) {
	my $self = shift;

	my $pkgvers = $self->{_pkgver};
	foreach my $pkgver (sort keys %$pkgvers) {
		$pkgvers->{$pkgver}->store();
	}
}

# PkgList is the master list of all packages in pkgsrc.
#
package PkgList;

sub add($@) {
	my $self = shift;

	if (!$self->pkgs($_[0])) {
		$self->{_pkgs}{ $_[0] } = new Pkgs $_[0];
	}
	$self->pkgs($_[0])->add(@_);
}

sub new($) {
	my $class = shift;
	my $self = {};
	bless $self, $class;
	return $self;
}

sub numpkgver($) {
	my $self = shift;
	scalar($self->pkgver);
}

sub pkgver($@) {
	my $self = shift;

	if (@_ == 0) {
		my (@list);
		foreach my $pkg ($self->pkgs) {
			push(@list, $pkg->pkgver);
		}
		return (@list);
	}

	if (defined $self->{_pkgs}{$_[0]}) {
		return (@_ > 1)
		    ? $self->{_pkgs}{$_[0]}->pkgver($_[1])
		    : $self->{_pkgs}{$_[0]}->pkgver();
	}
	return;
}

sub pkgs($@) {
	my $self = shift;

	if (@_) {
		return $self->{_pkgs}{$_[0]};
	} else {
		return (sort { $a->pkg cmp $b->pkg } values %{$self->{_pkgs}});
	}
}

sub store($) {
	my $self = shift;

	my $pkgs = $self->{_pkgs};
	foreach my $pkg (sort keys %$pkgs) {
		$pkgs->{$pkg}->store();
	}
}

package main;

# Buildtime configuration
my $conf_make = '@MAKE@';
my $conf_pkgsrcdir = '@PKGSRCDIR@';
my $conf_prefix = '@PREFIX@';
my $conf_sysconfdir = '@PKG_SYSCONFDIR@';

my (
    $pkglist,                  # list of Pkg packages
    $pkg_installver,           # installed version of pkg_install pseudo-pkg
    $default_vars,             # Set for Makefiles, inc PACKAGES & PKGSRCDIR
    %opt,                      # Command line options
    @matched_prebuiltpackages, # List of obsolete prebuilt package paths
    @prebuilt_pkgdirs,         # Use to follow symlinks in prebuilt pkgdirs
    %prebuilt_pkgdir_cache,    # To avoid symlink loops in prebuilt_pkgdirs
);

# Horrible kludge to ensure we have a value for testing in conditionals, but
# gets removed in the final evaluation
my $magic_undefined = 'M_a_G_i_C_uNdEfInEd';

sub debug(@) {

	($opt{D}) && print STDERR 'DEBUG: ', @_;
}

sub verbose(@) {

	if (-t STDERR) {
		print STDERR @_;
	}
}

sub fail($) {

	print STDERR shift(), "\n";
	exit(3);
}

# List (recursive) non directory contents of specified directory
#
#TODO this entire sub should be replaced with direct calls to
#     File::Find
sub listdir($$);
sub listdir($$) {
	my ($base, $dir) = @_;
	my ($thisdir);
	my (@list, @thislist);

	$thisdir = $base;
	if (defined($dir)) {
		$thisdir .= "/$dir";
		$dir .= '/';
	} else {
		$dir = '';
	}

	opendir(DIR, $thisdir) || fail("Unable to opendir($thisdir): $!");
	@thislist = grep(substr($_, 0, 1) ne '.' && $_ ne 'CVS', readdir(DIR));
	closedir(DIR);
	foreach my $entry (@thislist) {
		if (-d "$thisdir/$entry") {
			push(@list, listdir($base, "$dir$entry"));
		} else {
			push(@list, "$dir$entry");
		}
	}
	@list;
}

sub canonicalize_pkgname($) {
	my ($pkgname) = @_;

	$pkgname =~ s,^py\d+(?:pth|)-,py-,;
	$pkgname =~ s,^ruby\d+-,ruby-,;
	$pkgname =~ s,^php\d+-,php-,;
	return $pkgname;
}

sub convert_to_standard_pkgversion(@) {
	my ($elem, @temp);

	# See pkg_install/lib/dewey.c.
	# 'nb' has already been handled when we are here.
	foreach $elem (@_) {
		if ($elem =~ /\d/) {
			push(@temp, $elem);
		} elsif ($elem eq "pl" || $elem eq "." || $elem eq "_") {
			push(@temp, 0);
		} elsif ($elem eq "pre" || $elem eq "rc") {
			push(@temp, -1);
		} elsif ($elem eq "beta") {
			push(@temp, -2);
		} elsif ($elem eq "alpha") {
			push(@temp, -3);
		} else {
			push(@temp, 0);
			push(@temp, ord($elem) - ord("a") + 1);
		}
	}
	@temp;
}

sub pkgversioncmp_extract($$) {
	my ($match, $val) = @_;
	my ($cmp, @matchlist, @vallist);

	@matchlist = convert_to_standard_pkgversion(split(/(\D+)/, lc($match)));
	@vallist = convert_to_standard_pkgversion(split(/(\D+)/, lc($val)));
	$cmp = 0;
	while ($cmp == 0 && (@matchlist || @vallist)) {
		$cmp = ((shift @matchlist || 0) <=> (shift @vallist || 0));
	}
	$cmp;
}

# Package version number matching.
# Also handles 'nb<N>' suffix (checked iff values otherwise identical).
sub pkgversioncmp($$$) {
	my ($match, $test, $val) = @_;
	my ($cmp, $match_nb, $val_nb);

	$match_nb = $val_nb = 0;
	if ($match =~ /(.*)nb(.*)/) {
		# Handle nb<N> suffix
		$match = $1;
		$match_nb = $2;
	}

	if ($val =~ /(.*)nb(.*)/) {
		# Handle nb<N> suffix
		$val = $1;
		$val_nb = $2;
	}

	$cmp = pkgversioncmp_extract($match, $val);

	if (!$cmp) {
		# Iff otherwise identical, check nb suffix
		$cmp = pkgversioncmp_extract($match_nb, $val_nb);
	}

	debug("eval pkgversioncmp $cmp $test 0\n");
	eval "$cmp $test 0";
}

# Return a copy of $line in which trivial variable expressions are replaced
# with the variable values.
sub parse_expand_vars($$) {
	my ($line, $vars) = @_;

	while ($line =~ /\$\{([-\w.]+)\}/) {
		if (defined(${$vars}{$1})) {
			$line = $` . ${$vars}{$1} . $';
		} else {
			$line = $` . $magic_undefined . $';
		}
	}
	$line;
}

sub parse_eval_make_false($$) {
	my ($line, $vars) = @_;
	my ($false, $test);

	$false = 0;
	$test = parse_expand_vars($line, $vars);

	# XXX This is _so_ wrong - need to parse this correctly
	$test =~ s/""/\r/g;
	$test =~ s/"//g; # "
	$test =~ s/\r/""/g;

	debug("conditional: $test\n");

	# XXX Could do something with target
	while ($test =~ /(target|empty|make|defined|exists)\s*\(([^()]+)\)/) {
		my ($testname, $varname) = ($1, $2);
		my $var;

		# Implement (some of) make's :M modifier
		if ($varname =~ /^([^:]+):M(.+)$/) {
			$varname = $1;
			my $match = $2;

			$var = $${vars}{$varname};
			$var = parse_expand_vars($var, $vars)
			    if defined $var;

			$match =~ s/([{.+])/\\$1/g;
			$match =~ s/\*/.*/g;
			$match =~ s/\?/./g;
			$match = '^' . $match . '$';
			$var = ($var =~ /$match/)
			    if defined $var;
		} else {
			$var = $${vars}{$varname};
			$var = parse_expand_vars($var, $vars)
			    if defined $var;
		}

		if (defined $var && $var eq $magic_undefined) {
			$var = undef;
		}

		if ($testname eq 'exists') {
			$_ = (-e $varname) ? 1 : 0;

		} elsif ($testname eq 'defined') {
			$_ = defined($var) ? 1 : 0;

		} elsif ($testname eq 'empty') {
			$_ = ((not defined($var) or (length($var) == 0)) ? 1 : 0);

		} else {
			$_ = 0;
		}

		$test =~ s/$testname\s*\([^()]+\)/$_/;
		debug("conditional: update to $test\n");
	}

	while ($test =~ /([^\s()\|\&]+)\s+(!=|==)\s+([^\s()]+)/) {
		if ($2 eq '==') {
			$_ = ($1 eq $3) ? 1 : 0;
		} else {
			$_ = ($1 ne $3) ? 1 : 0;
		}
		$test =~ s/[^\s()\|\&]+\s+(!=|==)\s+[^\s()]+/$_/;
	}

	if ($test !~ /[^<>\d()\s&|.!]/) {
		debug("eval test $test\n");
		$false = eval "($test)?0:1";
		if (!defined $false) {
			fail("Eval failed $line - $test");
		}
		debug("conditional: evaluated to " . ($false ? 0 : 1) . "\n");

	} else {
		$false = 0;
		debug("conditional: defaulting to 0\n");
	}
	$false;
}

# Extract variable assignments from Makefile
# Much unpalatable magic to avoid having to use make (all for speed)
#
sub parse_makefile_vars($$) {
	my ($file, $cwd) = @_;
	my (
	    $pkgname, %vars, $plus, $value, @data,
	    %incfiles, # Cache of previously included fils
	    %incdirs,  # Directories in which to check for includes
	    @if_false
	); # 0:true 1:false 2:nested-false&nomore-elsif

	if (!open(FILE, $file)) {
		return (undef);
	}
	@data = map { chomp;
		$_; } <FILE>;
	close(FILE);

	$incdirs{"."} = 1;
	$incdirs{dirname($file)} = 1;

	# Some Makefiles depend on these being set
	if ($file eq '/etc/mk.conf') {
		$vars{LINTPKGSRC} = 'YES';
	} else {
		%vars = %{$default_vars};
	}
	$vars{BSD_PKG_MK} = 'YES';

	if ($cwd) {
		$vars{'.CURDIR'} = $cwd;
	} elsif ($file =~ m#(.*)/#) {
		$vars{'.CURDIR'} = $1;
	} else {
		$vars{'.CURDIR'} = getcwd;
	}

	$incdirs{$vars{'.CURDIR'}} = 1;
	if ($opt{L}) {
		print "$file\n";
	}

	while (defined($_ = shift(@data))) {
		s/\s*[^\\]#.*//;

		# Continuation lines
		#
		while (substr($_, -1) eq "\\") {
			substr($_, -2) = shift @data;
		}

		# Conditionals
		#
		if (m#^\.\s*if(|def|ndef)\s+(.*)#) {
			my ($type, $false);

			$type = $1;
			if ($if_false[$#if_false]) {
				push(@if_false, 2);

			} elsif ($type eq '') {
				# Straight if
				push(@if_false, parse_eval_make_false($2, \%vars));

			} else {
				$false = !defined($vars{ parse_expand_vars($2, \%vars) });
				if ($type eq 'ndef') {
					$false = !$false;
				}
				push(@if_false, $false ? 1 : 0);
			}
			debug("$file: .if$type (! @if_false)\n");
			next;
		}

		if (m#^\.\s*elif\s+(.*)# && @if_false) {
			if ($if_false[$#if_false] == 0) {
				$if_false[$#if_false] = 2;
			} elsif ($if_false[$#if_false] == 1
			    && !parse_eval_make_false($1, \%vars)) {
				$if_false[$#if_false] = 0;
			}
			debug("$file: .elif (! @if_false)\n");
			next;
		}

		if (m#^\.\s*else\b# && @if_false) {
			$if_false[$#if_false] = $if_false[$#if_false] == 1 ? 0 : 1;
			debug("$file: .else (! @if_false)\n");
			next;
		}

		if (m#^\.\s*endif\b#) {
			pop(@if_false);
			debug("$file: .endif (! @if_false)\n");
			next;
		}

		$if_false[$#if_false] && next;

		# Included files (just unshift onto @data)
		#
		if (m#^\.\s*include\s+"([^"]+)"#) {
			my ($incfile) = parse_expand_vars($1, \%vars);

			# At this point just skip any includes which we were not able to
			# fully expand
			if ($incfile =~ m#/mk/bsd#
			    || $incfile =~ /$magic_undefined/
			    || $incfile =~ /\$\{/
			    || (!$opt{d} && $incfile =~ m#/(buildlink[^/]*\.mk)#)) {
				debug("$file: .include \"$incfile\" skipped\n");

			} else {
				debug("$file: .include \"$incfile\"\n");

				# Expand any simple vars in $incfile
				#

				if (substr($incfile, 0, 1) ne '/') {
					foreach my $dir (keys %incdirs) {
						if (-f "$dir/$incfile") {
							$incfile = "$dir/$incfile";
							last;
						}
					}
				}

				# perl 5.6.1 realpath() cannot handle files, only directories
				# If the last component is a symlink this will give a false
				# negative, but that is not a problem as the duplicate check
				# is for performance
				$incfile =~ m#^(.+)(/[^/]+)$#;

				if (!-f $incfile) {
					if (!$opt{L}) {
						verbose("\n");
					}

					verbose("$file: Cannot locate $incfile in "
					    . join(" ", sort keys %incdirs)
					    . "\n");

				} else {
					$incfile = realpath($1) . $2;

					if (!$incfiles{$incfile}) {
						if ($opt{L}) {
							print "inc $incfile\n";
						}
						$incfiles{$incfile} = 1;

						if (!open(FILE, $incfile)) {
							verbose("Cannot open '$incfile' (from $file): $_ $!\n");
						} else {
							my $NEWCURDIR = $incfile;
							$NEWCURDIR =~ s#/[^/]*$##;
							$incdirs{$NEWCURDIR} = 1;
							unshift(@data, ".CURDIR=$vars{'.CURDIR'}");
							unshift(@data, map { chomp;
								$_ } <FILE>);
							unshift(@data, ".CURDIR=$NEWCURDIR");
							close(FILE);
						}
					}
				}
			}
			next;
		}

		if (/^ *([-\w\.]+)\s*([:+?]?)=\s*(.*)/) {
			my ($key);

			$key = $1;
			$plus = $2;
			$value = $3;

			if ($plus eq ':') {
				$vars{$key} = parse_expand_vars($value, \%vars);
			} elsif ($plus eq '+' && defined $vars{$key}) {
				$vars{$key} .= " $value";
			} elsif ($plus ne '?' || !defined $vars{$key}) {
				$vars{$key} = $value;
			}
			debug("assignment: $key$plus=[$value] ($vars{$key})\n");

			# Give python a little hand (XXX - do we wanna consider actually
			# implementing make .for loops, etc?
			#
			if ($key eq "PYTHON_VERSIONS_ACCEPTED") {
				my ($pv);

				foreach $pv (split(/\s+/, $vars{PYTHON_VERSIONS_ACCEPTED})) {
					$vars{"_PYTHON_VERSION_FIRSTACCEPTED"} ||= $pv;
					$vars{"_PYTHON_VERSION_${pv}_OK"} = "yes";
				}
			}
		}
	}

	debug("$file: expand\n");

	# Handle variable substitutions  FRED = a-${JIM:S/-/-b-/}
	#
	my ($loop);

	for ($loop = 1; $loop;) {
		$loop = 0;
		foreach my $key (keys %vars) {
			if (index($vars{$key}, '$') == -1) {
				next;
			}

			$_ = parse_expand_vars($vars{$key}, \%vars);
			if ($_ ne $vars{$key}) {
				$vars{$key} = $_;
				$loop = 1;

			} elsif ($vars{$key} =~ m#\$\{([\w.]+):([CS]([^{}])[^{}\3]+\3[^{}\3]*\3[g1]*(|:[^{}]+)|U[^{}]+)\}#) {
				my ($left, $subvar, $right) = ($`, $1, $');
				my (@patterns) = split(':', $2);
				my ($result);

				$result = $vars{$subvar};
				$result ||= '';

				# If $vars{$subvar} contains a $ skip it on this pass.
				# Hopefully it will get substituted and we can catch it
				# next time around.
				if (index($result, '${') != -1) {
					next;
				}

				debug("$file: substitutelist $key ($result) $subvar (@patterns)\n");
				foreach (@patterns) {
					if (m#(U)(.*)#) {
						$result ||= $2;
					} elsif (m#([CS])(.)([^/@]+)\2([^/@]*)\2([1g]*)#) {
						my ($how, $from, $to, $global) = ($1, $3, $4, $5);

						debug("$file: substituteglob $subvar, $how, $from, $to, $global\n");
						if ($how eq 'S') {
							# Limited substitution - keep ^ and $
							$from =~ s/([?.{}\]\[*+])/\\$1/g;
						}
						$to =~ s/\\(\d)/\$$1/g; # Change \1 etc to $1
						$to =~ s/\&/\$&/g;      # Change & to $1

						my ($notfirst);
						if ($global =~ s/1//) {
							($from, $notfirst) = split('\s', $from, 2);
						}

						debug("$file: substituteperl $subvar, $how, $from, $to\n");
						debug("eval substitute <$from> <$to> <$global>\n");
						eval "\$result =~ s/$from/$to/$global";
						if (defined $notfirst) {
							$result .= " $notfirst";
						}
					} else {
						next;
					}
				}

				$vars{$key} = $left . $result . $right;
				$loop = 1;
			}
		}
	}

	foreach my $key (keys %vars) {
		$vars{$key} =~ s/$magic_undefined//;
	}
	\%vars;
}

sub get_default_makefile_vars() {

	chomp($pkg_installver = `pkg_info -V 2>/dev/null || echo 20010302`);

	chomp($_ = `uname -srm`);
	(
	    $default_vars->{OPSYS},
	    $default_vars->{OS_VERSION},
	    $default_vars->{MACHINE}
	) = (split);
	if (!$default_vars->{MACHINE}) {
		die('Unable to extract machine from uname');
	}

	# Handle systems without uname -p  (NetBSD pre 1.4)
	chomp($default_vars->{MACHINE_ARCH} = `uname -p 2>/dev/null`);

	if (!$default_vars->{MACHINE_ARCH}
	    && $default_vars->{OS_VERSION} eq 'NetBSD') {
		chomp($default_vars->{MACHINE_ARCH} = `sysctl -n hw.machine_arch`);
	}

	if (!$default_vars->{MACHINE_ARCH}) {
		$default_vars->{MACHINE_ARCH} = $default_vars->{MACHINE};
	}

	$default_vars->{OBJECT_FMT} = 'x';
	$default_vars->{LOWER_OPSYS} = lc($default_vars->{OPSYS});

	if ($opt{P}) {
		$default_vars->{PKGSRCDIR} = realpath($opt{P});
	} else {
		$default_vars->{PKGSRCDIR} = $conf_pkgsrcdir;
	}

	$default_vars->{DESTDIR} = '';
	$default_vars->{LOCALBASE} = '/usr/pkg';
	$default_vars->{X11BASE} = '/usr/X11R6';

	my ($vars);
	if (-f '/etc/mk.conf' && ($vars = parse_makefile_vars('/etc/mk.conf', undef))) {
		foreach my $var (keys %{$vars}) {
			$default_vars->{$var} = $vars->{$var};
		}
	} elsif (-f "$conf_sysconfdir/mk.conf" &&
	    ($vars = parse_makefile_vars("$conf_sysconfdir/mk.conf", undef))) {
		foreach my $var (keys %{$vars}) {
			$default_vars->{$var} = $vars->{$var};
		}
	}

	if ($opt{P}) {
		$default_vars->{PKGSRCDIR} = realpath($opt{P});
	}

	if ($opt{M}) {
		$default_vars->{DISTDIR} = realpath($opt{M});
	} else {
		$default_vars->{DISTDIR} ||= $default_vars->{PKGSRCDIR} . '/distfiles';
	}

	if ($opt{K}) {
		$default_vars->{PACKAGES} = realpath($opt{K});
	}

	# Extract some variables from bsd.pkg.mk
	my ($mkvars);
	$mkvars = parse_makefile_vars(
	    "$default_vars->{PKGSRCDIR}/mk/bsd.pkg.mk",
	    "$default_vars->{PKGSRCDIR}/mk/scripts"
	);
	foreach my $varname (keys %{$mkvars}) {
		if ($varname =~ /_REQD$/ || $varname eq 'EXTRACT_SUFX') {
			$default_vars->{$varname} = $mkvars->{$varname};
		}
	}

	$default_vars->{PACKAGES} ||= $default_vars->{PKGSRCDIR} . '/packages';
}

# Determine if a package version is current. If not, report correct version
# if found
#
sub invalid_version($) {
	my ($pkgmatch) = @_;
	my ($fail, $ok);
	my (@pkgmatches, @todo);

	@todo = ($pkgmatch);

	# We handle {} here, everything else in package_globmatch
	while ($pkgmatch = shift @todo) {
		if ($pkgmatch =~ /(.*)\{([^{}]+)}(.*)/) {
			foreach (split(',', $2)) {
				push(@todo, "$1$_$3");
			}
		} else {
			push(@pkgmatches, $pkgmatch);
		}
	}

	foreach $pkgmatch (@pkgmatches) {
		my ($pkg, $badver) = package_globmatch($pkgmatch);

		if (defined($badver)) {
			my ($pkgs);

			if ($pkgs = $pkglist->pkgs($pkg)) {
				$fail .=
				    "Version mismatch: '$pkg' $badver vs "
					. join(',', $pkgs->versions) . "\n";
			} else {
				$fail .= "Unknown package: '$pkg' version $badver\n";
			}
		} else {

			# If we find one match, don't bitch about others
			$ok = 1;
		}
	}
	$ok && ($fail = undef);
	$fail;
}

# Use pkg_info to list installed packages
#
sub list_installed_packages() {
	my (@pkgs);

	open(PKG_INFO, 'pkg_info -e "*" |') || fail("Unable to run pkg_info: $!");
	while (defined(my $pkg = <PKG_INFO>)) {
		chomp($pkg);
		push(@pkgs, canonicalize_pkgname($pkg));
	}
	close(PKG_INFO);

	@pkgs;
}

# List top level pkgsrc categories
#
sub list_pkgsrc_categories($) {
	my ($pkgsrcdir) = @_;
	my (@categories);

	opendir(BASE, $pkgsrcdir) || die("Unable to opendir($pkgsrcdir): $!");
	@categories =
	    grep(substr($_, 0, 1) ne '.'
		&& $_ ne 'CVS'
		&& -f "$pkgsrcdir/$_/Makefile",
		readdir(BASE));
	closedir(BASE);
	@categories;
}

# For a given category, list potentially valid pkgdirs
#
sub list_pkgsrc_pkgdirs($$) {
	my ($pkgsrcdir, $cat) = @_;
	my (@pkgdirs);

	if (!opendir(CAT, "$pkgsrcdir/$cat")) {
		die("Unable to opendir($pkgsrcdir/$cat): $!");
	}
	@pkgdirs =
	    sort grep($_ ne 'Makefile'
		&& $_ ne 'pkg'
		&& $_ ne 'CVS'
		&& substr($_, 0, 1) ne '.',
		readdir(CAT));
	closedir(CAT);
	@pkgdirs;
}

sub glob2regex($) {
	my ($glob) = @_;
	my (@chars, $in_alt);
	my ($regex);

	@chars = split(//, $glob);
	while (defined($_ = shift @chars)) {
		if ($_ eq '*') {
			$regex .= '.*';
		} elsif ($_ eq '?') {
			$regex .= '.';
		} elsif ($_ eq '+') {
			$regex .= '.';
		} elsif ($_ eq '\\+') {
			$regex .= $_ . shift @chars;
		} elsif ($_ eq '.' || $_ eq '|') {
			$regex .= quotemeta;
		} elsif ($_ eq '{') {
			$regex .= '(';
			++$in_alt;
		} elsif ($_ eq '}') {
			if (!$in_alt) {
				# Error
				return undef;
			}
			$regex .= ')';
			--$in_alt;
		} elsif ($_ eq ',' && $in_alt) {
			$regex .= '|';
		} else {
			$regex .= $_;
		}
	}

	if ($in_alt) {
		# Error
		return undef;
	}
	if ($regex eq $glob) {
		return ('');
	}
	if ($opt{D}) {
		print "glob2regex: $glob -> $regex\n";
	}
	'^' . $regex . '$';
}

# Perform some (reasonable) subset of 'pkg_info -e' / glob(3)
# Returns (sometimes best guess at) package name,
# and either 'problem version' or undef if all OK
#
sub package_globmatch($) {
	my ($pkgmatch) = @_;
	my ($matchpkgname, $matchver, $regex);

	if ($pkgmatch =~ /^([^*?[]+)(<|>|<=|>=|-)(\d[^*?[{]*)$/) {

		# (package)(cmp)(pkgversion)
		my ($test, @pkgvers);

		($matchpkgname, $test, $matchver) = ($1, $2, $3);
		if (@pkgvers = $pkglist->pkgver($matchpkgname)) {
			foreach my $pkgver (@pkgvers) {
				if ($test eq '-') {
					if ($pkgver->ver eq $matchver) {
						$matchver = undef;
						last;
					}
				} else {
					if (pkgversioncmp($pkgver->ver, $test, $matchver)) {
						$matchver = undef;
						last;
					}
				}
			}

			if ($matchver && $test ne '-') {
				$matchver = "$test$matchver";
			}
		}

	} elsif ($pkgmatch =~ /^([^[]+)-([\d*?{[].*)$/) {

		# (package)-(globver)
		my (@pkgnames);

		($matchpkgname, $matchver) = ($1, $2);

		if (defined $pkglist->pkgs($matchpkgname)) {
			push(@pkgnames, $matchpkgname);

		} elsif ($regex = glob2regex($matchpkgname)) {
			foreach my $pkg ($pkglist->pkgs) {
				($pkg->pkg() =~ /$regex/) && push(@pkgnames, $pkg->pkg());
			}
		}

		# Try to convert $matchver into regex version
		#
		$regex = glob2regex($matchver);

		foreach my $pkg (@pkgnames) {
			if (defined $pkglist->pkgver($pkg, $matchver)) {
				return ($matchver);
			}

			if ($regex) {
				foreach my $ver ($pkglist->pkgs($pkg)->versions) {
					if ($ver =~ /$regex/) {
						$matchver = undef;
						last;
					}
				}
			}

			$matchver || last;
		}

		# last ditch attempt to handle the whole DEPENDS as a glob
		#
		if ($matchver && ($regex = glob2regex($pkgmatch))) {

			# (large-glob)
			foreach my $pkgver ($pkglist->pkgver) {
				if ($pkgver->pkgname =~ /$regex/) {
					$matchver = undef;
					last;
				}
			}
		}

	} else {
		($matchpkgname, $matchver) = ($pkgmatch, 'missing');
	}

	($matchpkgname, $matchver);
}

# Parse a pkgsrc package makefile and return the pkgname and set variables
#
sub parse_makefile_pkgsrc($) {
	my ($file) = @_;
	my ($pkgname, $vars);

	$vars = parse_makefile_vars($file, undef);

	if (!$vars) {

		# Missing Makefile
		return undef;
	}

	if (defined $vars->{PKGNAME}) {
		$pkgname = $vars->{PKGNAME};
	} elsif (defined $vars->{DISTNAME}) {
		$pkgname = $vars->{DISTNAME};
	}

	if (defined $vars->{PKGNAME}) {
		debug("$file: PKGNAME=$vars->{PKGNAME}\n");
	}
	if (defined $vars->{DISTNAME}) {
		debug("$file: DISTNAME=$vars->{DISTNAME}\n");
	}

	if (!defined $pkgname || $pkgname =~ /\$/ || $pkgname !~ /(.*)-(\d.*)/) {

		# invoke make here as a last resort
		my ($pkgsrcdir) = ($file =~ m:(/.*)/:);
		debug("Running '$conf_make' in '$pkgsrcdir'\n");
		my $pid = open3(\*WTR, \*RDR, \*ERR,
		    "cd $pkgsrcdir || exit 1; $conf_make show-vars VARNAMES=PKGNAME");
		if (!$pid) {
			warn "$file: Unable to run make: $!";
		} else {
			close(WTR);
			my @errors = <ERR>;
			close(ERR);
			my ($makepkgname) = <RDR>;
			close(RDR);
			wait;
			chomp @errors;
			if (@errors) { warn "\n$file: @errors\n"; }

			if ($makepkgname =~ /(.*)-(\d.*)/) {
				$pkgname = $makepkgname;
			}
		}
	}

	if (defined $pkgname) {
		if ($pkgname =~ /^pkg_install-(\d+)$/ && $1 < $pkg_installver) {
			$pkgname = "pkg_install-$pkg_installver";
		}

		$pkgname = canonicalize_pkgname($pkgname);

		if (defined $vars->{PKGREVISION}
		    and not $vars->{PKGREVISION} =~ /^\s*$/) {
			if ($vars->{PKGREVISION} =~ /^\$\{(_(CVS|GIT|HG|SVN)_PKGVERSION):.*\}$/) {
				# See wip/mk/*-package.mk.
			} elsif ($vars->{PKGREVISION} =~ /\D/) {
				print "\nBogus: PKGREVISION $vars->{PKGREVISION} (from $file)\n";

			} elsif ($vars->{PKGREVISION}) {
				$pkgname .= "nb";
				$pkgname .= $vars->{PKGREVISION};
			}
		}

		if ($pkgname =~ /\$/) {
			print "\nBogus: $pkgname (from $file)\n";

		} elsif ($pkgname =~ /(.*)-(\d.*)/) {
			if ($pkglist) {
				my ($pkgver) = $pkglist->add($1, $2);

				debug("add $1 $2\n");

				foreach my $var (qw(DEPENDS RESTRICTED OSVERSION_SPECIFIC BROKEN)) {
					$pkgver->var($var, $vars->{$var});
				}

				if (defined $vars->{NO_BIN_ON_FTP}) {
					$pkgver->var('RESTRICTED', 'NO_BIN_ON_FTP');
				}

				if ($file =~ m:([^/]+/[^/]+)/Makefile$:) {
					$pkgver->var('dir', $1);
				} else {
					$pkgver->var('dir', 'unknown');
				}
			}
		} else {
			print "Cannot extract $pkgname version ($file)\n";
		}

		return ($pkgname, $vars);

	} else {
		return (undef);
	}
}


sub chdir_or_fail($) {
	my ($dir) = @_;

	debug("chdir: $dir");
	chdir($dir) or fail("Cannot chdir($dir): $!\n");
}

sub load_pkgsrc_makefiles($) {
	my ($fname) = @_;

	open(STORE, "<", $fname)
	    or die("Cannot read pkgsrc store from $fname: $!\n");
	my ($pkgver);
	$pkglist = PkgList->new;
	while (defined(my $line = <STORE>)) {
		chomp($line);
		if ($line =~ qr"^package\t([^\t]+)\t([^\t]+$)$") {
			$pkgver = $pkglist->add($1, $2);
		} elsif ($line =~ qr"^var\t([^\t]+)\t(.*)$") {
			$pkgver->var($1, $2);
		} elsif ($line =~ qr"^sub ") {
			die "Outdated cache format in '$fname'\n";
		} else {
			die "Invalid line '$line' in cache '$fname'\n";
		}
	}
	close(STORE);
}

# Generate pkgname->category/pkg mapping, optionally check DEPENDS
#
sub scan_pkgsrc_makefiles($) {
	my ($pkgsrcdir) = @_;
	my (@categories);

	if ($pkglist) {

		# Already done
		return;
	}

	if ($opt{I}) {
		load_pkgsrc_makefiles($opt{I});
		return;
	}

	$pkglist = new PkgList;
	@categories = list_pkgsrc_categories($pkgsrcdir);
	verbose('Scan Makefiles: ');

	if (!$opt{L}) {
		verbose('_' x @categories . "\b" x @categories);
	} else {
		verbose("\n");
	}

	foreach my $cat (sort @categories) {
		foreach my $pkgdir (list_pkgsrc_pkgdirs($pkgsrcdir, $cat)) {
			my ($pkg, $vars) = parse_makefile_pkgsrc("$pkgsrcdir/$cat/$pkgdir/Makefile");
		}

		if (!$opt{L}) {
			verbose('.');
		}
	}

	if (!$opt{L}) {
		my ($len);

		$_ = $pkglist->numpkgver() . ' packages';
		$len = @categories - length($_);
		verbose("\b" x @categories, $_, ' ' x $len, "\b" x $len, "\n");
	}
}

# Cross reference all depends
#
sub pkgsrc_check_depends() {

	foreach my $pkgver ($pkglist->pkgver) {
		my ($err, $msg);

		defined $pkgver->var('DEPENDS') || next;
		foreach my $depend (split(" ", $pkgver->var('DEPENDS'))) {

			$depend =~ s/:.*// || next;

			$depend = canonicalize_pkgname($depend);
			if (($msg = invalid_version($depend))) {
				if (!defined($err)) {
					print $pkgver->pkgname . " DEPENDS errors:\n";
				}
				$err = 1;
				$msg =~ s/(\n)(.)/$1\t$2/g;
				print "\t$msg";
			}
		}
	}
}

# Extract all distinfo entries, then verify contents of distfiles
#
sub scan_pkgsrc_distfiles_vs_distinfo($$$$) {
	my ($pkgsrcdir, $pkgdistdir, $check_unref, $check_distinfo) = @_;
	my (@categories);
	my (%distfiles, %sumfiles, @distwarn, $numpkg);
	my (%bad_distfiles);

	@categories = list_pkgsrc_categories($pkgsrcdir);

	verbose('Scan distinfo: ' . '_' x @categories . "\b" x @categories);
	$numpkg = 0;
	foreach my $cat (sort @categories) {
		foreach my $pkgdir (list_pkgsrc_pkgdirs($pkgsrcdir, $cat)) {
			if (open(DISTINFO, "$pkgsrcdir/$cat/$pkgdir/distinfo")) {
				++$numpkg;
				while (<DISTINFO>) {
					if (m/^(\w+) ?\(([^\)]+)\) = (\S+)/) {
						my ($dn, $ds, $dt);
						$dt = $1;
						$dn = $2;
						$ds = $3;
						if ($dn =~ /^patch-[\w.+\-]+$/) {
							next;
						}

						# Strip leading ./ which sometimes gets added
						# because of DISTSUBDIR=.
						$dn =~ s/^(\.\/)*//;
						if (!defined $distfiles{$dn}) {
							$distfiles{$dn}{sumtype} = $dt;
							$distfiles{$dn}{sum} = $ds;
							$distfiles{$dn}{path} = "$cat/$pkgdir";

						} elsif ($distfiles{$dn}{sumtype} eq $dt && $distfiles{$dn}{sum} ne $ds) {
							push(@distwarn,
							    "checksum mismatch between '$dt' for '$dn' "
								. "in $cat/$pkgdir and $distfiles{$dn}{path}\n"
							);
						}
					}
				}
				close(DISTINFO);
			}
		}
		verbose('.');
	}
	verbose(" ($numpkg packages)\n");

	# check each file in $pkgdistdir
	find({ wanted => sub {
		my ($dist);
		if (-f $File::Find::name) {
			my $distn = $File::Find::name;
			$distn =~ s/$pkgdistdir\/?//g;
			#pkg/47516 ignore cvs dirs
			return if $distn =~ m/^\.cvsignore/;
			return if $distn =~ m/^CVS\//;
			if (!defined($dist = $distfiles{$distn})) {
				$bad_distfiles{$distn} = 1;
			} elsif ($dist->{sum} ne 'IGNORE') {
				push(@{$sumfiles{ $dist->{sumtype} }}, $distn);
			}
		}
	} },
	    ($pkgdistdir));

	if ($check_unref && %bad_distfiles) {
		verbose(scalar(keys %bad_distfiles),
		    " unreferenced file(s) in '$pkgdistdir':\n");
		print join("\n", sort keys %bad_distfiles), "\n";
	}

	if ($check_distinfo) {
		if (@distwarn) {
			verbose(@distwarn);
		}

		verbose("checksum mismatches\n");
		chdir_or_fail($pkgdistdir);
		foreach my $sum (keys %sumfiles) {
			if ($sum eq 'Size') {
				foreach my $file (@{$sumfiles{$sum}}) {
					if (!-f $file || -S $file != $distfiles{$file}{sum}) {
						print $file, " (Size)\n";
						$bad_distfiles{$file} = 1;
					}
				}
				next;
			}

			my $pid = open3(my $in, my $out, undef, "xargs", "digest", $sum);
			defined($pid) || fail "fork";
			my $pid2 = fork();
			defined($pid2) || fail "fork";
			if ($pid2) {
				close($in);
			} else {
				print $in "@{$sumfiles{$sum}}";
				exit 0;
			}
			while (<$out>) {
				if (m/^$sum ?\(([^\)]+)\) = (\S+)/) {
					if ($distfiles{$1}{sum} ne $2) {
						print $1, " ($sum)\n";
						$bad_distfiles{$1} = 1;
					}
				}
			}
			close($out);
			waitpid($pid, 0) || fail "xargs digest $sum";
			waitpid($pid2, 0) || fail "pipe write to xargs";
		}
		chdir_or_fail('/'); # Do not want to stay in $pkgdistdir
	}
	(sort keys %bad_distfiles);
}

sub store_pkgsrc_makefiles($) {
	my ($fname) = @_;

	open(STORE, ">", $fname)
	    or die("Cannot save pkgsrc store to $fname: $!\n");
	my $prev = select(STORE);
	$pkglist->store();
	select($prev);
	close(STORE)
	    or die("Cannot save pkgsrc store to $fname: $!\n");
}

# Remember to update manual page when modifying option list
#
sub usage_and_exit() {
	print "Usage: lintpkgsrc [opts] [makefiles]
opts:
  -h : This help.	 [see lintpkgsrc(1) for more information]

Installed package options:		Distfile options:
  -i : Check version against pkgsrc	  -m : List distinfo mismatches
  -u : As -i + fetch dist (may change)	  -o : List obsolete (no distinfo)
					  -y : Remove orphan distfiles
					  -z : Remove installed distfiles

Prebuilt package options:		Makefile options:
  -p : List old/obsolete		  -B : List packages marked as 'BROKEN'
  -O : List OSVERSION_SPECIFIC		  -d : Check 'DEPENDS' up to date
  -R : List NO_BIN_ON_FTP/RESTRICTED	  -S : List packages not in 'SUBDIRS'

Misc:
  -E file : Export the internal pkgsrc database to file
  -I file : Import the internal pkgsrc database to file (for use with -i)
  -g file : Generate 'pkgname pkgdir pkgver' map in file
  -r	  : Remove bad files (Without -m -o -p or -V implies all, can use -R)

Modifiers:
  -K path : Set PACKAGES basedir (default PKGSRCDIR/packages)
  -M path : Set DISTDIR		 (default PKGSRCDIR/distfiles)
  -P path : Set PKGSRCDIR	 (default $conf_pkgsrcdir)
  -D      : Debug makefile and glob parsing
  -L      : List each Makefile when scanned
";
	exit;
}

# Could speed up by building a cache of package names to paths, then processing
# each package name once against the tests.
sub check_prebuilt_packages() {

	if ($_ eq 'distfiles' || $_ eq 'pkgsrc') {
		# Skip these subdirs if present
		$File::Find::prune = 1;

	} elsif (/(.+)-(\d.*)\.t[bg]z$/) {
		my ($pkg, $ver) = ($1, $2);

		$pkg = canonicalize_pkgname($pkg);

		my ($pkgs);
		if ($pkgs = $pkglist->pkgs($pkg)) {
			my ($pkgver) = $pkgs->pkgver($ver);

			if (!defined $pkgver) {
				if ($opt{p}) {
					print "$File::Find::dir/$_\n";
					push(@matched_prebuiltpackages, "$File::Find::dir/$_");
				}

				# Pick probably the last version
				$pkgver = $pkgs->latestver;
			}

			if ($opt{R} && $pkgver->var('RESTRICTED')) {
				print "$File::Find::dir/$_\n";
				push(@matched_prebuiltpackages, "$File::Find::dir/$_");
			}

			if ($opt{O} && $pkgver->var('OSVERSION_SPECIFIC')) {
				print "$File::Find::dir/$_\n";
				push(@matched_prebuiltpackages, "$File::Find::dir/$_");
			}
		}

	} elsif (-d $_) {
		if ($prebuilt_pkgdir_cache{"$File::Find::dir/$_"}) {
			$File::Find::prune = 1;
			return;
		}

		$prebuilt_pkgdir_cache{"$File::Find::dir/$_"} = 1;
		if (-l $_) {
			my ($dest) = readlink($_);

			if (substr($dest, 0, 1) ne '/') {
				$dest = "$File::Find::dir/$dest";
			}
			if (!$prebuilt_pkgdir_cache{$dest}) {
				push(@prebuilt_pkgdirs, $dest);
			}
		}
	}
}

sub debug_parse_makefiles(@) {

	foreach my $file (@_) {
		-d $file and $file .= "/Makefile";
		-f $file or fail("No such file: $file");

		my ($pkgname, $vars) = parse_makefile_pkgsrc($file);
		$pkgname ||= 'uNDEFINEd';

		print "$file -> $pkgname\n";
		foreach my $varname (sort keys %$vars) {
			print "\t$varname = $vars->{$varname}\n";
		}

		#if ($opt{d}) {
		#	pkgsrc_check_depends();
		#}
	}
}

sub check_distfiles($$) {
	my ($pkgsrcdir, $pkgdistdir) = @_;

	my @baddist = scan_pkgsrc_distfiles_vs_distinfo(
	    $pkgsrcdir, $pkgdistdir, $opt{o}, $opt{m});

	return unless $opt{r};
	verbose("Unlinking 'bad' distfiles\n");
	foreach my $distfile (@baddist) {
		unlink("$pkgdistdir/$distfile");
	}
}

sub remove_distfiles($$) {
	my ($pkgsrcdir, $pkgdistdir) = @_;

	my @pkgs = list_installed_packages();
	scan_pkgsrc_makefiles($pkgsrcdir);

	# list the installed packages and the directory they live in
	my @installed;
	foreach my $pkgname (sort @pkgs) {
		if ($pkgname =~ /^([^*?[]+)-([\d*?[].*)/) {
			foreach my $pkgver ($pkglist->pkgver($1)) {
				next if $pkgver->var('dir') =~ /-current/;
				push(@installed, $pkgver);
				last;
			}
		}
	}

	# distfiles belonging to the currently installed packages
	my (%distfiles, @pkgdistfiles);
	foreach my $pkgver (sort @installed) {
		my $pkgpath = $pkgver->var('dir');
		next unless open(DISTINFO, "$pkgsrcdir/$pkgpath/distinfo");
		while (<DISTINFO>) {
			next unless m/^(\w+) ?\(([^\)]+)\) = (\S+)/;
			my $dn = $2;
			next if $dn =~ /^patch-[\w.+\-]+$/;
			# Strip leading ./ which sometimes gets added
			# because of DISTSUBDIR=.
			$dn =~ s/^(\.\/)*//;
			if (!defined $distfiles{$dn}) {
				$distfiles{$dn}{name} = $dn;
				push(@pkgdistfiles, $dn);
			}
		}
		close(DISTINFO);
	}

	# distfiles downloaded on the current system
	my @tmpdistfiles = listdir("$pkgdistdir", undef);
	my @dldistfiles = grep { $_ ne "pkg-vulnerabilities" } @tmpdistfiles;

	# sort the two arrays to make searching a bit faster
	@dldistfiles = sort { $a cmp $b } @dldistfiles;
	@pkgdistfiles = sort { $a cmp $b } @pkgdistfiles;

	if ($opt{y}) {
		# looking for files that are downloaded on the current system
		# but do not belong to any currently installed package i.e. orphaned
		my $found = 0;
		my @orphan;
		foreach my $dldf (@dldistfiles) {
			foreach my $pkgdf (@pkgdistfiles) {
				if ($dldf eq $pkgdf) {
					$found = 1;
				}
			}
			if ($found != 1) {
				push(@orphan, $dldf);
				print "Orphaned file: $dldf\n";
			}
			$found = 0;
		}

		if ($opt{r}) {
			chdir_or_fail("$pkgdistdir");
			verbose("Unlinking 'orphaned' distfiles\n");
			foreach my $distfile (@orphan) {
				unlink($distfile)
			}
		}
	}

	if ($opt{z}) {
		# looking for files that are downloaded on the current system
		# but belong to a currently installed package i.e. parented
		my $found = 0;
		my @parent;
		foreach my $pkgdf (@pkgdistfiles) {
			foreach my $dldf (@dldistfiles) {
				if ($pkgdf eq $dldf) {
					$found = 1;
				}
			}
			if ($found == 1) {
				push(@parent, $pkgdf);
				print "Parented file: $pkgdf\n";
			}
			$found = 0;
		}

		if ($opt{r}) {
			chdir_or_fail("$pkgdistdir");
			verbose("Unlinking 'parented' distfiles\n");
			foreach my $distfile (@parent) {
				unlink($distfile);
			}
		}
	}
}

sub list_broken_packages($) {
	my ($pkgsrcdir) = @_;

	scan_pkgsrc_makefiles($pkgsrcdir);
	foreach my $pkgver ($pkglist->pkgver) {
		my $broken = $pkgver->var('BROKEN');
		next unless $broken;
		print $pkgver->pkgname . ": $broken\n";
	}
}

# List obsolete or NO_BIN_ON_FTP/RESTRICTED prebuilt packages
#
sub list_prebuilt_packages($) {
	my ($pkgsrcdir) = @_;

	scan_pkgsrc_makefiles($pkgsrcdir);

	@prebuilt_pkgdirs = ($default_vars->{PACKAGES});
	%prebuilt_pkgdir_cache = ();

	while (@prebuilt_pkgdirs) {
		find(\&check_prebuilt_packages, shift @prebuilt_pkgdirs);
	}

	if ($opt{r}) {
		verbose("Unlinking listed prebuilt packages\n");
		foreach my $pkgfile (@matched_prebuiltpackages) {
			unlink($pkgfile);
		}
	}
}

sub list_packages_not_in_SUBDIR($) {
	my ($pkgsrcdir) = @_;

	my (%in_subdir);
	foreach my $cat (list_pkgsrc_categories($pkgsrcdir)) {
		my $vars = parse_makefile_vars("$pkgsrcdir/$cat/Makefile", undef);

		if (!$vars->{SUBDIR}) {
			print "Warning - no SUBDIR for $cat\n";
			next;
		}
		foreach my $pkgdir (split(/\s+/, $vars->{SUBDIR})) {
			$in_subdir{"$cat/$pkgdir"} = 1;
		}
	}

	scan_pkgsrc_makefiles($pkgsrcdir);
	foreach my $pkgver ($pkglist->pkgver) {
		my $pkgpath = $pkgver->var('dir');
		if (!defined $in_subdir{$pkgpath}) {
			print "$pkgpath: Not in SUBDIR\n";
		}
	}
}

sub generate_map_file($$) {
	my ($pkgsrcdir, $fname) = @_;

	my $tmpfile = "$fname.tmp.$$";

	scan_pkgsrc_makefiles($pkgsrcdir);
	open(TABLE, '>', $tmpfile) or fail("Cannot write '$tmpfile': $!");
	foreach my $pkgver ($pkglist->pkgver) {
		print TABLE $pkgver->pkg . "\t"
		    . $pkgver->var('dir') . "\t"
		    . $pkgver->ver . "\n";
	}
	close(TABLE) or fail("close('$tmpfile'): $!");
	rename($tmpfile, $fname)
	    or fail("rename('$tmpfile', '$fname'): $!");
}

sub check_outdated_installed_packages($) {
	my ($pkgsrcdir) = @_;

	my @pkgs = list_installed_packages();
	scan_pkgsrc_makefiles($pkgsrcdir);

	my @update;
	foreach my $pkgname (sort @pkgs) {
		next unless $_ = invalid_version($pkgname);

		print $_;
		next unless $pkgname =~ /^([^*?[]+)-([\d*?[].*)/;

		foreach my $pkgver ($pkglist->pkgver($1)) {
			next if $pkgver->var('dir') =~ /-current/;
			push(@update, $pkgver);
			last;
		}
	}

	return unless $opt{u};

	print "\nREQUIRED details for packages that could be updated:\n";

	foreach my $pkgver (@update) {
		print $pkgver->pkg . ':';
		if (open(PKGINFO, 'pkg_info -R ' . $pkgver->pkg . '|')) {
			my ($list);

			while (<PKGINFO>) {
				if (/Required by:/) {
					$list = 1;
				} elsif ($list) {
					chomp;
					s/-\d.*//;
					print " $_";
				}
			}
			close(PKGINFO);
		}
		print "\n";
	}

	print "\nRunning '$conf_make fetch-list | sh' for each package:\n";
	foreach my $pkgver (@update) {
		my $pkgpath = $pkgver->var('dir');
		defined($pkgpath)
		    or fail('Cannot determine ' . $pkgver->pkg . ' directory');

		print "$pkgsrcdir/$pkgpath\n";
		chdir_or_fail("$pkgsrcdir/$pkgpath");
		system("$conf_make fetch-list | sh");
	}
}

sub main() {

	$ENV{PATH} .=
	    ":/bin:/usr/bin:/sbin:/usr/sbin:$conf_prefix/sbin:$conf_prefix/bin";

	if (
	    !getopts('BDE:I:K:LM:OP:RSVdg:himopruyz', \%opt)
		|| $opt{h}
		|| !grep(/[BDEORSdgimopruyz]/, keys %opt)) {
		usage_and_exit();
	}
	$| = 1;

	get_default_makefile_vars(); # $default_vars

	if ($opt{D} && @ARGV) {
		debug_parse_makefiles(@ARGV);
		exit;
	}

	my $pkgsrcdir = $default_vars->{PKGSRCDIR};
	my $pkgdistdir = $default_vars->{DISTDIR};

	if ($opt{r} && !$opt{o} && !$opt{m} && !$opt{p}) {
		$opt{o} = $opt{m} = $opt{p} = 1;
	}
	if ($opt{o} || $opt{m}) {
		check_distfiles($pkgsrcdir, $pkgdistdir);
	}

	# Remove all distfiles that are / are not part of an installed package
	if ($opt{y} || $opt{z}) {
		remove_distfiles($pkgsrcdir, $pkgdistdir);
	}

	if ($opt{B}) {
		list_broken_packages($pkgsrcdir);
	}

	if ($opt{p} || $opt{O} || $opt{R}) {
		list_prebuilt_packages($pkgsrcdir);
	}

	if ($opt{S}) {
		list_packages_not_in_SUBDIR($pkgsrcdir);
	}

	if ($opt{g}) {
		generate_map_file($pkgsrcdir, $opt{g});
	}

	if ($opt{d}) {
		scan_pkgsrc_makefiles($pkgsrcdir);
		pkgsrc_check_depends();
	}

	if ($opt{i} || $opt{u}) {
		check_outdated_installed_packages($pkgsrcdir);
	}

	if ($opt{E}) {
		scan_pkgsrc_makefiles($pkgsrcdir);
		store_pkgsrc_makefiles($opt{E});
	}
}

if (caller()) {
	# To allow easy testing of the code.
	# TODO: reduce the use of global variables, or make them accessible
	#  to the tests.
	$default_vars = {};
}

main() unless caller();
