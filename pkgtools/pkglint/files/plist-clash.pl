#! @PERL@
# $NetBSD: plist-clash.pl,v 1.5 2005/11/10 14:30:56 rillig Exp $
#
# Scan all PLIST files given on the command line and report all lines
# that appear more than once.

my %files = ();

sub read_PLIST($) {
	my ($fname) = @_;

	if (!open(F, "<", $fname)) {
		warn "$!\n";
		return undef;
	}

	my $lineno = 0;
	foreach my $line (<F>) {
		chomp($line);
		$lineno++;

		# Ignore comments and commands
		next if ($line =~ qr"^@");

		# Ignore filenames with embedded variables
		next if ($line =~ qr"\$");
		
		if ($line =~ qr"^[A-Za-z0-9].*") {
			if (!exists($files{$line})) {
				$files{$line} = [];
			}
			push(@{$files{$line}}, "$fname:$lineno");

		} else {
			warn("ERROR: $fname:$lineno: Unknown line type\n");
		}
	}
	close(F);
}

sub main() {
	if (@ARGV == 0) {
		die("usage: $0 <plist>...\n");
	}

	foreach my $plist (@ARGV) {
		read_PLIST($plist);
	}

	foreach my $file (sort keys %files) {
		my $srcs = $files{$file};
		if (@{$srcs} != 1) {
			foreach my $src (@{$srcs}) {
				print "$src: $file\n";
			}
		}
	}
}

main();
