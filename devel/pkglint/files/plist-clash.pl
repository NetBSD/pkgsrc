#!@PREFIX@/bin/perl
#
# $NetBSD: plist-clash.pl,v 1.1 1998/08/07 22:13:44 tsarna Exp $
#
# Scan all ports and look for filenames used by more than one port.
#

if(`uname -s` eq "FreeBSD"){
    $OS="FreeBSD";
    $PORTSDIR="/usr/ports";
}else{
    $OS="NetBSD";
    $PORTSDIR="@PORTSDIR@";
}

###########################################################################
sub read_plist
{
    local($pkg)=@_;
    local($base);

    $prefix="\$LOCALBASE";
    
    if(! -d $pkg){
	print "$pkg: no such dir\n";
	return;
    }

    open(M,"$pkg/Makefile") || die "Can't read $pkg/Makefile: $!\n";
    while(<M>){
	$prefix="\$X11BASE" if /USE_X11/;
	$prefix="\$X11BASE" if /USE_IMAKE/;
	$prefix=$1 if /^PREFIX\??=\s*(\S+)/;
    }
    close(M);

    # printf "%-40s prefix=%s\n","$pkg:",$prefix;

    # NetBSD may have more than one PLIST file
    opendir(D,"$pkg/pkg/.") || die "Can't readdir($pkg/pkg/.): $!\n";
    while($f=readdir(D)){
	if($f =~ /^PLIST/){
	    next if $f=~/.orig$/;
	    
	    # printf("%-40s PLIST=$f\n","",$f);

	    open(P,"$pkg/pkg/$f") or die "Can't read $pkg/pkg/$f: $!\n";
	    while(<P>){
		next if /^@/;
		chomp;

		# strip .gz off manpages - handled via MANZ
		s/.gz$// if /^man/;

		($p) = $pkg =~ m@$PORTSDIR/(.+)@;
		if(0 and $F{"$prefix/$_"}){
		    print "$prefix/$_ already used by ",$F{"$prefix/$_"},"\n";
		}
		$F{"$prefix/$_"} .= " $p";
	    }
	    close(P);
	}
    }
    closedir(D);
}


###########################################################################
# M A I N
###########################################################################

if($#ARGV < 0){
    die "Usage: $0 portsdir1 ...\n";
}

# loop to parse all PLIST files
foreach $pkg (@ARGV){
    print "===> $pkg\n";
    &read_plist($pkg);
}

# Output diplicates
foreach $file (sort keys %F){
    $pkgs=$F{$file};
    $pkgs=~s/^\s+//g;

    # clean up duplicates (e.g. via PLIST-*)
    undef %pF;
    foreach $p (split(/ /,$pkgs)){
	$pF{$p}=1;
    }
    @pkgs=sort keys %pF;

    $n=$#pkgs+1;
    if($n>1){
	print "$n for $file: ",join(", ",@pkgs),"\n";
    }
}
