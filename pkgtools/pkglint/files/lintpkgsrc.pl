#!/usr/bin/env perl

# $NetBSD: lintpkgsrc.pl,v 1.38 2000/10/20 11:00:13 abs Exp $

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
my(	$pkgdistdir,		# Distfiles directory
	%pkg,			# {$ver} ->{'restricted'} and ->{'dir'}
	$default_vars,		# Set for Makefiles, inc PACKAGES & PKGSRCDIR
	%opt,			# Command line options
	%vuln,			# vulnerability data
	@matched_prebuiltpackages,# List of obsolete prebuilt package paths
	@prebuilt_pkgdirs,	# Use to follow symlinks in prebuilt pkgdirs
	);

$ENV{PATH} .= ':/usr/sbin';

if (! &getopts('SVDK:LM:P:Rdhilmopru', \%opt) || $opt{'h'} ||
	! ( defined($opt{'d'}) || defined($opt{'i'}) || defined($opt{'l'}) ||
	    defined($opt{'m'}) || defined($opt{'o'}) || defined($opt{'p'}) ||
	    defined($opt{'r'}) || defined($opt{'u'}) || defined($opt{'D'}) ||
	    defined($opt{'S'}) || defined($opt{'V'}) || defined($opt{'R'}) ))
    { &usage_and_exit; }
$| = 1;

&get_default_makefile_vars; # $default_vars

if ($opt{'D'} && @ARGV)
    {
    my($file);
    foreach $file (@ARGV)
	{
	if ( -d $file)
	    { $file .= "/Makefile"; }
	if (! -f $file)
	    { &fail("No such file: $file"); }
	my($pkgname, $vars);
	($pkgname, $vars) = &parse_makefile_pkgsrc($file);
	print "$file -> $pkgname\n";
	foreach ( sort keys %{$vars} )
	    { print "\t$_ = $vars->{$_}\n"; }
	if ($opt{'d'})
	    { &pkgsrc_check_depends(); }
	}
    exit;
    }

# main
    {
    my($pkglint_flags, $pkgsrcdir);

    $pkgsrcdir = $default_vars->{'PKGSRCDIR'};
    $pkglint_flags = '-v';

    if ($opt{'M'})
	{ $pkgdistdir = $opt{'M'}; } # override distfile dir
    else
	{ $pkgdistdir = "$pkgsrcdir/distfiles"; } # default


    if ($opt{'r'} && !$opt{'o'} && !$opt{'m'} && !$opt{'p'})
	{ $opt{'o'} = $opt{'m'} = $opt{'p'} = 1; }
    if ($opt{'o'} || $opt{'m'})
	{
	my(@baddist);

	@baddist = &scan_pkgsrc_distfiles_vs_md5($pkgsrcdir,
							$opt{'o'}, $opt{'m'});
	if ($opt{'r'})
	    {
	    &safe_chdir("$pkgdistdir");
	    &verbose("Unlinking 'bad' distfiles\n");
	    foreach (@baddist)
		{ unlink($_); }
	    }
	}

    # List obsolete or NO_BIN_ON_FTP/RESTRICTED prebuilt packages
    #
    if ($opt{'p'} || $opt{'R'} || $opt{'V'})
	{
	if ($opt{'V'})
	    {
	    my($vuln) = "$default_vars->{'PKGSRCDIR'}/distfiles/vulnerabilities";
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
	if (($opt{'p'} || $opt{'R'}) && !%pkg)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	@prebuilt_pkgdirs = ($default_vars->{'PACKAGES'});
	while (@prebuilt_pkgdirs)
	    { find(\&check_prebuilt_packages, shift @prebuilt_pkgdirs); }
	if ($opt{'r'})
	    {
	    &verbose("Unlinking listed prebuiltpackages\n");
	    foreach (@matched_prebuiltpackages)
		{ unlink($_); }
	    }
	}

    if ($opt{'S'})
	{
	my($pkgname, $ver, $tmpfile);

	$tmpfile = "$pkgsrcdir/pkgsrcmap.tmp.$$";

	if (!%pkg)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	if (!open(TABLE, ">$tmpfile"))
	    { &fail("Unable to write '$tmpfile': $!"); }
	foreach $pkgname (sort keys %pkg)
	    {			# Print highest number first
	    foreach $ver (reverse sort keys %{$pkg{$pkgname}})
		{ print TABLE "$pkgname\t$pkg{$pkgname}{$ver}{'dir'}\t$ver\n"; }
	    }
	if (!close(TABLE))
	    { &fail("Error while writing '$tmpfile': $!"); }
	if (!rename($tmpfile, "$pkgsrcdir/pkgsrcmap"))
	    { &fail("Error in rename('$tmpfile','$pkgsrcdir/pkgsrcmap'): $!"); }
	}
    if ($opt{'d'})
	{
	if (!%pkg)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }
	&pkgsrc_check_depends;
	}
    if ($opt{'i'} || $opt{'u'})
	{
	my(@pkgs, @bad, $pkg);

	@pkgs = &list_installed_packages;
	if (!%pkg)
	    { &scan_pkgsrc_makefiles($pkgsrcdir); }

	foreach $pkg ( sort @pkgs )
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
		    { $pkgdir = $pkg{$1}{$2}->{'dir'}; }

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


# Could speed up by building a cache of package names to paths, then processing
# each package name once against the tests.
sub check_prebuilt_packages
    {
    if ($_ eq 'distfiles')
	{ $File::Find::prune = 1; }
    elsif (/(.+)-(\d.*)\.tgz$/)
	{
	my($pkgname, $ver);
	($pkgname, $ver) = ($1, $2);

	if ($opt{'V'} && $vuln{$pkgname})
	    {
	    my($chk);
	    foreach $chk (@{$vuln{$pkgname}})
		{
		my($test, $matchver) = split(' ',$chk);
		if (deweycmp($ver, $test, $matchver))
		    {
		    print "$File::Find::dir/$_\n";
		    push(@matched_prebuiltpackages, "$File::Find::dir/$_");
		    }
		}
	    }

	if (defined $pkg{$1})
	    {
	    my($chkver) = ($ver);
	    if (!defined $pkg{$pkgname}{$chkver})
		{
		if ($opt{'p'})
		    {
		    print "$File::Find::dir/$_\n";
		    push(@matched_prebuiltpackages, "$File::Find::dir/$_");
		    }
		# Pick probably the last version
		($chkver) = (reverse sort keys %{$pkg{$pkgname}});
		}
	    if ($opt{'R'} && defined $pkg{$pkgname}{$chkver}->{'restricted'})
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
    chomp($_ = `uname -srmp`);
    ( $default_vars->{'OPSYS'},
	$default_vars->{'OS_VERSION'},
	$default_vars->{'MACHINE_ARCH'},
	$default_vars->{'MACHINE'} ) = (split);
    $default_vars->{'LINTPKGSRC'} = 'YES';
    $default_vars->{'EXTRACT_SUFX'} = 'tar.gz';
    $default_vars->{'OBJECT_FMT'} = 'x';
    $default_vars->{'LOWER_OPSYS'} = lc($default_vars->{'OPSYS'});

    if ($opt{'P'})
	{ $default_vars->{'PKGSRCDIR'} = $opt{'P'}; }
    else
	{ $default_vars->{'PKGSRCDIR'} = '/usr/pkgsrc'; }

    my($vars);
    if (-f '/etc/mk.conf' && ($vars = &parse_makefile_vars('/etc/mk.conf')))
	{ $default_vars = $vars; }

    if ($opt{'P'})
	{ $default_vars->{'PKGSRCDIR'} = $opt{'P'}; }

    if ($opt{'K'})
	{ $default_vars->{'PACKAGES'} = $opt{'K'}; }
    $default_vars->{'PACKAGES'} ||= $default_vars->{'PKGSRCDIR'}.'/packages';
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
	    { $fail = "Version mismatch: '$pkg' $badver vs ".join(',', sort keys %{$pkg{$pkg}})."\n"; }
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
	elsif ($_ eq '\\')
	    { $regex .= $_ . shift @chars; }
	elsif ($_ eq '.' || $_ eq '|' )
	    { $regex .= quotemeta; }
	elsif ($_ eq '{' )
	    { $regex .= '('; $in_alt = 1; }
	elsif ($_ eq '}' )
	    {
	    if (!$in_alt)		# Error
		{ return undef; }
	    $regex .= ')';
	    $in_alt = 0;
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
	foreach $pkgname (@pkgnames)
	    {
	    if (defined $pkg{$pkgname}{$matchver})
		{ return($matchver); }

	    # Try to convert $globver into regex version

	    if ( $regex = glob2regex($matchver))
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

    $vars = &parse_makefile_vars($file);

    if (!$vars) # Missing Makefile
	{ return(undef); }

    if (defined $vars->{'PKGNAME'})
	{ $pkgname = $vars->{'PKGNAME'}; }
    elsif (defined $vars->{'DISTNAME'})
	{ $pkgname = $vars->{'DISTNAME'}; }
    if (defined $pkgname)
	{
	if ( $pkgname =~ /\$/ )
	    { print "\rBogus: $pkgname (from $file)\n"; }
	elsif ($pkgname =~ /(.*)-(\d.*)/)
	    {
	    my($cat, $pkgdir);

	    if (defined $vars->{'NO_BIN_ON_FTP'} ||
		defined $vars->{'RESTRICTED'})
		{ $pkg{$1}{$2}{'restricted'} = 1; }
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
		$pkg{$1}{$2}{'dir'} = "$cat/$pkgdir";
		$pkg{$1}{$2}{'depends'} = $vars->{'DEPENDS'};
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
    %vars = %{$default_vars};
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

    debug("expand: $file\n");

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
	    elsif ($vars{$key} =~ m#\${(\w+):([CS]/[^{}/]+/[^{}/]*/g?(|:[^{}]+))}#)
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

		debug("substitutelist: $key ($result) $subvar (@patterns)\n");
		foreach (@patterns)
		    {
		    if (! m#([CS])/([^/]+)/([^/]*)/(g?)#)
			{ next; }

		    my($how, $from, $to, $global) = ($1, $2, $3, $4);

		    debug("substituteglob: $subvar, $how, $from, $to, $global\n");
		    if ($how eq 'S') # Limited substitution - keep ^ and $
			{ $from =~ s/([?.{}\]\[*+])/\\$1/g; }
		    $to =~ s/\\(\d)/\$$1/g; # Change \1 etc to $1
		    debug("substituteperl: $subvar, $how, $from, $to\n");
		    eval "\$result =~ s/$from/$to/$global";
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
	&safe_chdir("$pkgsrcdir/$cat");
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

    @categories = &list_pkgsrc_categories($pkgsrcdir);
    &verbose("Scanning pkgsrc Makefiles: ");
    if (!$opt{'L'})
	{ &verbose('_'x@categories."\b"x@categories); }
    else
	{ &verbose("\n"); }

    foreach $cat ( sort @categories )
	{
	foreach $pkgdir (&list_pkgsrc_pkgdirs($pkgsrcdir, $cat))
	    {
	    my($vars);
	    ($pkgname, $vars) =
		    &parse_makefile_pkgsrc("$pkgsrcdir/$cat/$pkgdir/Makefile");
	    }
	if (!$opt{'L'})
	    { &verbose('.'); }
	}

    if (!$opt{'L'})
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
	    defined $pkg{$pkgname}{$ver}{'depends'} || next;
	    foreach (split("\n", $pkg{$pkgname}{$ver}{'depends'}))
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

# Extract all md5 entries, then verify contents of distfiles
#
sub scan_pkgsrc_distfiles_vs_md5
    {
    my($pkgsrcdir, $check_unref, $check_md5) = @_;
    my($cat, @categories, $pkgdir);
    my(%distfiles, %md5, @distwarn, $file, $numpkg);
    my(@distfiles, @bad_distfiles);

    @categories = &list_pkgsrc_categories($pkgsrcdir);

    &verbose("Scanning pkgsrc md5s: ".'_'x@categories."\b"x@categories);
    $numpkg = 0;
    foreach $cat ( sort @categories )
	{
	foreach $pkgdir (&list_pkgsrc_pkgdirs($pkgsrcdir, $cat))
	    {
	    if (open(MD5, "$pkgsrcdir/$cat/$pkgdir/files/md5"))
		{
		++$numpkg;
		while( <MD5> )
		    {
		    if (m/^MD5 \(([^\)]+)\) = (\S+)/)
			{
			if (!defined($distfiles{$1}))
			    {
			    $distfiles{$1} = "$cat/$pkgdir";
			    $md5{$1} = $2;
			    }
			elsif( $md5{$1} ne $2 )
			    {
			    push(@distwarn, "md5 mismatch between '$1' in ".
			    "$cat/$pkgdir and $distfiles{$1}\n");
			    }
			}
		    }
		close(MD5);
		}
	    }
	&verbose('.');
	}
    &verbose(" ($numpkg packages)\n");

    # Do not mark the vulnerabilitis file as unknown
    $distfiles{'vulnerabilities'} = 'vulnerabilities';
    $md5{'vulnerabilities'} = 'IGNORE';

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
  -R	     : List any NO_BIN_ON_FTP/RESTRICTED prebuilt packages (#).
  -V	     : List any prebuilt packages with known vulnerabilities (#).
  -m	     : List md5 mismatches for files in distfiles/.
  -o	     : List old/obsolete distfiles (not referenced by any md5).
  -p	     : List old/obsolete prebuilt packages (#).
  -r	     : Remove 'bad' distfiles or packages (*).
  -u	     : For each installed package ensure distfiles are fetched.
  -S	     : Rebuild PKGSRCDIR/pkgsrcmap

  -L         : List each Makefile when scanned
  -P path    : Set PKGSRCDIR
  -K path    : Set basedir for prebuild packages (default PKGSRCDIR/packages)
  -M path    : Set basedir for distfiles (default PKGSRCDIR/distfiles)
  -D [paths] : Parse Makefiles and output contents (For debugging)

(*) Without any of -m, -o, -p, or -V implies all. Can use with -R.

See lintpkgsrc(1) for more information.
";
    exit;
    }

sub verbose
    { print STDERR @_; }

sub debug
    {
    ($opt{'D'}) && print STDERR 'DEBUG: ', @_;
    }
