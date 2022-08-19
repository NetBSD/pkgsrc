#!@PERL5@
# $NetBSD: lintpkgsrc.pl,v 1.126 2022/08/19 05:06:26 rillig Exp $

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

use v5.36;
use locale;
use strict;
use warnings;
use Cwd 'realpath', 'getcwd';
use File::Basename;
use File::Find;
use Getopt::Std;
use IPC::Open3;

# PkgVer is a PKGBASE + PKGVERSION, including some of the variables that
# have been extracted from the package Makefile.
package PkgVer;

sub new($class, $pkgbase, $pkgversion) {
	my $self = {
	    pkgbase    => $pkgbase,
	    pkgversion => $pkgversion,
	    vars       => {},
	};
	bless $self, $class;
	return $self;
}

sub pkgbase($self) {
	$self->{pkgbase};
}

sub pkgversion($self) {
	$self->{pkgversion};
}

sub pkgname($self) {
	$self->pkgbase . '-' . $self->pkgversion;
}

sub var($self, $name, $value = undef) {
	defined $value
	    ? ($self->{vars}->{$name} = $value)
	    : $self->{vars}->{$name};
}

sub vars($self) {
	keys $self->{vars}->%*;
}

# All versions of a given PKGBASE, e.g. apache-1.3.27 and apache-2.0.46.
# Multi-prefix packages like py39-* are stored as simply py-*.
package Pkgs;

sub new($class, $pkgbase) {
	my $self = {
	    pkgbase => $pkgbase,
	    pkgvers => {},
	};
	bless $self, $class;
	return $self;
}

sub pkgbase($self) {
	$self->{pkgbase};
}

# All available versions of the package, in decreasing alphabetical(!) order.
sub versions($self) {
	reverse sort keys $self->{pkgvers}->%*;
}

sub add($self, $pkgbase, $pkgversion) {
	$self->{pkgvers}->{$pkgversion} = PkgVer->new($pkgbase, $pkgversion);
}

# All PkgVers of this pkgbase, in decreasing alphabetical(!) version order.
sub pkgvers_all($self) {
	my $pkgvers = $self->{pkgvers};
	sort { $b->pkgversion cmp $a->pkgversion } values %$pkgvers;
}

sub pkgver($self, $pkgversion) {
	$self->{pkgvers}->{$pkgversion};
}

# PkgData is a small database of all packages in pkgsrc.
package PkgData;

sub new($class) {
	my $self = {}; # pkgbase => Pkgs
	bless $self, $class;
	return $self;
}

sub add($self, $pkgbase, $pkgversion) {
	my $pkgs = ($self->{$pkgbase} ||= Pkgs->new($pkgbase));
	$pkgs->add($pkgbase, $pkgversion);
}

# All PkgVers, sorted by pkgbase, then by version in decreasing
# alphabetical(!) order.
sub pkgvers_all($self) {
	map { $_->pkgvers_all } $self->pkgs;
}

# All PkgVers of the given pkgbase, sorted by version in decreasing
# alphabetical(!) order.
sub pkgvers_by_pkgbase($self, $pkgbase) {
	my $pkgs = $self->{$pkgbase};
	defined $pkgs ? $pkgs->pkgvers_all : ();
}

sub pkgver($self, $pkgbase, $pkgversion) {
	my $pkgs = $self->{$pkgbase};
	defined $pkgs ? $pkgs->pkgver($pkgversion) : undef;
}

# pkgs() returns all Pkgs, sorted by pkgbase.
#
# pkgs($pkgbase) returns the Pkgs, or undef.
sub pkgs($self, $pkgbase = undef) {
	defined $pkgbase
	    ? $self->{$pkgbase}
	    : sort { $a->pkgbase cmp $b->pkgbase } values %$self;
}

sub load($class, $fname) {
	open(STORE, '<', $fname)
	    or die("Cannot read package data from $fname: $!\n");
	my $pkgver;
	my $self = $class->new();
	while (defined(my $line = <STORE>)) {
		chomp($line);
		if ($line =~ m"^ package \t ([^\t]+) \t ([^\t]+) $"x) {
			$pkgver = $self->add($1, $2);
		} elsif ($line =~ m"^ var \t ([^\t]+) \t (.*) $"x) {
			$pkgver->var($1, $2);
		} elsif ($line =~ m"^ sub ") {
			die "Outdated cache format in '$fname'\n";
		} else {
			die "Invalid line '$line' in cache '$fname'\n";
		}
	}
	close(STORE) or die;
	$self;
}

sub store($self, $fname) {
	open(STORE, '>', $fname)
	    or die("Cannot save package data to $fname: $!\n");
	foreach my $pkgver ($self->pkgvers_all) {
		my $pkgbase = $pkgver->pkgbase;
		my $pkgversion = $pkgver->pkgversion;

		$pkgbase =~ /^\S+$/
		    or die "cannot store package name '$pkgbase'\n";
		$pkgversion =~ /^\S+$/
		    or die "cannot store package version '$pkgversion'\n";
		print STORE "package\t$pkgbase\t$pkgversion\n";

		foreach my $varname (sort $pkgver->vars) {
			my $value = $pkgver->var($varname);
			$varname =~ /^\S+$/
			    or die "cannot store variable name '$varname'\n";
			$value =~ /^.*$/
			    or die "cannot store variable value '$value'\n";
			print STORE "var\t$varname\t$value\n";
		}
	}
	close(STORE) or die("Cannot save package data to $fname: $!\n");
}

package main;

# Buildtime configuration
my $conf_make = '@MAKE@';
my $conf_makeconf = '@MAKECONF@';
my $conf_pkg_info = '@PKG_INFO@';
my $conf_pkgsrcdir = '@PKGSRCDIR@';
my $conf_prefix = '@PREFIX@';
my $conf_x11base = '@X11BASE@';

my (
    $pkgdata,                  # Database of pkgsrc packages
    $default_vars,             # Set for Makefiles, inc PACKAGES & PKGSRCDIR
    %opt,                      # Command line options
    @matched_prebuiltpackages, # List of obsolete prebuilt package paths
    @prebuilt_pkgdirs,         # Use to follow symlinks in prebuilt pkgdirs
    %prebuilt_pkgdir_cache,    # To avoid symlink loops in prebuilt_pkgdirs
);

# Horrible kludge to ensure we have a value for testing in conditionals, but
# gets removed in the final evaluation
my $magic_undefined = 'M_a_G_i_C_uNdEfInEd';

sub debug(@args) {
	$opt{D} and print STDERR 'DEBUG: ', @args, "\n";
}

sub verbose(@args) {
	-t STDERR and print STDERR @args;
}

sub fail($msg) {
	print STDERR $msg, "\n";
	exit(3);
}

# List (recursive) non directory contents of specified directory
#
#TODO this entire sub should be replaced with direct calls to
#     File::Find
sub listdir($base, $dir = undef) {
	my (@list, @thislist);

	my $thisdir = $base;
	if (defined $dir) {
		$thisdir .= "/$dir";
		$dir .= '/';
	} else {
		$dir = '';
	}

	opendir(DIR, $thisdir) or fail("Unable to opendir($thisdir): $!");
	@thislist = grep { substr($_, 0, 1) ne '.' && $_ ne 'CVS' } readdir(DIR);
	closedir(DIR);

	foreach my $entry (@thislist) {
		if (-d "$thisdir/$entry") {
			push @list, listdir($base, "$dir$entry");
		} else {
			push @list, "$dir$entry";
		}
	}

	@list;
}

sub canonicalize_pkgname($pkgname) {
	$pkgname =~ s,^ap\d+-,ap-,;
	$pkgname =~ s,^lua\d+-,lua-,;
	$pkgname =~ s,^py\d+(?:pth|)-,py-,;
	$pkgname =~ s,^ruby\d+-,ruby-,;
	$pkgname =~ s,^php\d+-,php-,;
	return $pkgname;
}

sub split_pkgversion($pkgversion) {
	$pkgversion = lc($pkgversion);

	# See pkgtools/pkg_install/files/lib/dewey.c.
	my @temp = ($pkgversion =~ s/nb(\d+)//) ? +$1 : 0;
	foreach my $elem (split(/(pl|pre|rc|beta|alpha|\D)/, $pkgversion)) {
		if ($elem =~ /\d/) {
			push @temp, +$elem;
		} elsif ($elem eq 'pl' || $elem eq '.' || $elem eq '_') {
			push @temp, 0;
		} elsif ($elem eq 'pre' || $elem eq 'rc') {
			push @temp, -1;
		} elsif ($elem eq 'beta') {
			push @temp, -2;
		} elsif ($elem eq 'alpha') {
			push @temp, -3;
		} elsif ('a' le $elem && $elem le 'z') {
			push @temp, 0, ord($elem) - ord('a') + 1;
		}
	}
	@temp;
}

sub pkgversion_cmp($va, $op, $vb) {
	my ($nb_a, @a) = split_pkgversion($va);
	my ($nb_b, @b) = split_pkgversion($vb);

	my $cmp = 0;
	while ($cmp == 0 && (@a || @b)) {
		$cmp = (shift @a || 0) <=> (shift @b || 0);
	}
	$cmp ||= $nb_a <=> $nb_b;

	$op eq '<' ? $cmp < 0
	    : $op eq '<=' ? $cmp <= 0
	    : $op eq '>' ? $cmp > 0
	    : $cmp >= 0;
}

sub expand_braces($str) {
	my @todo = ($str);

	my @expanded;
	while (defined($str = shift @todo)) {
		if ($str =~ /(.*) \{ ([^{}]+) } (.*)/x) {
			foreach my $alt (split(',', $2, -1)) {
				push @todo, "$1$alt$3";
			}
		} else {
			push @expanded, $str;
		}
	}
	@expanded;
}

# Return a copy of $value in which trivial variable expressions are replaced
# with their variable values.
sub expand_exprs($value, $vars) {
	while ($value =~ /\$\{([-\w.]+)\}/) {
		$value = defined $vars->{$1}
		    ? "$`$vars->{$1}$'"
		    : "$`$magic_undefined$'";
	}
	$value;
}

sub eval_mk_cond_func($func, $arg, $vars) {
	if ($func eq 'defined') {
		my $varname = expand_exprs($arg, $vars);
		defined $vars->{$varname} ? 1 : 0;

	} elsif ($func eq 'empty') {

		# Implement (some of) make's :M modifier
		if ($arg =~ /^ ([^:]+) :M ([^:]+) $/x) {
			my ($varname, $pattern) = ($1, $2);
			$varname = expand_exprs($varname, $vars);
			$pattern = expand_exprs($pattern, $vars);

			my $value = $vars->{$varname};
			return 1 unless defined $value;

			$value = expand_exprs($value, $vars);

			$pattern =~ s/([{.+])/\\$1/g;
			$pattern =~ s/\*/.*/g;
			$pattern =~ s/\?/./g;
			$pattern = '^' . $pattern . '$';

			# XXX: Splitting by whitespace is not correct, but
			#  it's good enough for lists with only unquoted
			#  words. See devel/bmake/files/str.c:brk_string.
			foreach my $word (split(/\s+/, $value)) {
				return 0 if $word =~ /$pattern/;
			}
			return 1;
		} elsif ($arg =~ /:M/) {
			debug("Unsupported ':M' modifier in '$arg'");
		}

		my $value = expand_exprs("\${$arg}", $vars);
		defined $value && $value =~ /\S/ ? 0 : 1;

	} elsif ($func eq 'exists') {
		my $fname = expand_exprs($arg, $vars);
		-e $fname ? 1 : 0;

	} elsif ($func eq 'make') {
		0;

	} else { # $func eq 'target'
		0;
	}
}

sub eval_mk_cond($line, $vars) {
	my $cond = expand_exprs($line, $vars);

	# XXX This is _so_ wrong - need to parse this correctly
	$cond =~ s/""/\r/g;
	$cond =~ s/"//g;
	$cond =~ s/\r/""/g;

	debug("conditional: $cond");

	while ($cond =~ /(target|empty|make|defined|exists)\s*\(([^()]+)\)/) {
		my ($func, $arg) = ($1, $2);
		my $result = eval_mk_cond_func($func, $arg, $vars);
		$cond =~ s/$func\s*\([^()]+\)/$result/;
		debug("conditional: update to $cond");
	}

	while ($cond =~ /([^\s()\|\&]+) \s+ (!=|==) \s+ ([^\s()]+)/x) {
		my $result = 0 + (($2 eq '==') ? ($1 eq $3) : ($1 ne $3));
		$cond =~ s/[^\s()\|\&]+ \s+ (!=|==) \s+ [^\s()]+/$result/x;
	}

	if ($cond =~ /^[ <> \d () \s & | . ! ]+$/xx) {
		my $result = eval "($cond) ? 1 : 0";
		defined $result or fail("Eval '$cond' failed in '$line': $@");
		debug("conditional: evaluated to " . ($result ? 'true' : 'false'));
		$result;

	} else {
		debug("conditional: defaulting '$cond' to true");
		1;
	}
}

sub parse_makefile_line_include($file, $incfile,
				$incdirs, $included, $lines, $vars) {

	# At this point just skip any includes which we were
	# not able to fully expand.
	if ($incfile =~ m#/mk/bsd#
	    || $incfile =~ /$magic_undefined/
	    || $incfile =~ /\$\{/
	    || (!$opt{d} && $incfile =~ m#/(buildlink[^/]*\.mk)#)) {
		debug("$file: .include \"$incfile\" skipped");
		return;
	}

	debug("$file: .include \"$incfile\"");

	if (substr($incfile, 0, 1) ne '/') {
		foreach my $dir (reverse @$incdirs) {
			if (-f "$dir/$incfile") {
				$incfile = "$dir/$incfile";
				last;
			}
		}
	}

	# perl 5.6.1 realpath() cannot handle files, only directories.
	# If the last component is a symlink, this will give a false
	# negative, but that is not a problem, as the duplicate check
	# is for performance.
	$incfile =~ m#^(.+)(/[^/]+)$#;

	if (!-f $incfile) {
		$opt{L} or verbose("\n");

		my $dirs = join(' ', @$incdirs);
		verbose("$file: Cannot locate $incfile in $dirs\n");
		return;
	}

	$incfile = realpath($1) . $2;
	return if $included->{$incfile};

	$opt{L} and print "inc $incfile\n";
	$included->{$incfile} = 1;

	if (!open(FILE, $incfile)) {
		verbose("Cannot open '$incfile' (from $file): $_ $!\n");
		return;
	}
	chomp(my @inc_lines = <FILE>);
	close(FILE);

	my $new_curdir = dirname $incfile;
	push @$incdirs, $new_curdir
	    unless grep { $_ eq $new_curdir } @$incdirs;

	# FIXME: .CURDIR doesn't change, but .PARSEDIR does.
	unshift @$lines,
	    ".CURDIR=$new_curdir",
	    @inc_lines,
	    ".CURDIR=" . $vars->{'.CURDIR'};
}

sub parse_makefile_line_var($varname, $op, $value, $vars) {
	if ($op eq ':=') {
		$vars->{$varname} = expand_exprs($value, $vars);
	} elsif ($op eq '+=' && defined $vars->{$varname}) {
		$vars->{$varname} .= " $value";
	} elsif ($op eq '?=' && defined $vars->{$varname}) {
		# Do nothing.
	} else {
		$vars->{$varname} = $value;
	}
	debug($op eq '='
	    ? "assignment: $varname $op $value"
	    : "assignment: $varname $op $value => $vars->{$varname}");

	# Give python a little hand (XXX - do we wanna consider actually
	# implementing make .for loops, etc?
	#
	if ($varname eq 'PYTHON_VERSIONS_ACCEPTED') {
		foreach my $pv (split(/\s+/, $vars->{PYTHON_VERSIONS_ACCEPTED})) {
			$vars->{'_PYTHON_VERSION_FIRSTACCEPTED'} ||= $pv;
			$vars->{"_PYTHON_VERSION_${pv}_OK"} = 'yes';
		}
	}
}

sub expand_modifiers($file, $varname, $left, $subvar, $mods, $right, $vars) {
	my @mods = split(':', $mods);
	my $result = $vars->{$subvar};
	$result = '' unless defined $result;

	# If the value of $subvar contains a '$', skip it on this pass.
	# Hopefully it will get substituted and we can catch it
	# next time around.
	return 0 if index($result, '${') != -1;

	debug("$file: substitutelist $varname ($result) $subvar (@mods)");
	foreach (@mods) {
		debug("expanding modifier '$_'");

		if (m#^ (U) (.*) #x) {
			$result = $2 unless defined $vars->{$subvar};

		} elsif (m#^ ([CS]) (.) ([^/\@]+) \2 ([^/\@]*) \2 ([1g]*) #x) {
			# TODO: Use non-greedy repetitions above.
			# TODO: Properly handle separators other than '/' and '@'.
			my ($how, $from, $to, $global) = ($1, $3, $4, $5);

			debug("$file: ':S' $subvar, $how, $from, $to, $global");
			if ($how eq 'S') {
				# Limited substitution - keep ^ and $
				$from =~ s/([?.{}\]\[*+])/\\$1/g;
			}
			$to =~ s/\\(\d)/\$$1/g; # Change \1 etc to $1
			$to =~ s/\&/\$&/g;

			my $notfirst;
			if ($global =~ s/1//) {
				# FIXME: The modifier '1' applies to the first
				#  occurrence in any word, it doesn't have to
				#  be in the first word.
				($from, $notfirst) = split('\s', $from, 2);
			}

			debug("$file: substituteperl $subvar, $how, $from, $to");
			debug("eval substitute <$from> <$to> <$global>");
			eval "\$result =~ s/$from/$to/$global";
			if (defined $notfirst) {
				$result .= " $notfirst";
			}

		} else {
			debug("$file: variable '$varname' has unknown modifier '$_'");
		}
	}

	$result = '' if !defined $result;
	$vars->{$varname} = "$left$result$right";
	return 1;
}

# Extract variable assignments from Makefile
# Much unpalatable magic to avoid having to use make (all for speed)
#
sub parse_makefile_vars($file, $cwd = undef) {
	my %vars;
	my %incfiles; # Cache of previously included files
	my @incdirs;  # Directories in which to check for includes
	my @lines;

	open(FILE, $file) or return undef;
	chomp(@lines = <FILE>);
	close(FILE) or die;

	push @incdirs, '.';
	push @incdirs, dirname($file);

	# Some Makefiles depend on these being set
	if ($file eq $conf_makeconf) {
		$vars{LINTPKGSRC} = 'YES';
	} else {
		%vars = %$default_vars;
	}
	$vars{BSD_PKG_MK} = 'YES';

	my $curdir = $cwd || ($file =~ m#(.*)/# ? $1 : getcwd);
	$vars{'.CURDIR'} = $curdir;
	push @incdirs, $curdir;
	if ($opt{L}) {
		print "$file\n";
	}

	my @if_state; # 'not_yet', 'active', 'done'
	while (defined($_ = shift @lines)) {
		s/(*negative_lookbehind:\\)#.*//;
		s/\s+$//;

		# Join continuation lines.
		# See devel/bmake/files/parse.c, 'replace following'.
		while (substr($_, -1) eq "\\" && @lines > 0) {
			my $cont = shift @lines;
			$cont =~ s,^\s*, ,;
			$cont =~ s/(*negative_lookbehind:\\)#.*//;
			$cont =~ s/\s+$//;
			substr($_, -1) = $cont;
		}

		# Conditionals
		#
		if (m#^ \. \s* (if|ifdef|ifndef) \s+ (.*) #x) {
			my ($kind, $cond) = ($1, $2);

			if (@if_state > 0 && $if_state[-1] ne 'active') {
				push @if_state, 'done';

			} elsif ($kind eq 'if') {
				my $result = eval_mk_cond($cond, \%vars);
				push @if_state, $result ? 'active' : 'not_yet';

			} else {
				my $varname = expand_exprs($cond, \%vars);

				# bmake also allows '.ifdef A && B'.
				debug("not implemented: .ifdef $varname")
				    if $cond =~ /\s/;

				my $result = $kind eq 'ifdef'
				    ? defined($vars{$varname})
				    : !defined($vars{$varname});
				push @if_state, $result ? 'active' : 'not_yet';
			}

			debug("$file: .$kind @if_state");

		} elsif ( # XXX: bmake also knows '.elifdef' and '.elifnmake'.
		    m#^ \. \s* elif \s+ (.*)#x && @if_state > 0) {
			my ($cond) = ($1);

			if ($if_state[-1] eq 'active') {
				$if_state[-1] = 'done';
			} elsif ($if_state[-1] eq 'not_yet'
			    && eval_mk_cond($cond, \%vars)) {
				$if_state[-1] = 'active';
			}
			debug("$file: .elif @if_state");

		} elsif (m#^ \. \s* else \b #x && @if_state > 0) {
			$if_state[-1] =
			    $if_state[-1] eq 'not_yet' ? 'active' : 'done';
			debug("$file: .else @if_state");

		} elsif (m#^\. \s* endif \b #x) {
			pop @if_state;
			debug("$file: .endif @if_state");

		} elsif (@if_state > 0 && $if_state[-1] ne 'active') {
			# Skip branches whose condition evaluated to false.

		} elsif (m#^\. \s* include \s+ "([^"]+)" #x) {
			my $incfile = expand_exprs($1, \%vars);

			parse_makefile_line_include($file, $incfile,
			    \@incdirs, \%incfiles, \@lines, \%vars);

		} elsif (m#^[ ]* ([-\w\.]+) \s* ([:+?]?=) \s* (.*)#x) {
			parse_makefile_line_var($1, $2, $3, \%vars);

		} elsif ($_ eq '' || m#^\s*\## || m#^\t#) {
			# Skip comment lines and shell commands.

		} else {
			debug("$file: unknown line '$_'");
		}
	}

	if ($opt{D}) {
		print "Before expansion:\n";
		foreach my $varname (sort keys %vars) {
			print "\t$varname = $vars{$varname}\n";
		}
	}
	debug("$file: expand");

	# Handle variable substitutions  FRED = a-${JIM:S/-/-b-/}

	for (my $loop = 1; $loop != 0;) {
		$loop = 0;
		foreach my $varname (keys %vars) {
			next if index($vars{$varname}, '$') == -1;

			$_ = expand_exprs($vars{$varname}, \%vars);
			if ($_ ne $vars{$varname}) {
				$vars{$varname} = $_;
				$loop = 1;

			} elsif ($vars{$varname} =~ m#\$\{([\w.]+):([CS]([^{}])[^{}\3]+\3[^{}\3]*\3[g1]*(|:[^{}]+)|U[^{}]+)\}#) {
				$loop ||= expand_modifiers($file, $varname, $`, $1, $2, $', \%vars);
			}
		}
	}

	foreach my $varname (keys %vars) {
		# XXX: Removing only the first magic string is strange; either
		#  all of them or none of them should be removed.
		$vars{$varname} =~ s/$magic_undefined//;
	}

	\%vars;
}

sub get_default_makefile_vars() {

	chomp($_ = `uname -srm`);
	(
	    $default_vars->{OPSYS},
	    $default_vars->{OS_VERSION},
	    $default_vars->{MACHINE}
	) = split;
	$default_vars->{MACHINE}
	    or die('Unable to extract machine from uname');

	# Handle systems without uname -p  (NetBSD pre 1.4)
	chomp($default_vars->{MACHINE_ARCH} = `uname -p 2>/dev/null`);

	if (!$default_vars->{MACHINE_ARCH}
	    && $default_vars->{OS_VERSION} eq 'NetBSD') {
		chomp($default_vars->{MACHINE_ARCH} = `sysctl -n hw.machine_arch`);
	}

	$default_vars->{MACHINE_ARCH} ||= $default_vars->{MACHINE};

	$default_vars->{OBJECT_FMT} = 'x';
	$default_vars->{LOWER_OPSYS} = lc($default_vars->{OPSYS});

	$default_vars->{PKGSRCDIR} = $opt{P}
	    ? realpath($opt{P})
	    : $conf_pkgsrcdir;

	$default_vars->{DESTDIR} = '';
	$default_vars->{LOCALBASE} = $conf_prefix;
	$default_vars->{X11BASE} = $conf_x11base;

	if (-f $conf_makeconf &&
	    (my $vars = parse_makefile_vars($conf_makeconf, undef))) {
		foreach my $var (keys %$vars) {
			$default_vars->{$var} = $vars->{$var};
		}
	}

	# XXX: repeated from above?
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
	my $mkvars = parse_makefile_vars(
	    "$default_vars->{PKGSRCDIR}/mk/bsd.pkg.mk",
	    "$default_vars->{PKGSRCDIR}/mk/scripts"
	);
	foreach my $varname (keys %$mkvars) {
		if ($varname =~ /_REQD$/ || $varname eq 'EXTRACT_SUFX') {
			$default_vars->{$varname} = $mkvars->{$varname};
		}
	}

	$default_vars->{PACKAGES} ||= $default_vars->{PKGSRCDIR} . '/packages';

	$default_vars->{PKG_APACHE} = 'apache12345';
	$default_vars->{'_APACHE_PKG_PREFIX.apache12345'} = 'ap12345';
	$default_vars->{LUA_PKGPREFIX} = 'lua12345';
	$default_vars->{PHP_PKG_PREFIX} = 'php12345';
	$default_vars->{PYPKGPREFIX} = 'py12345';
	$default_vars->{RUBY_PKGPREFIX} = 'ruby12345';
}

# Determine if a package version is current. If not, report the correct
# version if found.
sub invalid_version($pkgmatch) {

	my @warnings;
	foreach $pkgmatch (expand_braces($pkgmatch)) {
		my ($pkg, $badver) = package_globmatch($pkgmatch);
		# If we find one match, it's good enough.
		return () unless defined $badver;

		my $pkgs = $pkgdata->pkgs($pkg);
		push @warnings, $pkgs
		    ? "Version mismatch: '$pkg' $badver vs "
		    . join(',', $pkgs->versions)
		    : "Unknown package: '$pkg' version $badver";
	}
	@warnings;
}

sub list_installed_packages() {
	open(PKG_INFO, "$conf_pkg_info -e '*' |") or die;
	chomp(my @pkgs = <PKG_INFO>);
	close(PKG_INFO) or die;
	map { $_ = canonicalize_pkgname($_) } @pkgs;
}

sub list_pkgsrc_categories($pkgsrcdir) {
	my @categories;

	opendir(BASE, $pkgsrcdir) or die("Unable to opendir($pkgsrcdir): $!");
	@categories = grep { !/^\./ && -f "$pkgsrcdir/$_/Makefile" }
	    readdir(BASE);
	closedir(BASE);
	@categories;
}

# For a given category, list potentially valid pkgdirs
sub list_pkgsrc_pkgdirs($pkgsrcdir, $cat) {
	opendir(CAT, "$pkgsrcdir/$cat")
	    or die("Unable to opendir($pkgsrcdir/$cat): $!");
	my @pkgdirs = sort grep {
		$_ ne 'Makefile'
		    && $_ ne 'pkg'
		    && $_ ne 'CVS'
		    && substr($_, 0, 1) ne '.'
	} readdir(CAT);
	closedir(CAT) or die;
	@pkgdirs;
}

# Convert the glob pattern to a regular expression.
# Return '' if the regular expression equals the glob expression.
# Return undef on error.
sub glob2regex($glob) {
	my @chars = split(//, $glob);
	my $alternative_depth = 0;
	my $regex = '';
	while (defined($_ = shift @chars)) {
		if ($_ eq '*') {
			$regex .= '.*';
		} elsif ($_ eq '?') {
			$regex .= '.';
		} elsif ($_ eq '+') {
			$regex .= '\\+';
		} elsif ($_ eq '\\' && @chars > 0) {
			my $next = shift @chars;
			$regex .= $next =~ /\w/ ? $next : "\\$next";
		} elsif ($_ eq '.' || $_ eq '|') {
			$regex .= "\\$_";
		} elsif ($_ eq '{') {
			$regex .= '(';
			++$alternative_depth;
		} elsif ($_ eq '}') {
			return undef if $alternative_depth == 0;
			$regex .= ')';
			--$alternative_depth;
		} elsif ($_ eq ',' && $alternative_depth > 0) {
			$regex .= '|';
		} elsif ($_ eq '[') {
			$regex .= '[';
			while (defined($_ = shift @chars)) {
				$regex .= $_;
				if ($_ eq ']') {
					last;
				} elsif ($_ eq '\\' && @chars > 0) {
					$regex .= shift @chars;
				}
			}
			return undef if $_ ne ']';
		} else {
			$regex .= $_;
		}
	}

	return undef if $alternative_depth > 0;
	return '' if $regex eq $glob; # XXX: why?

	$opt{D} and print "glob2regex: $glob -> $regex\n";
	'^' . $regex . '$';
}

# Perform some (reasonable) subset of 'pkg_info -e' / glob(3)
# Returns (sometimes best guess at) package name,
# and either 'problem version' or undef if all OK
#
sub package_globmatch($pkgmatch) {

	if ($pkgmatch =~ /^ ([^*?[]+) (<|>|<=|>=|-) (\d[^*?[{]*) $/x) {
		my ($match_base, $op, $match_ver) = ($1, $2, $3);

		my @pkgvers = $pkgdata->pkgvers_by_pkgbase($match_base);
		foreach my $pkgver (@pkgvers) {
			if ($op eq '-'
			    ? $pkgver->pkgversion eq $match_ver
			    : pkgversion_cmp($pkgver->pkgversion, $op, $match_ver)) {
				return ($match_base, undef);
			}
		}

		if (@pkgvers && $match_ver && $op ne '-') {
			$match_ver = "$op$match_ver";
		}
		($match_base, $match_ver);

	} elsif ($pkgmatch =~ /^ ([^[]+) - ([\d*?{[].*) $/x) {
		my ($matchpkgname, $matchver) = ($1, $2);

		my @pkgnames;
		if (defined $pkgdata->pkgs($matchpkgname)) {
			push @pkgnames, $matchpkgname;

		} elsif (my $regex = glob2regex($matchpkgname)) {
			foreach my $pkg ($pkgdata->pkgs) {
				if ($pkg->pkgbase =~ /$regex/) {
					push @pkgnames, $pkg->pkgbase;
				}
			}
		}

		# Try to convert $matchver into regex version
		#
		my $regex = glob2regex($matchver);

		foreach my $pkg (@pkgnames) {
			if (defined $pkgdata->pkgver($pkg, $matchver)) {
				return ($matchver);
			}

			if ($regex) {
				foreach my $ver ($pkgdata->pkgs($pkg)->versions) {
					if ($ver =~ /$regex/) {
						$matchver = undef;
						last;
					}
				}
			}

			$matchver or last;
		}

		# last ditch attempt to handle the whole DEPENDS as a glob
		#
		if ($matchver && ($regex = glob2regex($pkgmatch))) {

			# (large-glob)
			foreach my $pkgver ($pkgdata->pkgvers_all) {
				if ($pkgver->pkgname =~ /$regex/) {
					$matchver = undef;
					last;
				}
			}
		}

		($matchpkgname, $matchver);

	} else {
		($pkgmatch, 'missing');
	}
}

# Parse a pkgsrc package makefile and return the pkgname and set variables
#
sub parse_makefile_pkgsrc($file) {
	my $vars = parse_makefile_vars($file, undef);
	defined $vars or return undef; # Missing Makefile.

	my $pkgname = $vars->{PKGNAME};
	my $distname = $vars->{DISTNAME};

	debug("$file: PKGNAME=$pkgname") if defined $pkgname;
	debug("$file: DISTNAME=$distname") if defined $distname;

	$pkgname = $distname unless defined $pkgname;

	if (!defined $pkgname || $pkgname =~ /\$/ || $pkgname !~ /(.*)-(\d.*)/) {

		# invoke make here as a last resort
		my $pkgdir = dirname $file;
		debug("Running '$conf_make' in '$pkgdir'");
		my $pid = open3(\*WTR, \*RDR, \*ERR,
		    "cd $pkgdir || exit 1; $conf_make show-vars VARNAMES=PKGNAME");
		if (!$pid) {
			warn "$file: Unable to run make: $!";
		} else {
			close(WTR) or die;
			my @errors = <ERR>;
			close(ERR) or die;
			my $makepkgname = <RDR>;
			close(RDR) or die;
			wait;
			chomp @errors;
			if (@errors) { warn "\n$file: @errors\n"; }

			if ($makepkgname =~ /(.*)-(\d.*)/) {
				$pkgname = $makepkgname;
			}
		}
	}

	defined $pkgname or return ();

	$pkgname = canonicalize_pkgname($pkgname);

	my $pkgrevision = $vars->{PKGREVISION};
	if (defined $pkgrevision && $pkgrevision !~ /^\s*$/) {
		if ($pkgrevision =~ /^\$\{ (?:
		    _CVS_PKGVERSION |
		    _GIT_PKGVERSION |
		    _HG_PKGVERSION_CMD |
		    _SVN_PKGREVISION_CMD) :.* \}$ /x) {
			# See wip/mk/*-package.mk.
		} elsif ($pkgrevision =~ /\D/) {
			print "\n";
			print "Bogus: PKGREVISION $pkgrevision (from $file)\n";

		} elsif ($pkgrevision > 0) {
			$pkgname .= "nb$pkgrevision";
		}
	}

	if ($pkgname =~ /\$/) {
		print "\nBogus: $pkgname (from $file)\n";

	} elsif ($pkgname =~ /(.*)-(\d.*)/) {
		if (defined $pkgdata) {
			my $pkgver = $pkgdata->add($1, $2);

			debug("add $1 $2");

			foreach my $var (qw(DEPENDS RESTRICTED OSVERSION_SPECIFIC BROKEN)) {
				$pkgver->var($var, $vars->{$var});
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

	($pkgname, $vars);
}

sub chdir_or_fail($dir) {
	my $prev_dir = getcwd() or die;
	debug("chdir: $dir");
	chdir($dir) or fail("Cannot chdir($dir): $!\n");
	return $prev_dir;
}

# Generate pkgname->category/pkg mapping, optionally check DEPENDS
#
sub scan_pkgsrc_makefiles($pkgsrcdir) {

	return if defined $pkgdata; # Already done.

	if ($opt{I}) {
		$pkgdata = PkgData->load($opt{I});
		return;
	}

	$pkgdata = PkgData->new();
	my @categories = list_pkgsrc_categories($pkgsrcdir);

	if ($opt{L}) {
		verbose("Scan Makefiles:\n");
	} else {
		verbose('Scan Makefiles: ', '_' x @categories, "\b" x @categories);
	}

	foreach my $cat (sort @categories) {
		foreach my $pkgdir (list_pkgsrc_pkgdirs($pkgsrcdir, $cat)) {
			my ($pkg, $vars) = parse_makefile_pkgsrc("$pkgsrcdir/$cat/$pkgdir/Makefile");
		}

		verbose('.') unless $opt{L};
	}

	if (!$opt{L}) {
		my $summary = scalar $pkgdata->pkgvers_all . ' packages';
		my $len = @categories - length($summary);
		verbose("\b" x @categories, $summary, ' ' x $len, "\b" x $len, "\n");
	}
}

# Cross reference all depends
#
sub pkgsrc_check_depends() {
	foreach my $pkgver ($pkgdata->pkgvers_all) {
		my $depends = $pkgver->var('DEPENDS');
		next unless defined $depends;

		my $seen_header = 0;
		foreach my $depend (split(' ', $depends)) {
			next unless $depend =~ s/:.*//;

			$depend = canonicalize_pkgname($depend);
			next unless my @msgs = invalid_version($depend);

			if ($seen_header == 0) {
				print $pkgver->pkgname . " DEPENDS errors:\n";
				$seen_header = 1;
			}
			print map { "\t$_\n" } @msgs;
		}
	}
}

sub load_distinfo($dir) {
	my $fname = "$dir/distinfo";
	open(my $f, '<', $fname) or return;
	chomp(my @lines = <$f>);
	close($f) or die;

	my @entries;
	foreach my $line (@lines) {
		next if $line eq '' || $line =~ m#^\$NetBSD#;

		if ($line =~ m/^ (\w+) \s \( ([^)]+) \) \s=\s (\S+)/x) {
			push @entries, {
			    algorithm => $1,
			    distfile  => $2,
			    hash      => $3,
			};
		} else {
			warn "Invalid line in $fname: $line\n";
		}
	}

	@entries;
}

sub check_distinfo_hash($entry, $pkgpath, $distfiles, $warnings) {
	my $algorithm = $entry->{algorithm};
	my $distfile = $entry->{distfile};
	my $hash = $entry->{hash};

	return if $distfile =~ /^patch-[\w.+\-]+$/;

	# Only store and check the first algorithm listed in distinfo.
	my $other_entry = $distfiles->{$distfile};
	if (!defined $other_entry) {
		$distfiles->{$distfile} = {
		    algorithm => $algorithm,
		    hash      => $hash,
		    pkgpath   => $pkgpath,
		};

	} elsif ($other_entry->{algorithm} eq $algorithm
	    && $other_entry->{hash} ne $hash) {
		my $other_pkgpath = $other_entry->{pkgpath};
		my $warning = "checksum mismatch for '$algorithm' "
		    . "of '$distfile' between '$pkgpath' and '$other_pkgpath'\n";
		push @$warnings, $warning;
	}
}

# Verify that the contents of the distfiles directory matches the distinfo
# files in the packages.
sub check_pkgsrc_distfiles_vs_distinfo($pkgsrcdir, $pkgdistdir, $check_unref,
				       $check_distinfo) {
	my @categories;
	my (%distfiles, %sumfiles, @distwarn, $numpkg);
	my %unref_distfiles;

	@categories = list_pkgsrc_categories($pkgsrcdir);

	verbose('Scan distinfo: ' . '_' x @categories . "\b" x @categories);
	$numpkg = 0;
	foreach my $cat (sort @categories) {
		foreach my $pkgdir (list_pkgsrc_pkgdirs($pkgsrcdir, $cat)) {
			++$numpkg;
			my $pkgpath = "$cat/$pkgdir";
			foreach my $entry (load_distinfo("$pkgsrcdir/$pkgpath")) {
				check_distinfo_hash($entry, $pkgpath,
				    \%distfiles, \@distwarn);
			}
		}
		verbose('.');
	}
	verbose(" ($numpkg packages)\n");

	# check each file in $pkgdistdir
	find({ wanted => sub {
		if (-f $File::Find::name) {
			my $distn = $File::Find::name;
			$distn =~ s/$pkgdistdir\/?//g;
			#pkg/47516 ignore cvs dirs
			return if $distn =~ m/^\.cvsignore/;
			return if $distn =~ m/^CVS\//;
			if (!defined(my $dist = $distfiles{$distn})) {
				$unref_distfiles{$distn} = 1;
			} else {
				push @{$sumfiles{$dist->{algorithm}}}, $distn;
			}
		}
	} },
	    ($pkgdistdir));

	if ($check_unref && %unref_distfiles) {
		verbose(scalar(keys %unref_distfiles),
		    " unreferenced file(s) in '$pkgdistdir':\n");
		print join("\n", sort keys %unref_distfiles), "\n";
	}

	if ($check_distinfo) {
		verbose(@distwarn) if @distwarn;

		verbose("checksum mismatches\n");
		my $prev_dir = chdir_or_fail($pkgdistdir);
		foreach my $sum (keys %sumfiles) {
			if ($sum eq 'Size') {
				foreach my $file (@{$sumfiles{$sum}}) {
					if (!-f $file || -S $file != $distfiles{$file}{hash}) {
						print $file, " (Size)\n";
						$unref_distfiles{$file} = 1;
					}
				}
				next;
			}

			my $pid = open3(my $in, my $out, undef, 'xargs', 'digest', $sum);
			defined $pid or fail 'fork';
			my $pid2 = fork();
			defined $pid2 or fail 'fork';
			if ($pid2) {
				close($in) or die;
			} else {
				print $in "@{$sumfiles{$sum}}";
				exit 0;
			}
			while (<$out>) {
				if (m/^$sum ?\(([^\)]+)\) = (\S+)/) {
					if ($distfiles{$1}{hash} ne $2) {
						print $1, " ($sum)\n";
						$unref_distfiles{$1} = 1;
					}
				}
			}
			close($out) or die;
			waitpid($pid, 0) or fail "xargs digest $sum";
			waitpid($pid2, 0) or fail 'pipe write to xargs';
		}
		chdir_or_fail($prev_dir);
	}

	sort keys %unref_distfiles;
}

# Remember to update manual page when modifying option list
#
sub usage_and_exit($status) {
	print "Usage: lintpkgsrc [options] [makefiles]
options:
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
	exit $status;
}

# Could speed up by building a cache of package names to paths, then processing
# each package name once against the tests.
sub check_prebuilt_packages() {

	if ($_ eq 'distfiles' || $_ eq 'pkgsrc') {
		# Skip these subdirs if present
		$File::Find::prune = 1;

	} elsif (/^ (.+) - (\d.*) \.t[bg]z $/x) {
		my ($pkg, $ver) = ($1, $2);

		$pkg = canonicalize_pkgname($pkg);

		if (my $pkgs = $pkgdata->pkgs($pkg)) {
			my $pkgver = $pkgs->pkgver($ver);

			if (!defined $pkgver) {
				if ($opt{p}) {
					print "$File::Find::dir/$_\n";
					push @matched_prebuiltpackages, "$File::Find::dir/$_";
				}

				# Pick probably the last version
				$pkgver = ($pkgs->pkgvers_all)[0];
			}

			if ($opt{R} && $pkgver->var('RESTRICTED')) {
				print "$File::Find::dir/$_\n";
				push @matched_prebuiltpackages, "$File::Find::dir/$_";
			}

			if ($opt{O} && $pkgver->var('OSVERSION_SPECIFIC')) {
				print "$File::Find::dir/$_\n";
				push @matched_prebuiltpackages, "$File::Find::dir/$_";
			}
		}

	} elsif (-d $_) {
		if ($prebuilt_pkgdir_cache{"$File::Find::dir/$_"}) {
			$File::Find::prune = 1;
			return;
		}

		$prebuilt_pkgdir_cache{"$File::Find::dir/$_"} = 1;
		if (-l $_) {
			my $dest = readlink($_);

			if (substr($dest, 0, 1) ne '/') {
				$dest = "$File::Find::dir/$dest";
			}
			if (!$prebuilt_pkgdir_cache{$dest}) {
				push @prebuilt_pkgdirs, $dest;
			}
		}
	}
}

sub debug_parse_makefiles(@args) {
	foreach my $file (@args) {
		-d $file and $file .= '/Makefile';
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

sub check_distfiles($pkgsrcdir, $pkgdistdir) {
	my @unref_distfiles = check_pkgsrc_distfiles_vs_distinfo(
	    $pkgsrcdir, $pkgdistdir, $opt{o}, $opt{m});

	return unless $opt{r};
	verbose("Unlinking unreferenced distfiles\n");
	foreach my $distfile (@unref_distfiles) {
		unlink("$pkgdistdir/$distfile");
	}
}

# looking for files that are downloaded on the current system
# but do not belong to any currently installed package i.e. orphaned
sub remove_orphaned_distfiles($dldistfiles, $pkgdistfiles, $pkgdistdir) {
	my $found = 0;
	my @orphan;
	foreach my $dldf (@$dldistfiles) {
		foreach my $pkgdf (@$pkgdistfiles) {
			if ($dldf eq $pkgdf) {
				$found = 1;
			}
		}
		if ($found != 1) {
			push @orphan, $dldf;
			print "Orphaned file: $dldf\n";
		}
		$found = 0;
	}

	if ($opt{r}) {
		verbose("Unlinking 'orphaned' distfiles\n");
		foreach my $distfile (@orphan) {
			unlink("$pkgdistdir/$distfile")
		}
	}
}

# looking for files that are downloaded on the current system
# but belong to a currently installed package i.e. parented
sub remove_parented_distfiles($dldistfiles, $pkgdistfiles, $pkgdistdir) {
	my $found = 0;
	my @parent;
	foreach my $pkgdf (sort @$pkgdistfiles) {
		foreach my $dldf (@$dldistfiles) {
			if ($pkgdf eq $dldf) {
				$found = 1;
			}
		}
		if ($found == 1) {
			push @parent, $pkgdf;
			print "Parented file: $pkgdf\n";
		}
		$found = 0;
	}

	if ($opt{r}) {
		verbose("Unlinking 'parented' distfiles\n");
		foreach my $distfile (@parent) {
			unlink("$pkgdistdir/$distfile");
		}
	}
}

sub remove_distfiles($pkgsrcdir, $pkgdistdir) {
	my @installed_pkgnames = list_installed_packages();
	scan_pkgsrc_makefiles($pkgsrcdir);

	# list the installed packages and the directory they live in
	my @installed_pkgvers;
	foreach my $pkgname (sort @installed_pkgnames) {
		if ($pkgname !~ /^ ([^*?[]+) - ([\d*?[].*) /x) {
			warn "Invalid installed package name: $pkgname";
			next;
		}

		foreach my $pkgver ($pkgdata->pkgvers_by_pkgbase($1)) {
			next if $pkgver->var('dir') =~ /-current/;
			push @installed_pkgvers, $pkgver;
			last;
		}
	}

	# distfiles belonging to the currently installed packages
	my (%distfiles, @pkgdistfiles);
	foreach my $pkgver (sort @installed_pkgvers) {
		my $pkgpath = $pkgver->var('dir');
		foreach my $entry (load_distinfo("$pkgsrcdir/$pkgpath")) {
			my $distfile = $entry->{distfile};
			next if $distfile =~ /^patch-[\w.+\-]+$/;
			next if defined $distfiles{$distfile};
			$distfiles{$distfile}->{name} = $distfile;
			push @pkgdistfiles, $distfile;
		}
	}

	# distfiles downloaded on the current system
	my @dldistfiles = sort grep { $_ ne 'pkg-vulnerabilities' }
	    listdir("$pkgdistdir", undef);

	$opt{y} and remove_orphaned_distfiles(
	    \@dldistfiles, \@pkgdistfiles, $pkgdistdir);

	$opt{z} and remove_parented_distfiles(
	    \@dldistfiles, \@pkgdistfiles, $pkgdistdir);
}

sub list_broken_packages($pkgsrcdir) {
	scan_pkgsrc_makefiles($pkgsrcdir);
	foreach my $pkgver ($pkgdata->pkgvers_all) {
		my $broken = $pkgver->var('BROKEN');
		next unless $broken;
		print $pkgver->pkgname . ": $broken\n";
	}
}

# List obsolete or NO_BIN_ON_FTP/RESTRICTED prebuilt packages
#
sub list_prebuilt_packages($pkgsrcdir) {
	scan_pkgsrc_makefiles($pkgsrcdir);

	@prebuilt_pkgdirs = ($default_vars->{PACKAGES});
	%prebuilt_pkgdir_cache = ();

	while (@prebuilt_pkgdirs) {
		find(\&check_prebuilt_packages, shift @prebuilt_pkgdirs);
	}

	return unless $opt{r};
	verbose("Unlinking listed prebuilt packages\n");
	foreach my $pkgfile (@matched_prebuiltpackages) {
		unlink($pkgfile);
	}
}

sub list_packages_not_in_SUBDIR($pkgsrcdir) {
	my %in_subdir;
	foreach my $cat (list_pkgsrc_categories($pkgsrcdir)) {
		my $makefile = "$pkgsrcdir/$cat/Makefile";
		my $vars = parse_makefile_vars($makefile, undef);
		my $subdirs = $vars->{SUBDIR};
		defined $subdirs or die "No SUBDIR in $makefile";

		foreach my $pkgdir (split(/\s+/, $subdirs)) {
			$in_subdir{"$cat/$pkgdir"} = 1;
		}
	}

	scan_pkgsrc_makefiles($pkgsrcdir);
	foreach my $pkgver ($pkgdata->pkgvers_all) {
		my $pkgpath = $pkgver->var('dir');
		if (!defined $in_subdir{$pkgpath}) {
			print "$pkgpath: Not in SUBDIR\n";
		}
	}
}

sub generate_map_file($pkgsrcdir, $fname) {
	my $tmpfile = "$fname.tmp.$$";

	scan_pkgsrc_makefiles($pkgsrcdir);
	open(TABLE, '>', $tmpfile) or fail("Cannot write '$tmpfile': $!");
	foreach my $pkgver ($pkgdata->pkgvers_all) {
		printf TABLE "%s\t%s\t%s\n",
		    $pkgver->pkgbase,
		    $pkgver->var('dir'),
		    $pkgver->pkgversion;
	}
	close(TABLE) or fail("close('$tmpfile'): $!");
	rename($tmpfile, $fname)
	    or fail("rename('$tmpfile', '$fname'): $!");
}

sub check_outdated_installed_packages($pkgsrcdir) {
	my @pkgs = list_installed_packages();
	scan_pkgsrc_makefiles($pkgsrcdir);

	my @update;
	foreach my $pkgname (sort @pkgs) {
		next unless my @warnings = invalid_version($pkgname);

		print map { "$_\n" } @warnings;
		next unless $pkgname =~ /^([^*?[]+)-([\d*?[].*)/;

		foreach my $pkgver ($pkgdata->pkgvers_by_pkgbase($1)) {
			next if $pkgver->var('dir') =~ /-current/;
			push @update, $pkgver;
			last;
		}
	}

	return unless $opt{u};

	print "\nREQUIRED details for packages that could be updated:\n";

	foreach my $pkgver (@update) {
		my $pkgbase = $pkgver->pkgbase;
		print "$pkgbase:";
		open(PKGINFO, "$conf_pkg_info -q -R $pkgbase |") or die;
		while (<PKGINFO>) {
			print " $1" if /^(.*?)-\d/;
		}
		close(PKGINFO) or die;
		print "\n";
	}

	print "\nRunning '$conf_make fetch-list | sh' for each package:\n";
	foreach my $pkgver (@update) {
		my $pkgpath = $pkgver->var('dir');
		defined $pkgpath
		    or fail('Cannot determine ' . $pkgver->pkgbase . ' directory');

		print "$pkgsrcdir/$pkgpath\n";
		my $prev_dir = chdir_or_fail("$pkgsrcdir/$pkgpath");
		system("$conf_make fetch-list | sh");
		chdir_or_fail($prev_dir);
	}
}

sub main() {

	$ENV{PATH} .=
	    ":/bin:/usr/bin:/sbin:/usr/sbin:$conf_prefix/sbin:$conf_prefix/bin";

	if (
	    !getopts('-BDE:I:K:LM:OP:RSVdg:himopruyz', \%opt)
		|| $opt{h}
		|| !grep(/[BDEORSdgimopruyz]/, keys %opt)) {
		usage_and_exit($opt{h} ? 0 : 1);
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
		$pkgdata->store($opt{E});
	}
}

sub export_for_test() {
	({
	    'opt'          => \%opt,
	    'default_vars' => $default_vars,
	    'pkgdata'      => $pkgdata,
	});
}

if (caller()) {
	# To allow easy testing of the code.
	# TODO: reduce the use of global variables, or make them accessible
	#  to the tests.
	$default_vars = {};
}

main() unless caller();
