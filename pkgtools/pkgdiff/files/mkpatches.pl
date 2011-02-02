#!@PERL5@
#
# $NetBSD: mkpatches.pl,v 1.14 2011/02/02 10:23:02 wiz Exp $
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
# Copyright (c) 2000, 2011 by Thomas Klausner <wiz@NetBSD.org>
#               2004 by Dieter Baron <dillo@NetBSD.org>
# All Rights Reserved.  Absolutely no warranty.
#

use Getopt::Std;
use Cwd;
use File::Spec;

my $patchdir;
my $old_patchdir;
my $wrkdir;
my %old_filename;
my %old_header;

# create patchdir, or empty it if already existing

sub create_patchdir {
    if (! -d $patchdir) {
	mkdir($patchdir, 0755);
    }
}

# read command line arguments

undef($opt_c);
undef($opt_h);
undef($opt_r);
undef($opt_v);

getopts('chrv');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-chv]
    -c   	commit -- clean up old patches backups
    -h   	show this help
    -r   	revert -- remove new patches, put old patches back
    -v   	verbose - list .orig files as processed
EOF
		exit 0;
};

# get WRKDIR

$wrkdir=`@MAKE@ show-var VARNAME=WRKDIR` or
    die ("can't find WRKDIR -- wrong dir?");
chomp($wrkdir);
$patchdir=`@MAKE@ show-var VARNAME=PATCHDIR` or
    die ("can't find PATCHDIR -- wrong dir?");
chomp($patchdir);

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

# get WRKSRC

$wrksrc=`@MAKE@ show-var VARNAME=WRKSRC` or 
    die ("can't find WRKSRC -- wrong dir?");
chomp($wrksrc);

move_away_old_patches();

analyze_old_patches();

chdir $wrksrc or die ("can't cd to WRKSRC ($wrksrc)");

# find files

open(HANDLE, "find ${wrkdir} -type f -name \\\*.orig |");

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
	$diff=`pkgdiff $old $new 2>&1`;
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
	$patch = `sed '/^\+\+\+/ q' $checkname`;
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
    $name =~ s,/,_,g;
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
}
