#!/usr/bin/env perl

# $NetBSD: lintpkgsrc.pl,v 1.25 2000/05/29 19:44:28 dmcmahill Exp $

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
	$pkgdistdir,		# Distfiles directory
	%pkgver2dir,		# Map package-version to category/pkgname
	%pkg2ver,		# Map pkgname to version
	%pkgrestricted,		# RESTRICTED/LICENCE packages, by pkgname
	%default_makefile_vars,	# Default vars set for Makefiles
	%opt,			# Command line options
	@old_prebuiltpackages,	# List of obsolete prebuilt package paths
	@prebuilt_pkgdirs,	# Use to follow symlinks in prebuilt pkgdirs
	@restricted_prebuiltpackages);	# " but for RESTRICTED/LICENCE packages

$ENV{PATH} .= ':/usr/sbin';

if (! &getopts('DK:LM:P:Rdhilmopru', \%opt) || $opt{'h'} ||
	! ( defined($opt{'d'}) || defined($opt{'i'}) || defined($opt{'l'}) ||
	    defined($opt{'m'}) || defined($opt{'o'}) || defined($opt{'p'}) ||
	    defined($opt{'r'}) || defined($opt{'u'}) || defined($opt{'D'}) ||
	    defined($opt{'R'}) ))
    { &usage_and_exit; }
$| = 1;

%default_makefile_vars = &get_default_makefile_vars;

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

    if ($opt{'M'})
	{ $pkgdistdir = $opt{'M'}; } # override distfile dir
    else
	{ $pkgdistdir = "$pkgsrcdir/distfiles"; } # default


    if ($opt{'r'} && !$opt{'o'} && !$opt{'m'} && !$opt{'p'})
	{ $opt{'o'} = $opt{'m'} = $opt{'p'} = 1; }
    if ($opt{'o'} || $opt{'m'})
	{
	my(@baddist);

	@baddist = &scan_pkgsrc_distfiles_vs_md5($pkgsrcdir, $opt{'o'},
								$opt{'m'});
	if ($opt{'r'})
	    {
	    &safe_chdir("$pkgdistdir");
	    &verbose("Unlinking 'bad' distfiles\n");
	    foreach (@baddist)
		{ unlink($_); }
	    }
	}

    # List obsolete or RESTRICTED/LICENCE prebuilt packages
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
	@prebuilt_pkgdirs = ($binpkgdir);
	while (@prebuilt_pkgdirs)
	    { find(\&check_prebuilt_packages, shift @prebuilt_pkgdirs); }
	if ($opt{'r'})
	    {
	    &verbose("Unlinking 'old' prebuiltpackages\n");
	    foreach (@old_prebuiltpackages)
		{ unlink($_); }
	    }
	}

    if ($opt{'d'})
	{ &scan_pkgsrc_makefiles($pkgsrcdir, 1); }
    if ($opt{'i'} || $opt{'u'})
	{
	my(@pkgs, @bad, $pkg);

	@pkgs = &list_installed_packages;
	if (!%pkgver2dir)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	foreach $pkg ( @pkgs )
	    {
	    if ( $_ = &invalid_version($pkg) )
		{
		push(@bad, $pkg);
		print $_;
		}
	    }
	if ($opt{'u'})
	    {
	    foreach $pkg (@bad)
		{
		my($pkgdir);

		if ( $pkg =~ /^([^*?[]+)-([\d*?[].*)/ ) 
		    { $pkgdir = $pkgver2dir{"$1-$pkg2ver{$1}"}; }

		if (!defined($pkgdir))
		    { &fail("Unable to determine directory for '$pkg'"); }
		print "$pkgsrcdir/$pkgdir\n";
		safe_chdir("$pkgsrcdir/$pkgdir");
		system('make fetch-list | sh');
		}
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
    elsif (-l $_ && -d $_)
	{ push(@prebuilt_pkgdirs, readlink($_)); }
    }

# Dewey decimal verson number matching - or thereabouts
# Also handles 'nb<N>' suffix (checked iff values otherwise identical)
#
sub deweycmp
    {
    my($match, $test, $val) = @_;
    my($cmp, $match_nb, $val_nb);

    $match_nb = $val_nb = 0;
    if ($match =~ /(.*)nb(.*)/)	# Handle nb<N> suffix
	{
	$match = $1;
	$match_nb = $2;
	}

    if ($val =~ /(.*)nb(.*)/)		# Handle nb<N> suffix 
	{
	$val = $1;
	$val_nb = $2;
	}

    $cmp = deweycmp_extract($match, $val);

    if (!$cmp)			# Iff otherwise identical, check nb suffix
	{ $cmp = deweycmp_extract($match_nb, $val_nb); }

    eval "$cmp $test 0";
    }

sub deweycmp_extract
    {
    my($match, $val) = @_;
    my($cmp, @matchlist, @vallist);

    @matchlist = split(/\D+/, $match);
    @vallist = split(/\D+/, $val);
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
    $cmp;
    }

sub fail
    { print STDERR @_, "\n"; exit(3); }

sub get_default_makefile_vars
    {
    my(%vars);

    chomp($_ = `uname -srmp`);
    ( $vars{'OPSYS'},
	$vars{'OS_VERSION'},
	$vars{'MACHINE_ARCH'},
	$vars{'MACHINE'} ) = (split);
    $vars{'EXTRACT_SUFX'} = 'tar.gz';
    $vars{'OBJECT_FMT'} = 'x';
    %vars;
    }

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
	    while (defined($_ = shift @chars))
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
    elsif ( $pkgmatch =~ /^([^*?[]+)(<|>|<=|>=)(\d.+)/ ) 
	{						# (package)(cmp)(dewey)
	my($test);

	($pkg, $test, $matchver) = ($1, $2, $3);

	if ($matchver !~ /^[\d.]+(nb\d+|)$/ )
	    { $matchver = "invalid-dewey($test$matchver)"; }
	elsif (defined($ver = $pkg2ver{$pkg}))
	    {
	    if ( deweycmp($ver, $test, $matchver) )
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
    my($pkgname, %vars, $key, $plus, $value, @data,
       @if_false); # 0:true 1:false 2:nested-false&nomore-elsif

    if (! open(FILE, $file))
	{ return(undef); }
    @data = map {chomp; $_} <FILE>;
    close(FILE);

    # Some Makefiles depend on these being set
    %vars = %default_makefile_vars;
    if ($file =~ m#(.*)/#)
	{ $vars{'.CURDIR'} = $1; }
    if ($opt{'L'})
	{ print "$file\n"; }

    while( defined($_ = shift(@data)) )
	{
	s/#.*//;

	# Continuation lines
	#
	while ( substr($_, -1) eq "\\" )
	    { substr($_, -2) = shift @data; }

	# Conditionals
	#
	if (m#^\.if(|def|ndef)\s+(.*)#)
	    {
	    my($type, $false);

	    $type = $1;
	    if ($if_false[$#if_false])
		{ push(@if_false, 2); }
	    elsif( $type eq '')	# Straight if
		{ push(@if_false, &parse_eval_make_false($2, \%vars)); }
	    else
		{
		$false = ! defined($vars{parse_expand_vars($2, \%vars)});
		if ( $type eq 'ndef' )
		    { $false = ! $false ; }
		push(@if_false, $false ?1 :0);
		}
	    debug("$file: .if$type (@if_false)\n");
	    next;
	    }
	if (m#^\.elif\s+(.*)# && @if_false)
	    {
	    if ($if_false[$#if_false] == 0)
		{ $if_false[$#if_false] = 2; }
	    elsif ($if_false[$#if_false] == 1 &&
		    ! &parse_eval_make_false($1, \%vars) )
		{ $if_false[$#if_false] = 0; }
	    debug("$file: .elif (@if_false)\n");
	    next;
	    }
	if (m#^\.else\b# && @if_false)
	    {
	    $if_false[$#if_false] = $if_false[$#if_false]?0:1;
	    debug("$file: .else (@if_false)\n");
	    next;
	    }
	if (m#^\.endif\b#)
	    {
	    pop(@if_false);
	    debug("$file: .endif (@if_false)\n");
	    next;
	    }

        $if_false[$#if_false] && next;

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
		    unshift(@data, map {chomp; $_} <FILE>);
		    close(FILE);
		    }
		}
	    next;
	    }

	if (/^ *(\w+)([+?]?)\s*=\s*(\S.*)/)
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
    debug("simple-expand: $file\n");

    # Handle simple variable substitutions FRED = a-${FRED}-b
    # Must be before next block to handle FRED = a-${JIM:S/-/-${SHELIA}-/}
    #
    my($loop);
    for ($loop = 1 ; $loop ;)
	{
	$loop = 0;
	foreach $key ( keys %vars )
	    {
	    $_ = parse_expand_vars($vars{$key}, \%vars);
	    if ( $_ ne $vars{$key} )
		{
		$vars{$key} = $_;
		$loop = 1;
		}
	    }
	}

    debug("complex-expand: $file\n");

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
	if (defined($vars{'RESTRICTED'}) || defined($vars{'LICENSE'}))
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

sub parse_eval_make_false
    {
    my($line, $vars) = @_;
    my($false, $test);

    $false = 0;
    $test = parse_expand_vars($line, $vars);
    # XX This is _so_ wrong - need to parse this correctly
    $test =~ s/"//g;

    debug("conditional: $test\n");
    while ( $test =~ /defined\((\S+)\)/ )
	{
	$_ = (defined($${vars}{$1}) ?1 :0);
	$test =~ s/defined\(\S+\)/$_/;
	}
    while ( $test =~ /([^\s()]+)\s+==\s+([^\s()]+)/ )
	{
	$_ = ($1 eq $2) ?1 :0;
	$test =~ s/\S+\s+==\s+\S+/$_/;
	}
    if ($test !~ /[^\d()\s&|]/ )
	{ $false = (eval $test) ?0 :1; }
    else
	{ $false = 0; }
    $false;
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
	foreach $pkg ( sort grep(substr($_, 0, 1) ne '.', readdir(CAT) ) )
	    {
	    if (-f "$pkg/Makefile")
		{
		if (!open(PKGLINT, "cd $pkg ; pkglint $pkglint_flags|"))
		    { &fail("Unable to run pkglint: $!"); }
		@output = grep(!/^OK:/ &&
			     !/^WARN: be sure to cleanup .* work before/ &&
			     !/^WARN: is it a new port/ &&
			     !/^\d+ fatal errors and \d+ warnings found/
			     , <PKGLINT> );
		close(PKGLINT);
		if (@output)
		    { print "===> $cat/$pkg\n", @output, "\n"; }
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
    my($cat, @categories, $pkgdir, $pkgname);
    my(%depends);

    @categories = &list_pkgsrc_categories($pkgsrcdir);
    &verbose("Scanning pkgsrc Makefiles: ");
    if (!$opt{'L'})
	{ &verbose('_'x@categories."\b"x@categories); }
    else
	{ &verbose("\n"); }

    foreach $cat ( sort @categories )
	{
	if (! opendir(CAT, "$pkgsrcdir/$cat"))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkgdir ( sort grep(substr($_, 0, 1) ne '.', readdir(CAT) ) )
	    {
	    my(%vars);
	    ($pkgname, %vars) =
			    &parse_makefile("$pkgsrcdir/$cat/$pkgdir/Makefile");
	    if ($pkgname)
		{
		if ($pkgname !~ /(.*)-(\d.*)/)
		    { print "Cannot extract $pkgname version ($cat/$pkgdir)\n"; }
		elsif ($pkgdir !~ /-current/)
		    {
		    if (defined $pkg2ver{$1} &&
					&deweycmp($pkg2ver{$1}, '>', $2))
			{ next; }
		    $pkg2ver{$1} = $2;
		    $pkgver2dir{$pkgname} = "$cat/$pkgdir";
		    if (defined($vars{'DEPENDS'}))
			{ $depends{$pkgname} = $vars{'DEPENDS'}; }
		    }
		}
	    }
	close(CAT);
	if (!$opt{'L'})
	    { &verbose('.'); }
	}

    if (!$opt{'L'})
	{
	my ($len);
	$_ = scalar(keys %pkgver2dir).' packages';
	$len = @categories - length($_);
	&verbose("\b"x@categories, $_, ' 'x$len, "\b"x$len, "\n");
	}

    if ($check_depends)
	{
	foreach $pkgname ( sort keys %depends )
	    {
	    my($err, $msg);
	    foreach (split("\n", $depends{$pkgname}))
		{
		s/:.*// || next;
		if (($msg = &invalid_version($_)) )
		    {
		    if (!defined($err))
			{ print "$pkgver2dir{$pkgname} DEPENDS errors:\n"; }
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
	foreach $pkg ( sort grep(substr($_, 0, 1) ne '.', readdir(CAT) ) )
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

    foreach $file (&listdir("$pkgdistdir"))
	{
	if (!defined($distfiles{$file}))
	    { push(@bad_distfiles, $file); }
	else
	    { push(@distfiles, $file); }
	}
    if ($check_unref && @bad_distfiles)
	{
	&verbose(scalar(@bad_distfiles),
			" unreferenced file(s) in '$pkgdistdir':\n");
	print join("\n", sort @bad_distfiles), "\n";
	}
    if ($check_md5)
	{
	if (@distwarn)
	    { &verbose(@distwarn); }
	&verbose("md5 mismatches\n");
	@distfiles = sort @distfiles;
	&safe_chdir("$pkgdistdir");
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

# Remember to update manual page when modifying option list
#
sub usage_and_exit
    {
    print "Usage: lintpkgsrc [opts]
opts:
  -h	     : This help.
  -d	     : Check 'DEPENDS' are up to date.
  -i	     : Check installed package versions against pkgsrc.
  -l	     : Pkglint every package in pkgsrc.
  -R	     : List any RESTRICTED/LICENCE prebuilt packages.
  -m	     : List md5 mismatches for files in distfiles/.
  -o	     : List old/obsolete distfiles (not referenced by any md5).
  -p	     : List old/obsolete prebuilt packages.
  -r	     : Remove any 'bad' distfiles (Without -m, -o, or -p, implies all).

  -L         : List each Makefile when scanned
  -P path    : Set PKGSRCDIR
  -K path    : Set basedir for prebuild packages (default PKGSRCDIR/packages)
  -M path    : Set basedir for distfiles (default PKGSRCDIR/distfiles)
  -D [paths] : Parse Makefiles and output contents (For debugging)

If pkgsrc is not in /usr/pkgsrc, set PKGSRCDIR in /etc/mk.conf
";
    exit;
    }

sub verbose
    { print STDERR @_; }

sub debug
    {
    ($opt{'D'}) && print STDERR 'DEBUG: ', @_;
    }
