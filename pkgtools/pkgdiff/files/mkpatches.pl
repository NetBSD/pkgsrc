#!@PREFIX@/bin/perl
#
# $NetBSD: mkpatches.pl,v 1.1.1.1 2000/06/28 01:42:42 wiz Exp $
#
# mkpatches: creates a set of patches patch-aa, patch-ab, ...
#   in work/.newpatches by looking for *.orig files in and below
#   WRKSRC and comparing them to the corresponding changed file. It
#   should be called from the packages directory,
#   e.g. /usr/pkgsrc/example/test
#
# Copyright (c) 2000 by Thomas Klausner <wiz@netbsd.org>
# All Rights Reserved.  Absolutely no warranty.
#

use Getopt::Std;
use Cwd;

my $patchdir;
my $wrkdir;
my $l=0;

# change to WRKSRC

sub goto_wrksrcdir {
    my $wrksrc;

    $wrksrc=`make show-var VARNAME=WRKSRC` or 
	die ("can't find WRKSRC -- wrong dir?");
    chomp($wrksrc);

    chdir $wrksrc or die ("can't cd to WRKSRC ($wrksrc)");
}

# create patchdir, or empty it if already existing

sub create_patchdir {
    if ( -d $patchdir ) {
	unlink "$patchdir/*";
    } else {
	mkdir($patchdir, 0755);
    }
}

# read command line arguments

getopts('d:h');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-d output-directory]
    -d dirname	directory to put the resulting patches into;
		defaults to \$WRKDIR/.newpatches
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

goto_wrksrcdir();
create_patchdir();

# find files

open(handle, "find . -type f -name \\\*.orig |");

# create patches

while(<handle>) {
    my $path, $complete;
    chomp();
    $path = $_;
    $path =~ s/^..//;
    $complete = $path;
    $complete =~ s/.orig$//;
    if ( -f $complete ) {
	$patchfile = ("aa".."zz")[$l];
	$patchfile =~ s/^/patch-/;
	system("pkgdiff $path $complete > $patchdir/$patchfile");
    } else {
	print ("$complete doesn't exist, though $path does");
    }
    $l++;
}
