#!@PERL5@
#
# $NetBSD: mkpatches.pl,v 1.11 2004/10/10 09:56:37 dillo Exp $
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
# Copyright (c) 2000 by Thomas Klausner <wiz@netbsd.org>
#               2004 by Dieter Baron <dillo@netbsd.org>
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
    if ( -d $patchdir ) {
	unlink "$patchdir/*";
    } else {
	mkdir($patchdir, 0755);
    }
}

# read command line arguments

undef($opt_d);
undef($opt_h);
undef($opt_v);

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

$wrkdir=`@MAKE@ show-var VARNAME=WRKDIR` or
    die ("can't find WRKDIR -- wrong dir?");
chomp($wrkdir);
$old_patchdir=`@MAKE@ show-var VARNAME=PATCHDIR` or
    die ("can't find PATCHDIR -- wrong dir?");
chomp($old_patchdir);

if ($opt_d) {
    $patchdir = cwd()."/$opt_d";
} 
else {
    $patchdir="$wrkdir"."/.newpatches";
}

create_patchdir();

# get WRKSRC

$wrksrc=`@MAKE@ show-var VARNAME=WRKSRC` or 
    die ("can't find WRKSRC -- wrong dir?");
chomp($wrksrc);

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
    $new = File::Spec->abs2rel( $complete, $wrksrc );
    $old = File::Spec->abs2rel( $path, $wrksrc );
    if ( -f $complete ) {
	$patchfile = patch_name($new);
	if ($opt_v) {
	    print "$patchfile -> $complete\n";
	}
	$diff=`pkgdiff $old $new`;
	if ( $? ) {
	    print "$old: $diff";
	}
	if ( "$diff" eq "" ) {
	    print ("$new and $old don't differ\n");
	} else {
	    make_patch($old, $new, $patchfile, $diff);
	}
    } else {
	print ("$new doesn't exist, though $old does\n");
    }
}

sub analyze_old_patches 
{
    my $filename;
    my $patch;
    my $name;

    %old_header = ();
    %old_filename = ();

    open(HANDLE, "ls $old_patchdir/patch-* 2>/dev/null |");

    while ($filename = <HANDLE>) {
	chomp $filename;
	$patch = `sed '/^\+\+\+/ q' $filename`;
	if (!($patch =~ m/^\+\+\+ ([^\t\n]*)(\n$|\t)/m)) {
	    warn "cannot extract filename from patch $filename";
	    next;
	}
	$name = $1;
	$patch =~ s/\n--- .*/\n/s;
	$old_header{$name} = $patch;
	$filename =~ s!.*/!!;
	$old_filename{$name} = $filename;
    }

    close(HANDLE);
}


sub patch_name # filename
{
    my $name = shift;
    my ($pname, $l);

    if (defined($old_filename{$name})) {
	return $old_filename{$name};
    }

    for ($l=0; ; $l++) {
	$pname = 'patch-' . ("aa" .. "zz")[$l];
	if (! -f "$old_patchdir/$pname" and ! -f "$patchdir/$pname") {
	    return $pname;
	}
    }
}


sub make_patch # new old patchfile diff
{
    my ($old, $new, $patchfile, $diff) = @_;

    if (defined($old_header{$new})) {
	$diff =~ s/^.*\n(--- )/$1/s;
	$diff = $old_header{$new} . $diff;
    }

    open(HANDLE, "> $patchdir/$patchfile");
    print HANDLE $diff;
    close(HANDLE);
}
