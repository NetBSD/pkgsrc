#!@PERL@

# $NetBSD: add_todo.pl,v 1.1.1.1 2009/08/30 10:40:34 wiz Exp $

# TODO:
# fix adding entry after last one (currently broken)
# check if package was removed
# check if package was downgraded (e.g. oto)
# allow multiple command line arguments

use strict;
use Getopt::Std;
use pkgsrc::Dewey;

use constant regex_pkgname      => qr"^(.*)-(\d[^-]*)$";

my ($comment, $entry, $grep_result, $newname, $newpkg, $newprinted,
    $newversion, %opt, $verbose);

my $PKGSRCDIR = "@PKGSRCDIR@";
my $input = "$PKGSRCDIR/doc/TODO";
my $wipinput = "$PKGSRCDIR/wip/TODO";
my $output = "$input.new";
my $changes = "$PKGSRCDIR/doc/CHANGES*";

getopts('fp:', \%opt);
#usage() if $opt{h};
if ($opt{p}) {
	$PKGSRCDIR = $opt{p};
}
$newpkg = shift(@ARGV);
$newpkg =~ regex_pkgname;
$newname = $1;
$newversion = $2;

# same code in obsolete_todo, keep in sync
sub update_done($$) {
	my ($file, $found_at_all, @files);
        my ($pkg, $ver) = @_;

	$found_at_all = 0;
	@files = glob($changes);
	# XXX: better way of handling +?
	$pkg =~ s/\+//g;
	# look in newest files first
	foreach $file (reverse(@files)) {
		open IN, $file;
		while (<IN>) {
			if (m/[ \/]$pkg version ([^ ]*) / or
			    (m/[ \/]$pkg to ([^ ]*) / and not m/Moved/) or
			    m/[ \/]$pkg-([0-9][^ -]*) /) {
				$found_at_all = 1;
				if (dewey_cmp($ver, "<=", $1)) {
					print STDERR "$pkg already at $1:\n";
					print STDERR "$file: $_";
					close(IN);
					return 1;
				}
			}
		}
		close(IN);
		# if found in latest CHANGES file, but no newer version,
		# assume the version to add is newer and don't check
		# older files
		if ($found_at_all) {
			last;
		}
	}
	return 0;
}

$newprinted = 0;
$verbose = 1;

$grep_result = qx/grep -e "[ \/]"$newname"[ -]" $changes/;
if (not $grep_result) {
	if (-d "$PKGSRCDIR/wip/$newname") {
		$input = $wipinput;
	}
	else {
		die "$newname not found in CHANGES* or wip\n";
	}
}

if (update_done($newname, $newversion)) {
	exit if not $opt{f};
	print STDERR "Ignored old entry (forced)\n";
}

open IN, $input or die "can't open input file ``$input''";
open OUT, ">$output" or die "can't open output file ``$output''";

while (<IN>) {
	if ($newprinted or not m/^	o /) {
		print OUT $_;
		next;
	}

	chomp();
	s/^\to //;
	if (m/([^ ]*)( .*)/) {
		$entry = $1;
		$comment = $2;
	} else {
		$entry = $_;
		$comment = "";
	}

	$entry =~ regex_pkgname;
	my ($entryname, $entryversion) = ($1, $2);

	# different package, alphabetically before new entry
	if ($newname gt $entryname) {
		print OUT "	o $entry$comment\n";
		next;
	}

	# different package, alphabetically after new entry -> add entry
	if ($newname lt $entryname) {
		print OUT "	o $newpkg\n";
		print OUT "	o $entry$comment\n";
		$newprinted = 1;
		next;
	}

	# $newname eq $entryname
	if (dewey_cmp($newversion, "<=", $entryversion)) {
		if ($opt{f}) {
			print STDERR "Replaced $entry (forced)\n" if $verbose;
			print OUT "	o $newpkg\n";
		} else {
			print STDERR "Newer or same version $entry already in TODO\n" if $verbose;
			print OUT "	o $entry$comment\n";
		}
	}
	else {
		if ($comment) {
			print STDERR "Keeping $entry because it has a comment:$comment\n";
			print OUT "	o $entry$comment\n";
			next;
		}

		print STDERR "Replaced $entry\n" if $verbose;
		print OUT "	o $newpkg\n";
	}

	$newprinted = 1;
}

close IN;
close OUT;

rename($output, $input) or die "can't rename $output to $input";
