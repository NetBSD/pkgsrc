#!/usr/bin/env perl

# $NetBSD: lintpkgsrc.pl,v 1.5 1999/08/01 18:34:41 abs Exp $

# (Somewhat quickly) Written by David Brownlee <abs@netbsd.org>.
# Caveats:
#	The 'Makefile parsing' algorithym used to obtain package versions
#	and DEPENDS information is geared towards speed rather than perfection.
#
#	The 'invalid distfiles' code picks up a couple of false positives in
#	fastcap (which does strange things anyway).

require 'getopts.pl';
$^W=1;
use strict;
use File::Find;
use vars qw($opt_P $opt_d $opt_h $opt_i $opt_l $opt_m $opt_o $opt_p $opt_r);
my(%pkg2dir,@oldprebuiltpackages);

if (! &Getopts('P:dhilmopr') || $opt_h ||
	! ( defined($opt_d) || defined($opt_i) || defined($opt_l) ||
	    defined($opt_m) || defined($opt_o) || defined($opt_p) ||
	    defined($opt_r) ))
    { &usage_and_exit; }
$|=1;


# main
    {
    my($pkgsrcdir,$pkglint_flags);

    $pkglint_flags='-a -b -c -v';
    if ($opt_P)
	{ $pkgsrcdir=$opt_P; } # Check /etc/mk.conf for PKGSRCDIR
    else
	{ $pkgsrcdir=&set_pkgsrcdir; } # Check /etc/mk.conf for PKGSRCDIR

    if ($opt_r && !$opt_o && !$opt_m && !$opt_p)
	{ $opt_o=$opt_m=$opt_p=1; }
    if ($opt_o || $opt_m)
	{
	my(@baddist);

	@baddist=&scan_pkgsrc_distfiles_vs_md5($pkgsrcdir,$opt_o,$opt_m);
	if ($opt_r)
	    {
	    &safe_chdir("$pkgsrcdir/distfiles");
	    &verbose("Unlinking 'bad' distfiles\n");
	    foreach (@baddist)
		{ unlink($_); }
	    }
	}

    if ($opt_p)
	{
	if (!%pkg2dir)
	    { %pkg2dir=&scan_pkgsrc_makefiles($pkgsrcdir); }
	find(\&check_prebuilt_packages,"$pkgsrcdir/packages");
	if ($opt_r)
	    {
	    &verbose("Unlinking 'old' prebuiltpackages\n");
	    foreach (@oldprebuiltpackages)
		{ unlink($_); }
	    }
	}

    if ($opt_d)
	{ %pkg2dir=&scan_pkgsrc_makefiles($pkgsrcdir,1); }
    if ($opt_i)
	{
	my(@pkgs,$pkg);

	@pkgs=&list_installed_packages;
	if (!%pkg2dir)
	    { %pkg2dir=&scan_pkgsrc_makefiles($pkgsrcdir); }
	foreach $pkg ( @pkgs )
	    { &list_possible_versions($pkg); }
	}
    if ($opt_l)
	{ &pkglint_all_pkgsrc($pkgsrcdir,$pkglint_flags); }
    }
exit;

sub check_prebuilt_packages
    {
    if (/(.*)\.tgz$/)
	{
	if (!defined($pkg2dir{$1}))
	    {
	    print "$File::Find::dir/$_\n";
	    push(@oldprebuiltpackages,"$File::Find::dir/$_");
	    }
	}
    }

sub fail
    { print STDERR @_,"\n"; exit(3); }

# Given a package, strip version and report possible matches
#
sub list_possible_versions
    {
    my($pkg)=@_;
    my($pkgname,@maybe,$fail);

    if (!defined($pkg2dir{$pkg}))
	{
	$pkgname=$pkg;
	$pkgname =~ s/-[^-]+$/-/;
	foreach ( sort keys %pkg2dir )
	    {
	    if (/^$pkgname[0-9]/)
		{ push(@maybe,$_); }
	    }
	$_="Unknown package: '$pkg'";
	if( @maybe )
	    { $_.=" (Maybe @maybe)"; }
	else
	    { $_.=" ($pkgname)"; }
	print "$_\n";
	$fail=1;
	}
    $fail;
    }

# List (recursive) non directory contents of specified directory
#
sub listdir
    {
    my($base,$dir)=@_;
    my($thisdir,$entry);
    my(@list,@thislist);

    $thisdir=$base;
    if (defined($dir))
	{
	$thisdir.="/$dir";
	$dir.='/';
	}
    else
	{ $dir=''; }
    opendir(DIR,$thisdir) || &fail("Unable to opendir($thisdir): $!");
    @thislist=grep(substr($_,0,1) ne '.' && $_ ne 'CVS',readdir(DIR));
    closedir(DIR);
    foreach $entry (@thislist)
	{
	if (-d "$thisdir/$entry")
	    { push(@list,&listdir($base,"$dir$entry")); }
	else
	    { push(@list,"$dir$entry"); }
	}
    @list;
    }

# Use pkg_info to list installed packages
#
sub list_installed_packages
    {
    my(@pkgs);

    open(PKG_INFO,'pkg_info -a|') || &fail("Unable to run pkg_info: $!");
    while ( <PKG_INFO> )
	{ push(@pkgs,(split)[0]); }
    close(PKG_INFO);
    @pkgs;
    }

# List top level pkgsrc categories
#
sub list_pkgsrc_categories
    {
    my($pkgsrcdir)=@_;
    my(@categories);

    opendir(BASE,$pkgsrcdir) || die("Unable to opendir($pkgsrcdir): $!");
    @categories=grep(substr($_,0,1) ne '.' && -f "$pkgsrcdir/$_/Makefile",
							readdir(BASE));
    closedir(BASE);
    @categories;
    }

# Extract variable assignments from Makefile, include pkgname.
# Much unpalatable magic to avoid having to use make (all for speed)
#
sub parse_makefile
    {
    my($file)=@_;
    my($pkgname,%vars);
    my($key,$plus,$value);

    if (open(FILE,$file))
	{
	while( <FILE> )
	    {
	    s/#.*//;
	    if (/^\s*(\w+)(\+?)=\s+(\S*)/)
		{
		$key=$1;
		$plus=$2;
		$value=$3;
		if ($plus)
		    { $vars{$key}.="\n$value"; }
		else
		    { $vars{$key}=$value; }
		} 
	    }
	foreach $key ( keys %vars, keys %vars)
	    {
	    foreach $value ( keys %vars )
		{
		if ($vars{$key} =~ m#\${(\w+):S/(\w+)/(\w+)/}#)
		    {
		    my($var,$from,$to)=($1,$2,$3);

		    if (defined($vars{$var}))
			{
			$_=$vars{$var};
			s/$from/$to/;
			$vars{$key} =~ s#\${$var:S/$from/$to/}#$_#;
			}
		    }
		$vars{$key} =~ s/\$\{$value\}/$vars{$value}/g;
		}
	    }
	close(FILE);
	}
    if (defined($vars{'PKGNAME'}))
	{ $pkgname=$vars{'PKGNAME'}; }
    elsif (defined($vars{'DISTNAME'}))
	{ $pkgname=$vars{'DISTNAME'}; }
    if (defined($pkgname))
	{ return($pkgname,%vars); }
    else
	{ return(undef); }
    }

# Run pkglint on every pkgsrc entry
#
sub pkglint_all_pkgsrc
    {
    my($pkgsrcdir,$pkglint_flags)=@_;
    my($cat,$pkg,@categories,@output);

    @categories=&list_pkgsrc_categories($pkgsrcdir);
    foreach $cat ( sort @categories )
	{
	&safe_chdir("$pkgsrcdir/$cat");
	if (! opendir(CAT,'.'))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkg ( grep(substr($_,0,1) ne '.',readdir(CAT) ) )
	    {
	    if (-f "$pkg/Makefile")
		{
		if (!open(PKGLINT,"pkglint $pkglint_flags $pkg|"))
		    { &fail("Unable to run pkglint: $!"); }
		@output=grep(!/^OK:/ &&
			     !/^WARN: be sure to cleanup .* work before/ &&
			     !/^WARN: is it a new port/ &&
			     !/^\d+ fatal errors and \d+ warnings found/
			     ,<PKGLINT> );
		close(PKGLINT);
		if (@output)
		    {
		    print "===> $cat/$pkg\n",
			  "pkglint $pkglint_flags $pkg\n",
			  @output,"\n";
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
    my($dir)=@_;

    if (! chdir($dir))
	{ &fail("Unable to chdir($dir): $!"); }
    }

# Generate pkgname->category/pkg mapping, optionally check DEPENDS
#
sub scan_pkgsrc_makefiles
    {
    my($pkgsrcdir,$check_depends)=@_;
    my($cat,@categories,$pkg,$pkgname);
    my(%pkg2dir,%depends);

    @categories=&list_pkgsrc_categories($pkgsrcdir);
    &verbose("Scanning pkgsrc Makefiles: ".'_'x@categories."\b"x@categories);
    foreach $cat ( sort @categories )
	{
	if (! opendir(CAT,"$pkgsrcdir/$cat"))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkg ( grep(substr($_,0,1) ne '.',readdir(CAT) ) )
	    {
	    my(%vars);
	    ($pkgname,%vars)=&parse_makefile("$pkgsrcdir/$cat/$pkg/Makefile");
	    if ($pkgname)
		{
		$pkg2dir{$pkgname}="$cat/$pkg";
		if (defined($vars{'DEPENDS'}))
		    { $depends{$pkgname}=$vars{'DEPENDS'}; }
		}
	    }
	close(CAT);
	&verbose('.');
	}
    &verbose(' (',scalar(keys %pkg2dir)," packages)\n");

    if ($check_depends)
	{
	foreach $pkg ( sort keys %depends )
	    {
	    my($err);
	    foreach (split("\n",$depends{$pkg}))
		{
		s/:.*// || next;
		if (!defined($pkg2dir{$_}))
		    {
		    if (!defined($err))
			{ print "DEPENDS errors for $pkg2dir{$pkg}:\n"; }
		    $err=1;
		    print "\t";
		    &list_possible_versions($_);
		    }
		}
	    }
	}
    %pkg2dir;
    }

# Extract all md5 entries, then verify contents of distfiles
#
sub scan_pkgsrc_distfiles_vs_md5
    {
    my($pkgsrcdir,$check_unref,$check_md5)=@_;
    my($cat,@categories,$pkg);
    my(%distfiles,%md5,@distwarn,$file,$numpkg);
    my(@distfiles,@bad_distfiles);

    @categories=&list_pkgsrc_categories($pkgsrcdir);

    &verbose("Scanning pkgsrc md5s: ".'_'x@categories."\b"x@categories);
    $numpkg=0;
    foreach $cat ( sort @categories )
	{
	if (! opendir(CAT,"$pkgsrcdir/$cat"))
	    { die("Unable to opendir($pkgsrcdir/$cat): $!"); }
	foreach $pkg ( grep(substr($_,0,1) ne '.',readdir(CAT) ) )
	    {
	    if (open(MD5,"$pkgsrcdir/$cat/$pkg/files/md5"))
		{
		++$numpkg;
		while( <MD5> )
		    {
		    if (m/^MD5 \(([^\)]+)\) = (\S+)/)
			{
			if (!defined($distfiles{$1}))
			    {
			    $distfiles{$1}="$cat/$pkg";
			    $md5{$1}=$2;
			    }
			elsif( $md5{$1} ne $2 )
			    {
			    push(@distwarn,"md5 mismatch between '$1' in ".
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
	    { push(@bad_distfiles,$file); }
	else
	    { push(@distfiles,$file); }
	}
    if ($check_unref && @bad_distfiles)
	{
	&verbose(scalar(@bad_distfiles),
			" unreferenced file(s) in '$pkgsrcdir/distfiles':\n");
	print join("\n",sort @bad_distfiles),"\n";
	}
    if ($check_md5)
	{
	if (@distwarn)
	    { &verbose(@distwarn); }
	&verbose("md5 mismatches\n");
	@distfiles=sort @distfiles;
	&safe_chdir("$pkgsrcdir/distfiles");
	open(MD5,"md5 @distfiles|") || &fail("Unable to run md5: $!");
	while (<MD5>)
	    {
	    if (m/^MD5 \(([^\)]+)\) = (\S+)/)
		{
		if ($md5{$1} ne 'IGNORE' && $md5{$1} ne $2)
		    {
		    print $1,"\n";
		    push(@bad_distfiles,$1);
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

    $pkgsrcdir='/usr/pkgsrc';
    if (open(MK_CONF,'/etc/mk.conf'))
	{
	while (<MK_CONF>)
	    {
	    if( /PKGSRCDIR\s*=\s*(\S+)/ )
		{ $pkgsrcdir=$1; last; }
	    }
	close(MK_CONF);
	}
    $pkgsrcdir;
    }

sub usage_and_exit
    {
    print "Usage: lintpkgsrc [opts]
opts:	-d : Check each Makefile's 'DEPENDS' matches current pkgsrc versions.
	-h : This help.
	-i : Check versions of installed packages against pkgsrc.
	-l : Run pkglint on every package in pkgsrc.
	-m : Report md5 mismatches for files in 'distfiles'.
	-o : Report old/obsolete 'distfiles' (not referenced by any md5).
	-p : Report old/obsolete prebuilt packages (in PKGSRCDIR/packages/...)
	-r : Remove any 'bad' distfiles (Without -m, -o, or -p, implies all).

If pkgsrc is not in /usr/pkgsrc, set PKGSRCDIR in /etc/mk.conf
";
    exit;
    }

sub verbose
    { print STDERR @_; }
