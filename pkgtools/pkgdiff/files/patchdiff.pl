#!@PERL5@
#
# $NetBSD: patchdiff.pl,v 1.13 2011/02/02 10:23:02 wiz Exp $
#
# patchdiff: compares a set of patches in the patch dir with their predecessors
#
# Copyright (c) 2000, 2011 by Dieter Baron <dillo@giga.or.at> and
#                             Thomas Klausner <wiz@NetBSD.org>  
# All Rights Reserved.  Absolutely no warranty.  

use Getopt::Std;
use Cwd;
use File::Spec;

my $patchdir, $patchdir;
my $wrkdir, $thisdir;
my %orig, %new;

sub getfilename {
    my $fname=shift;
    local $_;
    local *handle;
    open(handle, $fname);
    while (<handle>) {
	next unless m/^\+\+\+[	 ]([^ 	]*)/;
	close(handle);
	$_ = $1;
	chomp();
	s/^\.\///; # ignore leading "./", if any.
	return $_;
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
	$$hash{$temp}=File::Spec->abs2rel($_, $thisdir);
     }
     close(handle);
}

getopts('h');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog
EOF
		exit 0;
};

%orig=();
%new=();
$thisdir=cwd();
chomp($thisdir);
$patchdir=`@MAKE@ show-var VARNAME=PATCHDIR` or
    die ("can't find PATCHDIR -- wrong dir?");
chomp($patchdir);

if ( ! -d $patchdir) {
    print "No patches found (directory $patchdir not found)\n";
    exit(0);
}

open(HANDLE, "find ${patchdir} -type f -name \\\*.orig |");

foreach (sort <HANDLE>) {
    $orig = $_;
    chomp($orig);
    $new = $orig;
    $new =~ s/.orig$//;

    if (! -f "$new") {
	print "File $new removed\n";
    } else {
#	system("diff",$orig{$patch},$new{$patch});
	$diff=`diff $orig $new`;
	# the following regex try to eliminate uninteresting differences
	# The general structure of the diffs-to-be-removed is:
	# 25c25
	# < --- something.orig 2008-08-08 08:08
	# ---
	# > --- something.orig 2008-08-08 18:08
	#
	# In particular, remove hunks with:
	# . NetBSD RCS Id tag differences
	$diff=~s/^[\d,]+c[\d,]+\n..\$[N]etBSD.*\$\n---\n..\$[N]etBSD.*\$\n//m;
	# . the name of the input file changed
	#   (if the name of the output file has changed, patches
	#    won't get matched up anyway)
	# . time of the input and/or output file changed
	# . line numbers changed
	$diff=~s/^[\d,]+c[\d,]+\n(?:.\s---\s(:?\S+).*\n)?(?:.\s\+\+\+\s(\S+).*\n)?(?:.\s@@\s(?:.*)\s@@.*\n)?---\n(?:.\s---\s\S+.*\n)?(?:.\s\+\+\+\s\S+.*\n)?(?:.\s@@\s.*\s@@.*\n)?//m;
	# . only line numbers changed
	$diff=~s/^[\d,]+c[\d,]+\n.\s@@\s.*\s@@.*\n---\n.\s@@\s.*\s@@.*\n//mg;
	if ($diff) {
	    if (! -s $orig) {
		print "New file $new\n";
	    } else {
		print "Comparing $orig to $new\n$diff";
	    }
	} else {
	    # restore previous version to get rid of uninteresting diffs
	    rename "$orig", "$new";
	}
    }
}
