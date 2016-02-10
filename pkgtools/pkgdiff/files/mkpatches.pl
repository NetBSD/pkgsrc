#!@PERL5@
#
# $NetBSD: mkpatches.pl,v 1.21 2016/02/10 16:00:10 wiz Exp $
#
# mkpatches: creates a set of patches patch-aa, patch-ab, ...
#   in work/.newpatches by looking for *.orig files in and below
#   WRKDIR and comparing them to the corresponding changed file. All
#   files are then referrenced relative to WRKSRC.
#
#   It should be called from the packages directory,
#   e.g. /usr/pkgsrc/example/test
#
#   It retains the naming and header (RCS Id and comment) from the
#   patches directory.
#
# Copyright (c) 2000, 2011, 2015, 2016 by Thomas Klausner <wiz@NetBSD.org>
#               2004 by Dieter Baron <dillo@NetBSD.org>
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

my $patchdir;
my $old_patchdir;
my $wrkdir;
my $wrksrc;
my %old_filename;
my %old_header;

# create patchdir, or empty it if already existing

sub create_patchdir {
    if (! -d $patchdir) {
	mkdir($patchdir, 0755);
	if (-d $origpatchdir && "$origpatchdir" != "$patchdir") {
	    system("cp", "$origpatchdir/p*", "$patchdir");
	}
    }
}

sub get_variable {
    my ($variable) = shift;
    my ($value);

    $value = `@MAKE@ show-var VARNAME=$variable`;
    if (${^CHILD_ERROR_NATIVE} == 0) {
	chomp($value);
	return $value;
    }
    die("error executing \"make show-var VARNAME=$variable\": returned with exit code " . (${^CHILD_ERROR_NATIVE} >> 8));
}
    
# read command line arguments

undef($opt_c);
undef($opt_D);
undef($opt_d);
undef($opt_h);
undef($opt_r);
undef($opt_v);
undef($opt_w);

getopts('cDd:hrvw');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-hvw] [-c | -r] [-D | -d dir]
    -c   	commit -- clean up old patches backups
    -d dir   	create patches in this directory
    -D   	create patches in \$WRKDIR/.newpatches
    -h   	show this help
    -r   	revert -- remove new patches, put old patches back
    -v   	verbose - list .orig files as processed
    -w   	look for changes in \$WRKDIR instead of \$WRKSRC
EOF
		exit 0;
};

if ($opt_d && $opt_D) {
    print STDERR "-D and -d conflict, choose one\n";
    exit 1;
}

# get some pkgsrc variables

$wrksrc = get_variable("WRKSRC");
$wrkdir = get_variable("WRKDIR");
$origpatchdir = get_variable("PATCHDIR");

if ($opt_D) {
    $patchdir = "$wrkdir/.newpatches";
} elsif ($opt_d) {
    if (-d "/$opt_d") {
	$patchdir = $opt_d;
    } else {
	my $pwd = cwd();
	chomp($pwd);
	$patchdir = "$pwd/$opt_d";
    }
} else {
    $patchdir = $origpatchdir;
}

if ($opt_c) {
    open(HANDLE, "find ${patchdir} -type f -name \\\*.orig |");
    foreach (<HANDLE>) {
	chomp;
	unlink $_;
    }
    exit 0;
}

if ($opt_r) {
    open(HANDLE, "find ${patchdir} -type f -name \\\*.orig |");
    foreach (<HANDLE>) {
	chomp;
	my $orig = $_;
	my $new = $_;
	$new =~ s/.orig$//;
	rename $orig, $new;
	if (! -s $new) {
	    unlink $new;
	}
    }
    exit 0;
}

create_patchdir();

move_away_old_patches();

analyze_old_patches();

chdir $wrksrc or die ("can't cd to WRKSRC ($wrksrc)");

# find files

if ($opt_w) {
    open(HANDLE, "find ${wrkdir} -type f -name \\\*.orig |");
} else {
    open(HANDLE, "find ${wrksrc} -type f -name \\\*.orig |");
}

# create patches

foreach (sort <HANDLE>) {
    my ($path, $complete);
    my ($new, $old);
    chomp();
    $path = $_;
    $complete = $path;
    $complete =~ s/.orig$//;
    $new = File::Spec->abs2rel($complete, $wrksrc);
    $old = File::Spec->abs2rel($path, $wrksrc);
    if (-f $complete) {
	$patchfile = patch_name($new);
	if ($opt_v) {
	    print "$patchfile -> $complete\n";
	}
	$diff=`@PREFIX@/bin/pkgdiff "$old" "$new" 2>&1`;
	if ($?) {
	    print "$old: $diff";
	}
	make_patch($old, $new, $patchfile, $diff);
    } else {
	print ("$new doesn't exist, though $old does\n");
    }
}

sub analyze_old_patches 
{
    my $filename;
    my $origfilename;
    my $patch;
    my $name;
    my $checkname;

    %old_header = ();
    %old_filename = ();

    open(HANDLE, "ls $patchdir/patch-* 2>/dev/null |");

    while ($origfilename = <HANDLE>) {
	chomp $origfilename;
	next if not $origfilename =~ m/.orig$/;
	$filename = $origfilename;
	$filename =~ s/.orig$//;
	$checkname = $origfilename;
	if (! -s $checkname) {
	    $checkname = $filename;
	}
	$patch = `sed '/^\+\+\+/ q' "$checkname"`;
	if (!($patch =~ m/^\+\+\+ ([^\t\n]*)(\n$|\t)/m)) {
	    warn "cannot extract filename from patch $checkname";
	    next;
	}
	$name = $1;
	$name =~ s/^\.\///; # ignore leading "./", if any.
	$patch =~ s/\n--- .*/\n/s;
	$old_header{$name} = $patch;
	$filename =~ s!.*/!!;
	$old_filename{$name} = $filename;
    }

    close(HANDLE);
}

sub move_away_old_patches
{
    open(HANDLE, "ls $patchdir/patch-* 2>/dev/null |");

    while ($filename = <HANDLE>) {
	chomp $filename;
	next if $filename =~ m/.orig$/;
	if (-f "$filename" and not -f "$filename.orig") {
	    rename "$filename", "$filename.orig";
	}
    }
	
}

sub patch_name # filename
{
    my $name = shift;
    my ($pname, $l);

    if (defined($old_filename{$name})) {
	return $old_filename{$name};
    }

    $name =~ s,_,__,g;
    $name =~ s,[/\s],_,g;
    $name = "patch-$name";

    return $name;
}


sub make_patch # new old patchfile diff
{
    my ($old, $new, $patchfile, $diff) = @_;

    if ("$diff" eq "") {
	print "$old and $new don't differ\n";
	if (-f "$patchdir/$patchfile.orig") {
	    rename "$patchdir/$patchfile.orig", "$patchdir/$patchfile";
	}
    }
    if (not -f "$patchdir/$patchfile.orig") {
	system("touch", "$patchdir/$patchfile.orig");
    }
    if (defined($old_header{$new})) {
	$diff =~ s/^.*\n(--- )/$1/s;
	$diff = $old_header{$new} . $diff;
    }

    open(HANDLE, "> $patchdir/$patchfile");
    print HANDLE $diff;
    close(HANDLE);

    # check if the new patch is basically the same as the old one

    $diff=`diff $patchdir/$patchfile.orig $patchdir/$patchfile`;

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
	# all fine, keep diff
    } else {
	# restore previous version to get rid of uninteresting diffs
	rename "$patchdir/$patchfile.orig", "$patchdir/$patchfile";
    }

}
