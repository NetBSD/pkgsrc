#!@PREFIX@/bin/perl
#
# $NetBSD: mkpatches.pl,v 1.5 2001/05/24 17:02:44 abs Exp $
#
# mkpatches: creates a set of patches patch-aa, patch-ab, ...
#   in work/.newpatches by looking for *.orig files in and below
#   WRKDIR and comparing them to the corresponding changed file. All
#   files are then referrenced relative to WRKSRC.
#
#   It should be called from the packages directory,
#   e.g. /usr/pkgsrc/example/test
#
# Copyright (c) 2000 by Thomas Klausner <wiz@netbsd.org>
# All Rights Reserved.  Absolutely no warranty.
#

use Getopt::Std;
use Cwd;
use File::Spec;

my $patchdir;
my $wrkdir;
my $l=0;

# create patchdir, or empty it if already existing

sub create_patchdir {
    if ( -d $patchdir ) {
	unlink "$patchdir/*";
    } else {
	mkdir($patchdir, 0755);
    }
}

# read command line arguments

getopts('d:hv');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-d output-directory]
    -d dirname	directory to put the resulting patches into;
		defaults to \$WRKDIR/.newpatches
    -v   	verbose - list .orig files as processed
EOF
		exit 0;
};

# get WRKDIR

$wrkdir=`make show-var VARNAME=WRKDIR` or
    die ("can't find WRKDIR -- wrong dir?");
chomp($wrkdir);

if ($opt_d) {
    $patchdir = cwd()."/$opt_d";
} 
else {
    $patchdir="$wrkdir"."/.newpatches";
}

create_patchdir();

# get WRKSRC

$wrksrc=`make show-var VARNAME=WRKSRC` or 
    die ("can't find WRKSRC -- wrong dir?");
chomp($wrksrc);

chdir $wrksrc or die ("can't cd to WRKSRC ($wrksrc)");

# find files

open(handle, "find ${wrkdir} -type f -name \\\*.orig |");

# create patches

foreach (sort <handle>) {
    my $path, $complete;
    my $new, $old;
    chomp();
    $path = $_;
    $complete = $path;
    $complete =~ s/.orig$//;
    $new = File::Spec->abs2rel( $complete, $wrksrc );
    $old = File::Spec->abs2rel( $path, $wrksrc );
    if ( -f $complete ) {
	$patchfile = ("aa".."zz")[$l];
	$patchfile =~ s/^/patch-/;
	if ($opt_v) {
	    print "$patchfile -> $complete\n";
	}
	$diff=`pkgdiff $old $new`;
	if ( $? ) {
		print "$old\n$diff\n";
		exit 1;
	}
	if ( "$diff" eq "" ) {
		print ("$new and $old don't differ\n");
	} else {
		system("pkgdiff $old $new > $patchdir/$patchfile");
	}
    } else {
	print ("$new doesn't exist, though $old does");
    }
    $l++;
}
