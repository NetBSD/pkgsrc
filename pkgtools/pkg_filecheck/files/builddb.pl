#!@PREFIX@/bin/perl

#  $NetBSD: builddb.pl,v 1.1.1.1 2003/07/13 16:15:34 wiz Exp $
#
#  builddb -- build .byfile.db from tgz files or directory hierarchies.
#  Copyright (C) 2000, 2003 Dieter Baron
#
#  This file is part of img2eps, an image to EPS file converter.
#  The author can be contacted at <dillo@giga.or.at>
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in
#     the documentation and/or other materials provided with the
#     distribution.
#  3. The name of the author may not be used to endorse or promote
#     products derived from this software without specific prior
#     written permission.
# 
#  THIS SOFTWARE IS PROVIDED BY DIETER BARON ``AS IS'' AND ANY EXPRESS
#  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED.  IN NO EVENT SHALL DIETER BARON BE LIABLE FOR ANY
#  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
#  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
#  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
#  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
#  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

use strict;
use Getopt::Std;
use DB_File;

my $prg;
my $options = 'hvo:';
my $usage = '[-hv] [-o db-file] tar-file|directory ...';
my %opt;
my ($verbose, $dbfile);
my %db;
my ($file, $pkg, $opkg);

#
# defaults
#

$verbose = 0;
$dbfile = '/var/db/pkg/xdb.byfile.db';

#
# command line handling
#

($prg) = ($0 =~ /([^\/]+)$/);

getopts($options, \%opt);

if ($opt{h}) {
    print <<EOF;
usage: $prg $usage
  -h           display this help message
  -o DB-FILE   output to DB-FILE
  -v           verbose mode
EOF
    exit 0;
}

if (@ARGV == 0) {
    print STDERR "usage: $prg $usage\n";
    exit 1;
}

$verbose = $opt{v} if ($opt{v});
$dbfile = $opt{o} if ($opt{o});

#
# setup
#

tie %db, 'DB_File', $dbfile, O_RDWR|O_CREAT, 0666, $DB_BTREE
	or die "cannot open db `$dbfile': $!\n";

#
# process tar files
#

foreach $file (@ARGV) {
    if (-f $file) {
	unless (open LST, "tar -tzf $file |") {
	    warn "cannot list `$file': $!\n";
	    next;
	}
	
	($pkg) = ($file =~ m/([^\/]+)\.tgz$/);
    }
    elsif (-d $file) {
	$pkg = $file;

	$file = "`pwd`/$file" unless ($file =~ m!^/!);
	unless (open LST, "find $file -type f |") {
	    warn "cannot list `$file': $!\n";
	    next;
	}
    }
    else {
	warn "no such file or directory: `$file'";
	next;
    }
    
    while (<LST>) {
	chomp;
	if (exists($db{"$_\0"})) {
	    ($opkg = $db{"$_\0"}) =~ s/\0//;
	    warn "overwriting `$_' (old: $opkg, new: $pkg)\n";
	}
	print "$pkg: $_\n" if ($verbose);
	$db{"$_\0"} = "$pkg\0";
    }

    close LST;
}

#
# cleanup
#

untie %db;
