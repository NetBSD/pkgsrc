#!@PERL5@
#
# $NetBSD: patchdiff.pl,v 1.16 2016/02/10 16:00:10 wiz Exp $
#
# patchdiff: compares a set of patches in the patch dir with their predecessors
#
# Copyright (c) 2000, 2011 by Dieter Baron <dillo@giga.or.at> and
#                             Thomas Klausner <wiz@NetBSD.org>  
# Copyright (c) 2016 Thomas Klausner <wiz@NetBSD.org>  
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

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

getopts('Dd:h');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-D | -d dir]
    -D		look at patches in \$WRKDIR/.newpatches
    -d dir	look at patches in this directory
EOF
		exit 0;
};

%orig=();
%new=();
$thisdir=cwd();
chomp($thisdir);
$wrkdir=`@MAKE@ show-var VARNAME=WRKDIR` or
    die ("can't find WRKDIR -- wrong dir?");
chomp($wrkdir);
$origpatchdir=`@MAKE@ show-var VARNAME=PATCHDIR` or
    die ("can't find PATCHDIR -- wrong dir?");
chomp($origpatchdir);

if ($opt_D) {
    $patchdir = "$wrkdir/.newpatches";
} elsif ($opt_d) {
    if (-d "/$opt_d") {
	$patchdir = $opt_d;
    } else {
	$patchdir = "$thisdir/$opt_d";
    }
} else {
    $patchdir = $origpatchdir;
}

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
	$diff=`diff $orig $new`;
	if ($diff) {
	    if (! -s $orig) {
		print "New file $new\n";
	    } else {
		print "Comparing $orig to $new\n$diff";
	    }
	} else {
	    print "$orig and $new are the same";
	}
    }
}
