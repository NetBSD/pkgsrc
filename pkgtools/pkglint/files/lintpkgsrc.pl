#!@PREFIX@/bin/perl

# $NetBSD: lintpkgsrc.pl,v 1.58 2001/12/03 18:20:49 abs Exp $

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
use Cwd;
my(	%pkg,			# {$ver} ->{restricted} ->{dir} ->{BROKEN}
	$default_vars,		# Set for Makefiles, inc PACKAGES & PKGSRCDIR
	%opt,			# Command line options
	%vuln,			# vulnerability data
	@matched_prebuiltpackages,# List of obsolete prebuilt package paths
	@prebuilt_pkgdirs,	# Use to follow symlinks in prebuilt pkgdirs
	);

$ENV{PATH} .= ':/usr/sbin';

if (! &getopts('BDK:LM:OP:RSVdg:hilmopru', \%opt) || $opt{h} ||
	! ( defined($opt{d}) || defined($opt{g}) || defined($opt{i}) ||
	    defined($opt{l}) || defined($opt{m}) || defined($opt{o}) ||
	    defined($opt{p}) || defined($opt{r}) || defined($opt{u}) ||
	    defined($opt{B}) || defined($opt{D}) || defined($opt{R}) ||
	    defined($opt{O}) || defined($opt{S}) || defined($opt{V}) ))
    { &usage_and_exit; }
$| = 1;

&get_default_makefile_vars; # $default_vars

if ($opt{D} && @ARGV)
    {
    my($file);
    foreach $file (@ARGV)
	{
	if ( -d $file)
	    { $file .= "/Makefile"; }
	if (! -f $file)
	    { &fail("No such file: $file"); }
	my($pkgname, $vars);
	($pkgname, $vars) = parse_makefile_pkgsrc($file);
	$pkgname ||= 'UNDEFINED';
	print "$file -> $pkgname\n";
	foreach ( sort keys %{$vars} )
	    { print "\t$_ = $vars->{$_}\n"; }
	if ($opt{d})
	    { &pkgsrc_check_depends(); }
	}
    exit;
    }

# main
    {
    my($pkglint_flags, $pkgsrcdir, $pkgdistdir);

    $pkgsrcdir = $default_vars->{PKGSRCDIR};
    $pkgdistdir = $default_vars->{DISTDIR};
    $pkglint_flags = '-v';

    if ($opt{r} && !$opt{o} && !$opt{m} && !$opt{p})
	{ $opt{o} = $opt{m} = $opt{p} = 1; }
    if ($opt{o} || $opt{m})
	{
	my(@baddist);

	@baddist = &scan_pkgsrc_distfiles_vs_distinfo($pkgsrcdir, $pkgdistdir,
							$opt{o}, $opt{m});
	if ($opt{r})
	    {
	    safe_chdir("$pkgdistdir");
	    &verbose("Unlinking 'bad' distfiles\n");
	    foreach (@baddist)
		{ unlink($_); }
	    }
	}

    # List BROKEN packages
    if ($opt{B})
	{
	my($pkgname, $ver);
	&scan_pkgsrc_makefiles($pkgsrcdir);
	foreach $pkgname (sort keys %pkg)
	    {			# Print highest number first
	    foreach $ver (reverse sort keys %{$pkg{$pkgname}})
		{
		if ($pkg{$pkgname}{$ver}{BROKEN})
		    { print "$pkgname-$ver: $pkg{$pkgname}{$ver}{BROKEN}\n"; }
		}
	    }
	}

    # List obsolete or NO_BIN_ON_FTP/RESTRICTED prebuilt packages
    #
    if ($opt{p} || $opt{O} || $opt{R} || $opt{V})
	{
	if ($opt{V})
	    {
	    my($vuln) = "$pkgdistdir/vulnerabilities";
	    if (! open(VULN, $vuln))
		{ &fail("Unable to open '$vuln': $!"); }
	    while (<VULN>)
		{
		s/#.*//;
		if ( /([^*?[]+)(<|>|<=|>=)(\d\S+)/ ) 
		    { push(@{$vuln{$1}},"$2 $3"); }
		}
	    close(VULN);
	    }
	if ($opt{p} || $opt{O} || $opt{R})
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	@prebuilt_pkgdirs = ($default_vars->{PACKAGES});
	while (@prebuilt_pkgdirs)
	    { find(\&check_prebuilt_packages, shift @prebuilt_pkgdirs); }
	if ($opt{r})
	    {
	    &verbose("Unlinking listed prebuiltpackages\n");
	    foreach (@matched_prebuiltpackages)
		{ unlink($_); }
	    }
	}

    if ($opt{S})
	{
	my($cat, %in_subdir, $pkgname, $ver);

	foreach $cat (&list_pkgsrc_categories($pkgsrcdir))
	    {
	    my($vars) = parse_makefile_vars("$pkgsrcdir/$cat/Makefile");
	    if (! $vars->{SUBDIR})
		{ print "Warning - no SUBDIR for $cat\n"; next; }
	    foreach (split(/\s+/, $vars->{SUBDIR}))
		{ $in_subdir{"$cat/$_"} = 1; }
	    }

	&scan_pkgsrc_makefiles($pkgsrcdir);
	foreach $pkgname (sort keys %pkg)
	    {			# Print highest number first
	    foreach $ver (reverse sort keys %{$pkg{$pkgname}})
		{
		if (!defined $in_subdir{$pkg{$pkgname}{$ver}{dir}})
		    { print "$pkg{$pkgname}{$ver}{dir}: Not in SUBDIR\n"; }
		}
	    }
	}

    if ($opt{g})
	{
	my($pkgname, $ver, $tmpfile);

	$tmpfile = "$opt{g}.tmp.$$";

	&scan_pkgsrc_makefiles($pkgsrcdir);
	if (!open(TABLE, ">$tmpfile"))
	    { &fail("Unable to write '$tmpfile': $!"); }
	foreach $pkgname (sort keys %pkg)
	    {			# Print highest number first
	    foreach $ver (reverse sort keys %{$pkg{$pkgname}})
		{ print TABLE "$pkgname\t$pkg{$pkgname}{$ver}{dir}\t$ver\n"; }
	    }
	if (!close(TABLE))
	    { &fail("Error while writing '$tmpfile': $!"); }
	if (!rename($tmpfile, $opt{g}))
	    { &fail("Error in rename('$tmpfile','$opt{g}'): $!"); }
	}

    if ($opt{d})
	{
	&scan_pkgsrc_makefiles($pkgsrcdir);
	&pkgsrc_check_depends;
	}
    if ($opt{i} || $opt{u})
	{
	my(@pkgs, %update, $pkg);

	@pkgs = &list_installed_packages;
	&scan_pkgsrc_makefiles($pkgsrcdir);

	foreach $pkg (sort @pkgs)
	    {
	    if ( $_ = &invalid_version($pkg) )
		{
		print $_;
		if ( $pkg =~ /^([^*?[]+)-([\d*?[].*)/ ) 
		    {
		    my($ver);
		    foreach (reverse sort keys %{$pkg{$1}})
			{
			$pkg{$1}{$_}->{dir} =~ /-current/ && next;
			$update{$1} = $_;
			last;
			}
		    }
		}
	    }

	if ($opt{u})
	    {
	    my($pkgname);
	    print "\nREQUIRED details for packages that could be updated:\n";
	    foreach $pkgname (sort keys %update)
		{
		print "$pkgname:";
		if (open(PKGINFO, "pkg_info -R $pkgname|"))
		    {
		    my($list);
		    while (<PKGINFO>)
			{
			if (/Required by:/)
			    { $list = 1; }
			elsif ($list)
			    {
			    chomp;
			    s/-\d.*//;
			    print " $_";
			    }
			}
		    close(PKGINFO);
		    }
		print "\n";
		}
	    print "\nRunning 'make fetch-list | sh' for each package:\n";
	    foreach $pkgname (sort keys %update)
		{
		my($pkgdir);

		$pkgdir = $pkg{$pkgname}{$update{$pkgname}}->{dir};
		if (!defined($pkgdir))
		    { &fail("Unable to determine directory for '$pkgname'"); }
		print "$pkgsrcdir/$pkgdir\n";
		safe_chdir("$pkgsrcdir/$pkgdir");
		system('make fetch-list | sh');
		}
	    }
	}
    if ($opt{l})
	{ &pkglint_all_pkgsrc($pkgsrcdir, $pkglint_flags); }
    }
exit;

# Could speed up by building a cache of package names to paths, then processing
# each package name once against the tests.
sub check_prebuilt_packages
    {
    if ($_ eq 'distfiles' || $_ eq 'pkgsrc') # Skip these subdirs if present
	{ $File::Find::prune = 1; }
    elsif (/(.+)-(\d.*)\.tgz$/)
	{
	my($pkgname, $ver);
	($pkgname, $ver) = ($1, $2);

	if ($opt{V} && $vuln{$pkgname})
	    {
	    my($chk);
	    foreach $chk (@{$vuln{$pkgname}})
		{
		my($test, $matchver) = split(' ',$chk);
		if (deweycmp($ver, $test, $matchver))
		    {
		    print "$File::Find::dir/$_\n";
		    push(@matched_prebuiltpackages, "$File::Find::dir/$_");
		    last;
		    }
		}
	    }

	if (defined $pkg{$1})
	    {
	    my($chkver) = ($ver);
	    if (!defined $pkg{$pkgname}{$chkver})
		{
		if ($opt{p})
		    {
		    print "$File::Find::dir/$_\n";
		    push(@matched_prebuiltpackages, "$File::Find::dir/$_");
		    }
		# Pick probably the last version
		($chkver) = (reverse sort keys %{$pkg{$pkgname}});
		}
	    if ($opt{R} && defined $pkg{$pkgname}{$chkver}->{restricted})
		{
		print "$File::Find::dir/$_\n";
		push(@matched_prebuiltpackages, "$File::Find::dir/$_");
		}
	    if ($opt{O} && defined $pkg{$pkgname}{$chkver}->{osversion_specific})
		{
		print "$File::Find::dir/$_\n";
		push(@matched_prebuiltpackages, "$File::Find::dir/$_");
		}
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
    chomp($_ = `uname -srm`);
    ( $default_vars->{OPSYS},
	$default_vars->{OS_VERSION},
	$default_vars->{MACHINE} ) = (split);

    # Handle systems without uname -p  (NetBSD pre 1.4)
    chomp($default_vars->{MACHINE_ARCH} = `uname -p 2>/dev/null`);
    if (! $default_vars->{MACHINE_ARCH} &&
				$default_vars->{OS_VERSION} eq 'NetBSD')
	{ chomp($default_vars->{MACHINE_ARCH} = `sysctl -n hw.machine_arch`);}
    if (! $default_vars->{MACHINE_ARCH})
	{ $default_vars->{MACHINE_ARCH} = $default_vars->{MACHINE}; }

    $default_vars->{EXTRACT_SUFX} = 'tar.gz';
    $default_vars->{OBJECT_FMT} = 'x';
    $default_vars->{LOWER_OPSYS} = lc($default_vars->{OPSYS});

    if ($opt{P})
	{ $default_vars->{PKGSRCDIR} = $opt{P}; }
    else
	{ $default_vars->{PKGSRCDIR} = '/usr/pkgsrc'; }

    my($vars);
    if (-f '/etc/mk.conf' && ($vars = parse_makefile_vars('/etc/mk.conf')))
	{
	foreach (keys %{$vars})
	    { $default_vars->{$_} = $vars->{$_}; }
	}

    if ($opt{P})
	{ $default_vars->{PKGSRCDIR} = $opt{P}; }

    if ($opt{M})
	{ $default_vars->{DISTDIR} = $opt{M}; }
    $default_vars->{DISTDIR} ||= $default_vars->{PKGSRCDIR}.'/distfiles';

    if ($opt{K})
	{ $default_vars->{PACKAGES} = $opt{K}; }
    $default_vars->{PACKAGES} ||= $default_vars->{PKGSRCDIR}.'/packages';
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
	if (defined $pkg{$pkg})
	    {
	    $fail = "Version mismatch: '$pkg' $badver vs ".
				join(',', sort keys %{$pkg{$pkg}})."\n";
	    }
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
    @categories = grep(substr($_, 0, 1) ne '.' && $_ ne 'CVS' &&
				-f "$pkgsrcdir/$_/Makefile", readdir(BASE));
    closedir(BASE);
    @categories;
    }

# For a given category, list potentially valid pkgdirs
#
sub list_pkgsrc_pkgdirs
    {
    my($pkgsrcdir, $cat) = @_;
    my(@pkgdirs);

    if (! opendir(CAT, "$pkgsrcdir/$cat"))
	{ die("Unable to opendir($pkgsrcdir/cat): $!"); }
    @pkgdirs = sort grep($_ ne 'Makefile' && $_ ne 'pkg' && $_ ne 'CVS' &&
					substr($_, 0, 1) ne '.', readdir(CAT));
    close(CAT);
    @pkgdirs;
    }

sub glob2regex
    {
    my($glob) = @_;
    my(@chars, $in_alt);
    my($regex);

    @chars = split(//, $glob);
    while (defined($_ = shift @chars))
	{
	if ($_ eq '*')
	    { $regex .= '.*'; }
	elsif ($_ eq '?')
	    { $regex .= '.'; }
	elsif ($_ eq '+')
	    { $regex .= '.'; }
	elsif ($_ eq '\\+')
	    { $regex .= $_ . shift @chars; }
	elsif ($_ eq '.' || $_ eq '|' )
	    { $regex .= quotemeta; }
	elsif ($_ eq '{' )
	    { $regex .= '('; ++$in_alt; }
	elsif ($_ eq '}' )
	    {
	    if (!$in_alt)		# Error
		{ return undef; }
	    $regex .= ')';
	    --$in_alt;
	    }
	elsif ($_ eq ','  && $in_alt)
	    { $regex .= '|'; }
	else
	    { $regex .= $_; }
	}
    if ($in_alt)			# Error
	{ return undef; }
    if ($regex eq $glob)
	{ return(''); }
    if ($opt{D})
	{ print "glob2regex: $glob -> $regex\n"; }
    '^'.$regex.'$';
    }

# Perform some (reasonable) subset of 'pkg_info -e' / glob(3)
# Returns (sometimes best guess at) package name,
# and either 'problem version' or undef if all OK
#
sub package_globmatch
    {
    my($pkgmatch) = @_;
    my($matchpkgname, $matchver, $regex);

    if ( $pkgmatch =~ /^([^*?[]+)(<|>|<=|>=)(\d\S+)/ ) 
	{						# (package)(cmp)(dewey)
	my($test);

	($matchpkgname, $test, $matchver) = ($1, $2, $3);

	if ($matchver !~ /^[\d.]+(nb\d+|)$/ )
	    { $matchver = "invalid-dewey($test$matchver)"; }
	else
	    {
	    my($ver);
	    if (defined $pkg{$matchpkgname})
		{
		foreach $ver (%{$pkg{$matchpkgname}})
		    {
		    if (deweycmp($ver, $test, $matchver))
			{ $matchver = undef; last }
		    }
		if ($matchver)
		    { $matchver = "$test$matchver"; }
		}
	    }
	}
    elsif ( $pkgmatch =~ /^([^[]+)-([\d*?{[].*)$/ )
	{					 	# (package)-(globver)
	my($pkgname, $ver, @pkgnames);

	($matchpkgname, $matchver) = ($1, $2);

	if (defined $pkg{$matchpkgname})
	    { push(@pkgnames, $matchpkgname); }
	elsif ($regex = glob2regex($matchpkgname))
	    {
	    foreach $pkgname (sort keys %pkg)
		{ ($pkgname =~ /$regex/) && push(@pkgnames, $pkgname); }
	    }

	# Try to convert $matchver into regex version
	#
	$regex = glob2regex($matchver);

	foreach $pkgname (@pkgnames)
	    {
	    if (defined $pkg{$pkgname}{$matchver})
		{ return($matchver); }

	    if ($regex)
		{
		foreach $ver (keys %{$pkg{$pkgname}})
		    {
		    if( $ver =~ /$regex/ )
			{ $matchver = undef; last }
		    }
		}
	    $matchver || last;
	    }

	# last ditch attempt to handle the whole DEPENDS as a glob
	#
	if ($matchver && ($regex = glob2regex($pkgmatch)))	# (large-glob)
	    {
	    my($pkgname, $ver);
	    foreach $pkgname (sort keys %pkg)
		{
		foreach $ver (keys %{$pkg{$pkgname}})
		    {
		    if( "$pkgname-$ver" =~ /$regex/ )
			{ $matchver = undef; last }
		    }
		$matchver || last;
		}
	    }
	}
    else
	{ ($matchpkgname, $matchver) = ($pkgmatch, 'missing'); }
    ($matchpkgname, $matchver);
    }

# Parse a pkgsrc package makefile and return the pkgname and set variables
#
sub parse_makefile_pkgsrc
    {
    my($file) = @_;
    my($pkgname, $vars);

    $vars = parse_makefile_vars($file);

    if (!$vars) # Missing Makefile
	{ return(undef); }

    if (defined $vars->{PKGNAME})
	{ $pkgname = $vars->{PKGNAME}; }
    elsif (defined $vars->{DISTNAME})
	{
	$pkgname = $vars->{DISTNAME};
	}
    if (defined $pkgname)
	{
	if (defined $vars->{PKGREVISION})
	    {
	    $pkgname .= "nb";
	    $pkgname .= $vars->{PKGREVISION};
	    }
	if ( $pkgname =~ /\$/ )
	    { print "\rBogus: $pkgname (from $file)\n"; }
	elsif ($pkgname =~ /(.*)-(\d.*)/)
	    {
	    my($cat, $pkgdir);

	    if (defined $vars->{NO_BIN_ON_FTP} ||
		defined $vars->{RESTRICTED})
		{ $pkg{$1}{$2}{restricted} = 1; }
	    if (defined $vars->{OSVERSION_SPECIFIC})
		{ $pkg{$1}{$2}{osversion_specific} = 1; }
	    if (defined $vars->{BROKEN})
		{ $pkg{$1}{$2}{BROKEN} = $vars->{BROKEN}; }
	    if ($file =~ m:([^/]+)/([^/]+)/Makefile$:)
		{
		$cat = $1;
		$pkgdir = $2;
		}
	    else
		{ $cat = $pkgdir = 'unknown'; }
	    if ($pkgname !~ /(.*)-(\d.*)/)
		{
		print "Cannot extract $pkgname version ($cat/$pkgdir)\n";
		next;
		}
	    else
		{
		$pkg{$1}{$2}{dir} = "$cat/$pkgdir";
		$pkg{$1}{$2}{depends} = $vars->{DEPENDS};
		}
	    }
	return($pkgname, $vars);
	}
    else
	{ return(undef); }
    }

# Extract variable assignments from Makefile
# Much unpalatable magic to avoid having to use make (all for speed)
#
sub parse_makefile_vars
    {
    my($file) = @_;
    my($pkgname, %vars, $key, $plus, $value, @data,
       @if_false); # 0:true 1:false 2:nested-false&nomore-elsif

    if (! open(FILE, $file))
	{ return(undef); }
    @data = map {chomp; $_} <FILE>;
    close(FILE);

    # Some Makefiles depend on these being set
    if ($file eq '/etc/mk.conf')
	{ $vars{LINTPKGSRC} = 'YES'; }
    else
	{ %vars = %{$default_vars}; }
    $vars{BSD_PKG_MK} = 'YES';

    if ($file =~ m#(.*)/#)
	{ $vars{'.CURDIR'} = $1; }
    else
	{ $vars{'.CURDIR'} = getcwd; }
    if ($opt{L})
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

	if (/^ *(\w+)\s*([+?]?)=\s*(.*)/)
	    {
	    $key = $1;
	    $plus = $2;
	    $value = $3;
	    if ($plus eq '+' && defined $vars{$key} )
		{ $vars{$key} .= " $value"; }
	    elsif ($plus ne '?' || !defined $vars{$key} )
		{ $vars{$key} = $value; }
	    } 
	}

    debug("$file: expand\n");

    # Handle variable substitutions  FRED = a-${JIM:S/-/-b-/}
    #
    my($loop);
    for ($loop = 1 ; $loop ;)
	{
	$loop = 0;
	foreach $key (keys %vars)
	    {
	    if ( index($vars{$key}, '$') == -1 )
		{ next; }
	    $_ = parse_expand_vars($vars{$key}, \%vars);
	    if ($_ ne $vars{$key})
		{
		$vars{$key} = $_;
		$loop = 1;
		}
	    elsif ($vars{$key} =~ m#\${(\w+):([CS]([^{}])[^{}\3]+\3[^{}\3]*\3[g1]*(|:[^{}]+))}#)
		{
		my($left, $subvar, $right) = ($`, $1, $');
		my(@patterns) = split(':', $2);
		my($result);

		$result = $vars{$subvar};
		$result ||= '';

		# If $vars{$subvar} contains a $ skip it on this pass.
		# Hopefully it will get substituted and we can catch it
		# next time around.
		if (index($result, '${') != -1)
		    { next; }

		debug("$file: substitutelist $key ($result) $subvar (@patterns)\n");
		foreach (@patterns)
		    {
		    if (! m#([CS])/([^/]+)/([^/]*)/([1g]*)#)
			{ next; }

		    my($how, $from, $to, $global) = ($1, $2, $3, $4);

		    debug("$file: substituteglob $subvar, $how, $from, $to, $global\n");
		    if ($how eq 'S') # Limited substitution - keep ^ and $
			{ $from =~ s/([?.{}\]\[*+])/\\$1/g; }
		    $to =~ s/\\(\d)/\$$1/g; # Change \1 etc to $1

		    my($notfirst);
		    if ($global =~ s/1//)
			{ ($from, $notfirst) = split('\s', $from, 2); }

		    debug("$file: substituteperl $subvar, $how, $from, $to\n");
		    eval "\$result =~ s/$from/$to/$global";
		    if (defined $notfirst)
			{ $result .= " $notfirst"; }
		    }
		$vars{$key} = $left . $result . $right;
		$loop = 1;
		}
	    }
	}
    \%vars;
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
    while ( $test =~ /([^\s()]+)\s+(!=|==)\s+([^\s()]+)/ )
	{
	if ($2 eq '==')
	    { $_ = ($1 eq $3) ?1 :0; }
	else
	    { $_ = ($1 ne $3) ?1 :0; }
	$test =~ s/\S+\s+(!=|==)\s+\S+/$_/;
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
    my($cat, $pkgdir, @categories, @output);

    @categories = &list_pkgsrc_categories($pkgsrcdir);
    foreach $cat ( sort @categories )
	{
	safe_chdir("$pkgsrcdir/$cat");
	foreach $pkgdir (&list_pkgsrc_pkgdirs($pkgsrcdir, $cat))
	    {
	    if (-f "$pkgdir/Makefile")
		{
		if (!open(PKGLINT, "cd $pkgdir ; pkglint $pkglint_flags|"))
		    { &fail("Unable to run pkglint: $!"); }
		@output = grep(!/^OK:/ &&
			     !/^WARN: be sure to cleanup .*work.* before/ &&
			     !/^WARN: is it a new package/ &&
			     !/^\d+ fatal errors and \d+ warnings found/
			     , <PKGLINT> );
		close(PKGLINT);
		if (@output)
		    { print "===> $cat/$pkgdir\n", @output, "\n"; }
		}
	    }
	}
    }

# chdir() || fail()
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

    if (%pkg) # Already done
	{ return; }
    @categories = &list_pkgsrc_categories($pkgsrcdir);
    &verbose("Scanning pkgsrc Makefiles: ");
    if (!$opt{L})
	{ &verbose('_'x@categories."\b"x@categories); }
    else
	{ &verbose("\n"); }

    foreach $cat ( sort @categories )
	{
	foreach $pkgdir (&list_pkgsrc_pkgdirs($pkgsrcdir, $cat))
	    {
	    my($vars);
	    ($pkgname, $vars) =
		    parse_makefile_pkgsrc("$pkgsrcdir/$cat/$pkgdir/Makefile");
	    }
	if (!$opt{L})
	    { &verbose('.'); }
	}

    if (!$opt{L})
	{
	my ($len);
	$_ = scalar(keys %pkg).' packages';
	$len = @categories - length($_);
	&verbose("\b"x@categories, $_, ' 'x$len, "\b"x$len, "\n");
	}
    }

# Cross reference all depends
#
sub pkgsrc_check_depends
    {
    my($pkgname);
    foreach $pkgname (sort keys %pkg)
	{
	my($ver);
	foreach $ver (keys %{$pkg{$pkgname}})
	    {
	    my($err, $msg);
	    defined $pkg{$pkgname}{$ver}{depends} || next;
	    foreach (split(" ", $pkg{$pkgname}{$ver}{depends}))
		{
		s/:.*// || next;
		if (($msg = &invalid_version($_)) )
		    {
		    if (!defined($err))
			{ print "$pkgname-$ver DEPENDS errors:\n"; }
		    $err = 1;
		    print "\t$msg";
		    }
		}
	    }
	}
    }

# Extract all distinfo entries, then verify contents of distfiles
#
sub scan_pkgsrc_distfiles_vs_distinfo
    {
    my($pkgsrcdir, $pkgdistdir, $check_unref, $check_distinfo) = @_;
    my($cat, @categories, $pkgdir);
    my(%distfiles, %sumfiles, @distwarn, $file, $numpkg);
    my(%bad_distfiles);

    @categories = &list_pkgsrc_categories($pkgsrcdir);

    &verbose("Scanning pkgsrc distinfo: ".'_'x@categories."\b"x@categories);
    $numpkg = 0;
    foreach $cat (sort @categories)
	{
	foreach $pkgdir (&list_pkgsrc_pkgdirs($pkgsrcdir, $cat))
	    {
	    if (open(DISTINFO, "$pkgsrcdir/$cat/$pkgdir/distinfo"))
		{
		++$numpkg;
		while( <DISTINFO> )
		    {
		    if (m/^(\w+) ?\(([^\)]+)\) = (\S+)/)
			{
			if ($2 =~ /^patch-[a-z0-9]+$/)
			    { next; }
			if (!defined $distfiles{$2})
			    {
			    $distfiles{$2}{sumtype} = $1;
			    $distfiles{$2}{sum} = $3;
			    $distfiles{$2}{path} = "$cat/$pkgdir";
			    }
			elsif ($distfiles{$2}{sumtype} eq $1 &&
				$distfiles{$2}{sum} ne $3)
			    {
			    push(@distwarn, "checksum mismatch between '$1' ".
			    "in $cat/$pkgdir and $distfiles{$2}{path}\n");
			    }
			}
		    }
		close(DISTINFO);
		}
	    }
	&verbose('.');
	}
    &verbose(" ($numpkg packages)\n");

    # Do not mark the vulnerabilities file as unknown
    $distfiles{vulnerabilities} = { path => 'vulnerabilities',
				      sum => 'IGNORE'};

    foreach $file (&listdir("$pkgdistdir"))
	{
	my($dist);
	if (!defined($dist = $distfiles{$file}))
	    { $bad_distfiles{$file} = 1; }
	else
	    {
	    if ($dist->{sum} ne 'IGNORE')
		{ push(@{$sumfiles{$dist->{sumtype}}}, $file); }
	    }
	}

    if ($check_unref && %bad_distfiles)
	{
	&verbose(scalar(keys %bad_distfiles),
			" unreferenced file(s) in '$pkgdistdir':\n");
	print join("\n", sort keys %bad_distfiles), "\n";
	}

    if ($check_distinfo)
	{
	my($sum);
	if (@distwarn)
	    { &verbose(@distwarn); }
	&verbose("checksum mismatches\n");
	safe_chdir("$pkgdistdir");
	foreach $sum (keys %sumfiles)
	    {
	    if ($sum eq 'Size')
		{
		foreach (@{$sumfiles{$sum}})
		    {
		    if (! -f $_ || -S $_ != $distfiles{$_}{sum})
			{
			print $_, " (Size)\n";
			$bad_distfiles{$_} = 1;
			}
		    }
		next;
		}
	    open(DIGEST, "digest $sum @{$sumfiles{$sum}}|") ||
						&fail("Run digest: $!");
	    while (<DIGEST>)
		{
		if (m/^$sum ?\(([^\)]+)\) = (\S+)/)
		    {
		    if ($distfiles{$1}{sum} ne $2)
			{
			print $1, " ($sum)\n";
			$bad_distfiles{$1} = 1;
			}
		    }
		}
	    close(DIGEST);
	    }
	}
    (sort keys %bad_distfiles);
    }

# Remember to update manual page when modifying option list
#
sub usage_and_exit
    {
    print "Usage: lintpkgsrc [opts] [makefiles]
opts:
  -h : This help.	 [see lintpkgsrc(1) for more information]

Installed package options:		Distfile options:
  -i : Check version against pkgsrc	  -m : List distinfo mismatches
  -u : As -i + fetch dist (may change)	  -o : List obsolete (no distinfo)

Prebuilt package options:		Makefile options:
  -p : List old/obsolete		  -B : List packages marked as 'BROKEN'
  -O : List OSVERSION_SPECIFIC		  -d : Check 'DEPENDS' up to date
  -R : List NO_BIN_ON_FTP/RESTRICTED	  -S : List packages not in 'SUBDIRS'
  -V : List known vulnerabilities

Misc:
  -g file : Generate 'pkgname pkgdir pkgver' map in file
  -l	  : Pkglint all packages
  -r	  : Remove bad files (Without -m -o -p or -V implies all, can use -R)

Modifiers:
  -K path : Set PACKAGES basedir (default PKGSRCDIR/packages)
  -M path : Set DISTDIR		 (default PKGSRCDIR/distfiles)
  -P path : Set PKGSRCDIR	 (default /usr/pkgsrc)
  -D      : Debug makefile and glob parsing
  -L      : List each Makefile when scanned
";
    exit;
    }

sub verbose
    {
    if (-t STDERR)
	{ print STDERR @_; }
    }

sub debug
    {
    ($opt{D}) && print STDERR 'DEBUG: ', @_;
    }
