#!@PREFIX@/bin/perl
#
# $NetBSD: patchdiff.pl,v 1.1.1.1 2000/06/28 01:42:42 wiz Exp $
#
# patchdiff: compares a set of patches patch-aa, patch-ab, ... in
#   $WRKDIR/.newpatches in the with another set in patches.
#
# Copyright (c) 2000 by Dieter Baron <dillo@giga.or.at> and
#                       Thomas Klausner <wiz@netbsd.org>  
# All Rights Reserved.  Absolutely no warranty.  

use Getopt::Std;
use Cwd;

my $oldpatchdir, $newpatchdir;
my $wrkdir;
my %orig, %new;

# change to WRKDIR

sub goto_wrkdir {
    chdir $wrkdir or die ("can't cd to WRKDIR ($wrkdir)");
}

sub getfilename {
    my $fname=shift;
    local $_;
    local *handle;
    open(handle, $fname);
    while (<handle>) {
	next unless m/^\+\+\+ ([^	]*)/;
	close(handle);
	return $1;
     }
     close(handle);
     return undef;
}

sub putinhash {
    my $hash=shift;
    my $files=shift;
    my $temp;
    local *handle;
    open(handle, "ls $files|");
    while(<handle>) {
	chomp;
	$temp=getfilename($_);
	$$hash{$temp}=$_;
#	print "put in hash: $temp // $_";
     }
     close(handle);
}

getopts('d:h');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-d output-directory]
    -d dirname	directory to compare the patches in patches/ to;
		defaults to \$WRKDIR/.newpatches
EOF
		exit 0;
};

%orig=();
%new=();
$oldpatchdir=cwd();
chomp($oldpatchdir);
$oldpatchdir=$oldpatchdir."/patches";

$wrkdir=`make show-var VARNAME=WRKDIR` or 
    die ("can't find WRKDIR -- wrong dir?");
chomp($wrkdir);

if ($opt_d) {
    $newpatchdir = cwd()."/$opt_d";
} 
else {
    $newpatchdir="$wrkdir"."/.newpatches";
}

if ( ! -d $oldpatchdir) {
    print "No old patches found (directory $oldpatchdir not found)\n";
    exit(0);
}
if ( ! -d $newpatchdir ) {
    print "No new patches found (directory $newpatchdir not found)\n";
    exit(0);
}
putinhash(\%orig,"$oldpatchdir/patch-*");
putinhash(\%new,"$newpatchdir/patch-*");
foreach $patch (keys%orig) {
    print "Only in old: $orig{$patch} ($patch)\n" unless defined($new{$patch});
}
foreach $patch (keys%new) {
    if (defined($orig{$patch})) {
#	system("diff",$orig{$patch},$new{$patch});
	$diff=`diff $orig{$patch} $new{$patch}`;
	$diff=~s/^\dc\d\n..\$NetBSD.*\$\n---\n..\$NetBSD.*\$\n//m;
	$diff=~s/^\dc\d\n..\+\+\+.*\n---\n..\+\+\+.*\n//m;
	if ($diff) {
	     print "Comparing $orig{$patch} to $new{$patch}\n$diff";
	}
     } else {
	print "Only in new: $new{$patch} ($patch)\n" 
     }
}
