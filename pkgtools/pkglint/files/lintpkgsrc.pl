#!/usr/bin/env perl

# $NetBSD: lintpkgsrc.pl,v 1.15 2000/01/03 15:21:45 abs Exp $

# Written by David Brownlee <abs@netbsd.org>.
#
# Caveats:
#	The 'Makefile parsing' algorithym used to obtain package versions
#	and DEPENDS information is geared towards speed rather than perfection,
#	though it has got somewhat better over time, it only parses the
#	simplest Makefile conditionals. (a == b, no && etc).
#
#	The 'invalid distfiles' code picks up a couple of false positives in
#	fastcap (which does strange things anyway).

$^W = 1;
use strict;
use Getopt::Std;
use File::Find;
my(	$pkgsrcdir,		# Base of pkgsrc tree
	%pkgver2dir,		# Map package-version to category/pkgname
	%pkg2ver,		# Map pkgname to version
	%pkgrestricted,		# RESTRICTED packages, by pkgname
	%opt,			# Command line options
	@old_prebuiltpackages,	# List of obsolete prebuilt package paths
	@restricted_prebuiltpackages);	# Ditto, but for RESTRICTED packages

$ENV{PATH} .= ':/usr/sbin';

if (! &getopts('DK:P:Rdhilmopr', \%opt) || $opt{'h'} ||
	! ( defined($opt{'d'}) || defined($opt{'i'}) || defined($opt{'l'}) ||
	    defined($opt{'m'}) || defined($opt{'o'}) || defined($opt{'p'}) ||
	    defined($opt{'r'}) || defined($opt{'D'}) || defined($opt{'R'}) ))
    { &usage_and_exit; }
$| = 1;

if ($opt{'D'})
    {
    my ($file, $pkgname, %vars);
    foreach $file (@ARGV)
	{
	if ( -d $file)
	    { $file .= "/Makefile"; }
	($pkgname, %vars) = &parse_makefile($file);
	print "$file -> $pkgname\n";
	foreach ( sort keys %vars )
	    { print "\t$_ = $vars{$_}\n"; }
	}
    }

# main
    {
    my($pkglint_flags);

    $pkglint_flags = '-a -b -c -v';
    if ($opt{'P'})
	{ $pkgsrcdir = $opt{'P'}; } # Check /etc/mk.conf for PKGSRCDIR
    else
	{ $pkgsrcdir = &set_pkgsrcdir; } # Check /etc/mk.conf for PKGSRCDIR

    if ($opt{'r'} && !$opt{'o'} && !$opt{'m'} && !$opt{'p'})
	{ $opt{'o'} = $opt{'m'} = $opt{'p'} = 1; }
    if ($opt{'o'} || $opt{'m'})
	{
	my(@baddist);

	@baddist = &scan_pkgsrc_distfiles_vs_md5($pkgsrcdir, $opt{'o'},
								$opt{'m'});
	if ($opt{'r'})
	    {
	    &safe_chdir("$pkgsrcdir/distfiles");
	    &verbose("Unlinking 'bad' distfiles\n");
	    foreach (@baddist)
		{ unlink($_); }
	    }
	}

    # List obsolete or RESTRICTED prebuilt packages
    #
    if ($opt{'p'} || $opt{'R'})
	{
	my($binpkgdir);

	if (!%pkgver2dir)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	if ($opt{'K'})
	    { $binpkgdir = $opt{'K'}; }
	else
	    { $binpkgdir = "$pkgsrcdir/packages"; }
	find(\&check_prebuilt_packages, $binpkgdir);
	if ($opt{'r'})
	    {
	    &verbose("Unlinking 'old' prebuiltpackages\n");
	    foreach (@old_prebuiltpackages)
		{ unlink($_); }
	    }
	}

    if ($opt{'d'})
	{ &scan_pkgsrc_makefiles($pkgsrcdir, 1); }
    if ($opt{'i'})
	{
	my(@pkgs, $pkg);

	@pkgs = &list_installed_packages;
	if (!%pkgver2dir)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	foreach $pkg ( @pkgs )
	    {
	    if ( $_ = &invalid_version($pkg) )
		{ print $_; }
	    }
	}
    if ($opt{'l'})
	{ &pkglint_all_pkgsrc($pkgsrcdir, $pkglint_flags); }
    }
exit;

sub check_prebuilt_packages
    {
    if ($_ eq 'distfiles')
	{ $File::Find::prune = 1; }
    elsif (/(.*)\.tgz$/)
	{
	if (!defined($pkgver2dir{$1}))
	    {
	    if ($opt{'p'})
		{ print "$File::Find::dir/$_\n"; }
	    push(@old_prebuiltpackages, "$File::Find::dir/$_");
	    }
	elsif (defined($pkgrestricted{$1}))
	    {
	    if ($opt{'R'})
		{ print "$File::Find::dir/$_\n"; }
	    push(@restricted_prebuiltpackages, "$File::Find::dir/$_");
	    }
	}
    }

# Dewey decimal verson number matching - or thereabouts
#
sub dewey_cmp
    {
    my($match, $test, $val) = @_;
    my($cmp, @matchlist, @vallist);

    @matchlist = split(/\./, $match);
    @vallist = split(/\./, $val);
    $cmp = 0;
    while( ! $cmp && (@matchlist || @vallist))
	{
	if (!@matchlist)
	    { $cmp = -1; }
	elsif (!@vallist)
	    { $cmp = 1; }
	else
	    { $cmp = (shift @matchlist <=> shift @vallist) }
	}
    print "$cmp $test 0\n";
    eval "$cmp $test 0";
    }


sub fail
    { print STDERR @_, "\n"; exit(3); }

# Determine if a package version is current. If not, report correct version
# if found
#
sub invalid_version
    {
    my($pkgver) = @_;
    my($pkg, $badver, $fail);

    ($pkg, $badver) = package_globmatch($pkgver);

    if (defined($badver))
	{
	if (defined($pkg2ver{$pkg}))
	    { $fail = "Version mismatch: '$pkg' $badver vs $pkg2ver{$pkg}\n"; }
	else
	    { $fail = "Unknown package: '$pkg' version $badver\n"; }
	}
    $fail;
    }

# List (recursive) non directory contents of specified directory
#
sub listdir
    {
    my($base, $dir) = @_;
    my($thisdir, $entry);
    my(@list, @thislist);

    $thisdir = $base;
    if (defined($dir))
	{
	$thisdir .= "/$dir";
	$dir .= '/';
	}
    else
	{ $dir = ''; }
    opendir(DIR, $thisdir) || &fail("Unable to opendir($thisdir): $!");
    @thislist = grep(substr($_, 0, 1) ne '.' && $_ ne 'CVS', readdir(DIR));
    closedir(DIR);
    foreach $entry (@thislist)
	{
	if (-d "$thisdir/$entry")
	    { push(@list, &listdir($base, "$dir$entry")); }
	else
	    { push(@list, "$dir$entry"); }
	}
    @list;
    }

# Use pkg_info to list installed packages
#
sub list_installed_packages
    {
    my(@pkgs);

    open(PKG_INFO, 'pkg_info -a|') || &fail("Unable to run pkg_info: $!");
    while ( <PKG_INFO> )
	{ push(@pkgs, (split)[0]); }
    close(PKG_INFO);
    @pkgs;
    }

# List top level pkgsrc categories
#
sub list_pkgsrc_categories
    {
    my($pkgsrcdir) = @_;
    my(@categories);

    opendir(BASE, $pkgsrcdir) || die("Unable to opendir($pkgsrcdir): $!");
    @categories = grep(substr($_, 0, 1) ne '.' && -f "$pkgsrcdir/$_/Makefile",
							readdir(BASE));
    closedir(BASE);
    @categories;
    }

# Perform some (reasonable) subset of 'pkg_info -e' / glob(3)
# Returns (sometimes best guess at) package name,
# and either 'problem version' or undef if all OK
#
sub package_globmatch
    {
    my($pkgmatch) = @_;
    my($pkg, $ver, $matchver);

    if ( $pkgmatch =~ /^([^*?[]+)-([\d*?[].*)/ )
	{					 	# (package)-(globver)
	my($regexver, @chars, $in_alt);

	($pkg, $matchver) = ($1, $2);

	# Try to convert $globver into regex version $regexver
	if (defined($ver = $pkg2ver{$pkg}))
	    {
	    if ($ver eq $matchver)	# Exact match
		{ return($ver); }
	    @chars = split(//, $matchver);
	    $regexver = '^';
	    while ($_ = shift @chars)
		{
		if ($_ eq '*')
		    { $regexver .= '.*'; }
		elsif ($_ eq '?')
		    { $regexver .= '.'; }
		elsif ($_ eq '\\')
		    { $regexver .= $_ . shift @chars; }
		elsif ($_ eq '.' || $_ eq '|' )
		    { $regexver .= quotemeta; }
		elsif ($_ eq '{' )
		    { $regexver .= '('; $in_alt = 1; }
		elsif ($_ eq '}' )
		    { $regexver .= ')'; $in_alt = 0; }
		elsif ($_ eq ','  && $in_alt)
		    { $regexver .= '|'; }
		else
		    { $regexver .= $_; }
		}
	    $regexver .= '$';
	    if( $ver =~ /$regexver/ )
		{ $matchver = undef; }
	    }
	}
    elsif ( $pkgmatch =~ /^([^*?[]+)(<|>|<=|>=)([\d.]+)/ ) 
	{						# (package)(cmp)(dewey)
	my($test);

	($pkg, $test, $matchver) = ($1, $2);

	if (defined($ver = $pkg2ver{$pkg}))
	    {
	    if ( dewey_cmp($matchver, $test, $ver) )
		{ $matchver = undef; }
	    else
		{ $matchver = "$test$matchver"; }
	    }
	}
    else
	{ ($pkg, $matchver) = ($pkgmatch, 'missing'); }
    ($pkg, $matchver);
    }

# Extract variable assignments from Makefile, include pkgname.
# Much unpalatable magic to avoid having to use make (all for speed)
#
sub parse_makefile
    {
    my($file) = @_;
    my($pkgname, %vars);
    my($key, $plus, $value, @data, $if_nest, $if_false);

    if (! open(FILE, $file))
	{ return(undef); }
    @data = <FILE>;
    close(FILE);

    # Some Makefiles depend on these being set
    $vars{'EXTRACT_SUFX'} = 'tar.gz';
    $vars{'OBJECT_FMT'} = '';
    if ($file =~ m#(.*)/#)
	{ $vars{'.CURDIR'} = $1; }

    while( $_ = shift(@data) )
	{
	s/#.*//;

	# Continuation lines
	#
	while ( substr($_,-2) eq "\\\n" )
	    { substr($_,-2) = shift @data; }

	# Conditionals
	#
	if (m#^\.endif\b#)
	    {
	    --$if_nest;
	    if ($if_false)
		{ --$if_false; }
	    }
	elsif (m#^\.if\s+(.*)#)
	    {
	    ++$if_nest;
	    if ($if_false)
		{ ++$if_false; }
	    else
		{
		my($test);

		$test = parse_expand_vars($1, \%vars);
		# XX This is _so_ wrong - need to parse this correctly
		$test =~ s/"//g;

		if ( $test =~ /^defined\((\S+)\)$/ && !defined($vars{$1}) )
		    { ++$if_false; }
		elsif ( $test =~ /^(\S+)\s+==\s+(\S+)$/ && $1 ne $2 )
		    { ++$if_false; }
		}
	    }

	$if_false && next;

	# Included files (just unshift onto @data)
	#
	if (m#^\.include\s+"([^"]+)"#)
	    {
	    $_ = $1;
	    if (! m#/mk/#)
		{
		my($newfile) = ($_);

		# Expand any simple vars in $newfile
		#
		$newfile = parse_expand_vars($newfile, \%vars);

		# Handle relative path newfile
		#
		if (substr($newfile, 0, 1) ne '/')
		    { $newfile = "$vars{'.CURDIR'}/$newfile"; }

		if (!open(FILE, $newfile))
		    { &verbose("Cannot open '$newfile' (from $file): $!\n"); }
		else
		    {
		    unshift(@data, <FILE>);
		    close(FILE);
		    }
		}
	    next;
	    }

	if (/^\s*(\w+)([+?]?)=\s*(\S.*)/)
	    {
	    $key = $1;
	    $plus = $2;
	    $value = $3;
	    if ($plus eq '+' && defined($vars{$key}) )
		{ $vars{$key} .= " $value"; }
	    elsif ($plus ne '?' || !defined($vars{$key}) )
		{ $vars{$key} = $value; }
	    } 
	}

    # Handle simple variable substitutions FRED = a-${FRED}-b
    # Must be before next block to handle FRED = a-${JIM:S/-/-${SHELIA}-/}
    #
    my($loop);
    for ($loop = 1 ; $loop ;)
	{
	$loop = 0;
	foreach $key ( keys %vars )
	    {
	    while ( $vars{$key} =~ /\$\{([\w.]+)\}/ )
		{
		if (defined($vars{$1}))
		    { $vars{$key} = $`.$vars{$1}.$'; }
		else
		    { $vars{$key} = $`.'UNDEFINED'.$'; }
		$loop = 1;
		}
	    }
	}

    # Handle more complex variable substitutions FRED = a-${JIM:S/-/-b-/}
    #
    for ($loop = 1 ; $loop ;)
	{
	$loop = 0;
	foreach $key ( keys %vars )
	    {
	    if ( index($vars{$key}, '$') == -1 )
		{ next; }
	    foreach $value ( keys %vars )
		{
		if ($vars{$key} =~ m#\${(\w+):[CS]/([^/]+)/([^/]*)/(g?)}#)
		    {
		    my($var, $from, $to, $global) = ($1, $2, $3, $4);

		    if (defined($vars{$var}))
			{
			$from =~ s/\./\\./g;	# Change . etc to \\.
			$to =~ s/\\(\d)/\$$1/g; # Change \1 etc to $1
			$_ = $vars{$var};
			eval "s/$from/$to/$global";
			if ($vars{$key} =~
					s#\${$var:[CS]/[^/]+/[^/]*/$global}#$_#)
			    { $loop = 1; }
			}
		    }
		}
	    }
	}

    if (defined($vars{'PKGNAME'}))
	{ $pkgname = $vars{'PKGNAME'}; }
    elsif (defined($vars{'DISTNAME'}))
	{ $pkgname = $vars{'DISTNAME'}; }
    if (defined($pkgname))
	{
	if ( $pkgname =~ /\$/ )
	    { print "\rBogus: $pkgname (from $file)\n"; }
	if (defined($vars{'RESTRICTED'}))
	    { $pkgrestricted{$pkgname} = 1; }
	return($pkgname, %vars);
	}
    else
	{ return(undef); }
    }

sub parse_expand_vars
    {
    my($line, $vars) = @_;

    while ( $line =~ /\$\{([\w.]+)\}/ )
	{
	if (defined(${$vars}{$1}))
	    { $line = $`.${$vars}{$1}.$'; }
	else
	    { $line = $`.'UNDEFINED'.$'; }
	}
    $line;
    }

# Run pkglint on every pkgsrc entry
#
sub pkglint_all_pkgsrc
    {
    my($pkgsrcdir, $pkglint_flags) = @_;
    my($cat, $pkg, @categories, @output);

    @categories = &list_pkgsrc_categories($pkgsrcdir);
    foreach $cat ( sort @categories )
	{
	&safe_chdir("$pkgsrcdir/$cat");
	if (! opendir(CAT, '.'))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkg ( grep(substr($_, 0, 1) ne '.', readdir(CAT) ) )
	    {
	    if (-f "$pkg/Makefile")
		{
		if (!open(PKGLINT, "pkglint $pkglint_flags $pkg|"))
		    { &fail("Unable to run pkglint: $!"); }
		@output = grep(!/^OK:/ &&
			     !/^WARN: be sure to cleanup .* work before/ &&
			     !/^WARN: is it a new port/ &&
			     !/^\d+ fatal errors and \d+ warnings found/
			     , <PKGLINT> );
		close(PKGLINT);
		if (@output)
		    {
		    print "===> $cat/$pkg\n",
			  "pkglint $pkglint_flags $pkg\n",
			  @output, "\n";
		    }
		}
	    }
	close(CAT);
	}
    }

# chdir() || &fail()
#
sub safe_chdir
    {
    my($dir) = @_;

    if (! chdir($dir))
	{ &fail("Unable to chdir($dir): $!"); }
    }

# Generate pkgname->category/pkg mapping, optionally check DEPENDS
#
sub scan_pkgsrc_makefiles
    {
    my($pkgsrcdir, $check_depends) = @_;
    my($cat, @categories, $pkg, $pkgname);
    my(%depends);

    @categories = &list_pkgsrc_categories($pkgsrcdir);
    &verbose("Scanning pkgsrc Makefiles: ".'_'x@categories."\b"x@categories);

    # @categories = qw( cross mail );
    # @categories = qw( archivers audio benchmarks biology cad comms converters
    # corba databases devel graphics lang mail ); # XXX
    # corba cross databases devel graphics lang mail ); # XXX

    foreach $cat ( sort @categories )
	{
	if (! opendir(CAT, "$pkgsrcdir/$cat"))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkg ( grep(substr($_, 0, 1) ne '.', readdir(CAT) ) )
	    {
	    my(%vars);
	    ($pkgname, %vars) =
			    &parse_makefile("$pkgsrcdir/$cat/$pkg/Makefile");
	    if ($pkgname)
		{
		if ($pkgname !~ /(.*)-(\d.*)/)
		    { print "Cannot extract $pkgname version ($cat/$pkg)\n"; }
		else
		    { $pkg2ver{$1} = $2; }
		$pkgver2dir{$pkgname} = "$cat/$pkg";
		if (defined($vars{'DEPENDS'}))
		    { $depends{$pkgname} = $vars{'DEPENDS'}; }
		}
	    }
	close(CAT);
	&verbose('.');
	}

    my ($len);
    $_ = scalar(keys %pkgver2dir).' packages';
    $len = @categories - length($_);
    &verbose("\b"x@categories, $_, ' 'x$len, "\b"x$len, "\n");

    if ($check_depends)
	{
	foreach $pkg ( sort keys %depends )
	    {
	    my($err, $msg);
	    foreach (split("\n", $depends{$pkg}))
		{
		s/:.*// || next;
		if (($msg = &invalid_version($_)) )
		    {
		    if (!defined($err))
			{ print "$pkgver2dir{$pkg} DEPENDS errors:\n"; }
		    $err = 1;
		    print "\t$msg";
		    }
		}
	    }
	}
    %pkgver2dir;
    }

# Extract all md5 entries, then verify contents of distfiles
#
sub scan_pkgsrc_distfiles_vs_md5
    {
    my($pkgsrcdir, $check_unref, $check_md5) = @_;
    my($cat, @categories, $pkg);
    my(%distfiles, %md5, @distwarn, $file, $numpkg);
    my(@distfiles, @bad_distfiles);

    @categories = &list_pkgsrc_categories($pkgsrcdir);

    &verbose("Scanning pkgsrc md5s: ".'_'x@categories."\b"x@categories);
    $numpkg = 0;
    foreach $cat ( sort @categories )
	{
	if (! opendir(CAT, "$pkgsrcdir/$cat"))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkg ( grep(substr($_, 0, 1) ne '.', readdir(CAT) ) )
	    {
	    if (open(MD5, "$pkgsrcdir/$cat/$pkg/files/md5"))
		{
		++$numpkg;
		while( <MD5> )
		    {
		    if (m/^MD5 \(([^\)]+)\) = (\S+)/)
			{
			if (!defined($distfiles{$1}))
			    {
			    $distfiles{$1} = "$cat/$pkg";
			    $md5{$1} = $2;
			    }
			elsif( $md5{$1} ne $2 )
			    {
			    push(@distwarn, "md5 mismatch between '$1' in ".
			    "$cat/$pkg and $distfiles{$1}\n");
			    }
			}
		    }
		close(MD5);
		}
	    }
	close(CAT);
	&verbose('.');
	}
    &verbose(" ($numpkg packages)\n");

    foreach $file (&listdir("$pkgsrcdir/distfiles"))
	{
	if (!defined($distfiles{$file}))
	    { push(@bad_distfiles, $file); }
	else
	    { push(@distfiles, $file); }
	}
    if ($check_unref && @bad_distfiles)
	{
	&verbose(scalar(@bad_distfiles),
			" unreferenced file(s) in '$pkgsrcdir/distfiles':\n");
	print join("\n", sort @bad_distfiles), "\n";
	}
    if ($check_md5)
	{
	if (@distwarn)
	    { &verbose(@distwarn); }
	&verbose("md5 mismatches\n");
	@distfiles = sort @distfiles;
	&safe_chdir("$pkgsrcdir/distfiles");
	open(MD5, "md5 @distfiles|") || &fail("Unable to run md5: $!");
	while (<MD5>)
	    {
	    if (m/^MD5 \(([^\)]+)\) = (\S+)/)
		{
		if ($md5{$1} ne 'IGNORE' && $md5{$1} ne $2)
		    {
		    print $1, "\n";
		    push(@bad_distfiles, $1);
		    }
		}
	    }
	close(MD5);
	}
    @bad_distfiles;
    }

sub set_pkgsrcdir # Parse /etc/mk.conf (if present) for PKGSRCDIR
    {
    my($pkgsrcdir);

    $pkgsrcdir = '/usr/pkgsrc';
    if (open(MK_CONF, '/etc/mk.conf'))
	{
	while (<MK_CONF>)
	    {
	    if( /PKGSRCDIR\s*=\s*(\S+)/ )
		{ $pkgsrcdir = $1; last; }
	    }
	close(MK_CONF);
	}
    $pkgsrcdir;
    }

sub usage_and_exit
    {
    print "Usage: lintpkgsrc [opts]
opts:
  -h	     : This help.
  -d	     : Check 'DEPENDS' are up to date.
  -i	     : Check installed package versions against pkgsrc.
  -l	     : Pkglint every package in pkgsrc.
  -R	     : List any RESTRICTED prebuilt packages.
  -m	     : List md5 mismatches for files in distfiles/.
  -o	     : List old/obsolete distfiles (not referenced by any md5).
  -p	     : List old/obsolete prebuilt packages.
  -r	     : Remove any 'bad' distfiles (Without -m, -o, or -p, implies all).

  -P path    : Set PKGSRCDIR
  -K path    : Set basedir for prebuild packages (default PKGSRCDIR/packages)
  -D [paths] : Parse Makefiles and output contents (For debugging)

If pkgsrc is not in /usr/pkgsrc, set PKGSRCDIR in /etc/mk.conf
";
    exit;
    }

sub verbose
    { print STDERR @_; }
