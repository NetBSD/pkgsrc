#!@PERL@

# $NetBSD: obsolete_todo.pl,v 1.1.1.1 2009/08/30 10:40:34 wiz Exp $

# TODO:
# check if package was removed

use strict;
use pkgsrc::Dewey;

my ($comment, $entry, $import, $newfound, $oldfound, $enteredos,
    $filever, $found, $name, @newlist, @oldlist, $pkg, $version, $verbose);

my $PKGSRCDIR = "@PKGSRCDIR@";
my $input = "$PKGSRCDIR/doc/TODO";
my $output = "$PKGSRCDIR/doc/TODO.new";
my $changes = "$PKGSRCDIR/doc/CHANGES*";

# same code in add_todo, keep in sync
sub update_done($$) {
	my ($file, $found_at_all, @files);
        my ($pkg, $ver) = @_;

	$found_at_all = 0;
	@files = glob($changes);
	# XXX: better way of handling +?
	$pkg =~ s/\+//g;
	# look in newest files first
	foreach $file (reverse(@files)) {
		open SUBIN, $file;
		while (<SUBIN>) {
			if (m/[ \/]$pkg version ([^ ]*) / or
			    (m/[ \/]$pkg to ([^ ]*) / and not m/Moved/) or
			    m/[ \/]$pkg-([0-9][^ -]*) /) {
				$found_at_all = 1;
				if (dewey_cmp($ver, "<=", $1)) {
					print STDERR "$pkg already at $1:\n";
					print STDERR "$file: $_";
					close(SUBIN);
					return 1;
				}
			}
		}
		close(SUBIN);
		# if found in latest CHANGES file, but no newer version,
		# assume the version to add is newer and don't check
		# older files
		if ($found_at_all) {
			last;
		}
	}
	return 0;
}

open IN, $input or die "can't open TODO file";
open OUT, ">$output" or die "can't open TODO output file";

$verbose = 1;
$enteredos = 0;

MAIN: while (<IN>) {
	if ($enteredos == 2 or not m/^	o /) {
		if ($enteredos == 1) {
			$enteredos = 2;
		}
		print OUT $_;
		next;
	}

	$enteredos = 1;

	chomp();
	s/^	o //;
	if (m/(\S*)(\s.*)/) {
		$pkg = $1;
		$comment = $2;
	} else {
		$pkg = $_;
		$comment = "";
	}

	$pkg =~ m/(.*)-([^-]*)$/;
	$name = $1;
	$version = $2;

	if (update_done($name, $version)) {
		print STDERR "Removing entry for $name-$version\n";
		next MAIN;
	}

	print OUT "\to $pkg$comment\n";
}

close IN;
close OUT;

rename($output, $input) or die "can't rename $output to $input";
