#!@PERL5@ -w

# $NetBSD: pkg_distinst.pl,v 1.2 2009/01/06 10:28:38 adrianp Exp $

use Data::Dumper;
use File::Basename;
use File::Find;
use Getopt::Long;
use strict;

my ($pkg_info, $pkgsrc, @pkg, @installed, $ipkg, $loc, @distfiles, $line);
my (@pdistfiles, %dupe, $distdir, @downloaded, $dl, @dltmp, $dir, $file);
my (@orphan, $found, $delete, $help);

# set some defaults
#
$pkgsrc = "";
$distdir = "";
$delete = 0;
$found = 0;
$help = 0;

GetOptions (	'pkgsrc=s' => \$pkgsrc, 
		'distdir=s' => \$distdir,
		'delete' => \$delete,
		'help' => \$help,
	);

if ($help == 1) {
	help();
	exit 0;
}

# check everything we need exists
#
if ($pkgsrc eq "") {
	$pkgsrc = "@PKGSRCDIR@";
}

if (! -d "$pkgsrc/pkgtools/pkglint") {
	print "ERROR: Unable to find $pkgsrc: $!\n";
	exit 1;
}

chdir("$pkgsrc/pkgtools/pkglint");
$pkg_info = `@MAKE@ show-var VARNAME=PKG_INFO_CMD`;
chomp($pkg_info);

if ($distdir eq "") {
	$distdir = `@MAKE@ show-var VARNAME=DISTDIR`;
	chomp($distdir);
}

if (! -d "$distdir") {
	print "ERROR: Unable to find $distdir: $!\n";
	exit 1;
}

# get a list of installed packages
#
open(PKG_INFO, "$pkg_info|");

while(<PKG_INFO>) {
	$line = $_;
	@pkg = split / /, $line;
	push(@installed, $pkg[0]);
}

close(PKG_INFO);

# get a list of distfiles for the installed packages
#
print "Gathering DISTFILES for installed packages";

foreach $ipkg (@installed) {

	$loc = `$pkg_info -Q PKGPATH $ipkg`;
	chomp($loc);

	if (! -d "$pkgsrc/$loc") {
		print "WARNING: Unable to find package $loc: $!\n";
	} else {
		chdir("$pkgsrc/$loc");

		$line = `@MAKE@ show-var VARNAME=DISTFILES`;
		chomp($line);

		if ($line ne "") {
			@pdistfiles = split / /, $line;
			push(@distfiles, @pdistfiles);
		}

		$line = `@MAKE@ show-var VARNAME=PATCHFILES`;
		chomp($line);

		if ($line ne "") {
			@pdistfiles = split / /, $line;
			push(@distfiles, @pdistfiles);
		}

		print ".";
	}
}

print "done\n";

# remove duplicates
#
%dupe = map { $_, 1 } @distfiles;
@distfiles = keys %dupe;

# get a list of downloaded DISTFILES in DISTDIR
#
find(\&dfile, $distdir);

# trim .cvsignore and CVS/*
#
foreach $dl (@downloaded) {
	$dir = dirname($dl);
	$file = basename($dir);
	if (-f $dl && $dl ne "$distdir/.cvsignore" && $file ne "CVS") {
		push(@dltmp, $dl);
	}
}

@downloaded = @dltmp;

# figure out what belongs and what doesn't
#
foreach $dl (@downloaded) {
	$file = basename($dl);

	foreach my $ipkg (@distfiles) {
		if ($file eq $ipkg) {
			$found = 1;
			last;
		}
	}

	if ($found == 0) {
		push(@orphan, $dl);
	} else {
		$found = 0;
	}
}

# Print the list of orphaned files
#
foreach $file (@orphan) {
	print "$file\n";
	if ($delete == 1) {
		unlink($file);
	}
}

exit 0;

#
# subs follow
#

sub dfile {
	push(@downloaded, $File::Find::name);
}

sub help {
	print "pkg_distinst [--pkgsrc <pkgsrc dir> | --distdir <distfiles dir> | --delete | --help]\n";
	print "\t --pkgsrc <pkgsrc dir>: Specify a pkgsrc directory to use.\n";
	print "\t\t This will default to \${PKGSRCDIR}\n";
	print "\t --distdir <distfiles dir>: Specify a distfiles directory to use.\n"; 
	print "\t\t This will default to \${DISTDIR}\n";
	print "\t --delete: Delete any orphaned files found.\n";
	print "\t\t Default is to display the list of files.\n";
	print "\t --help: You\'re looking at it\n";
}
