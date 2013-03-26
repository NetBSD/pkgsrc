package PkgLint::Util;
#==========================================================================
# This package is a catch-all for subroutines that are not application-spe-
# cific. Currently it contains the boolean constants C<false> and C<true>,
# as well as a function to print text in a table format, and a function
# that converts an array into a hash. The latter is just for convenience
# because I don't know of a Perl operator similar to qw() that can be used
# for creating a hash.
#==========================================================================
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		assert
		false true dont_know doesnt_matter
		array_to_hash normalize_pathname print_table
	);
}

use enum qw(false true dont_know doesnt_matter);

sub assert($$) {
	my ($cond, $msg) = @_;
	my (@callers, $n);

	if (!$cond) {
		print STDERR ("FATAL: Assertion failed: ${msg}.\n");

		for ($n = 0; my @info = caller($n); $n++) {
			push(@callers, [$info[2], $info[3]]);
		}

		for (my $i = $#callers; $i >= 0; $i--) {
			my $info = $callers[$i];
			printf STDERR ("  line %4d called %s\n", $info->[0], $info->[1]);
		}
		exit(1);
	}
}

# Prints the C<$table> on the C<$out> stream. The C<$table> shall be an
# array of rows, each row shall be an array of cells, and each cell shall
# be a string.
sub print_table($$) {
	my ($out, $table) = @_;
	my (@width) = ();
	foreach my $row (@{$table}) {
		foreach my $i (0..$#{$row}) {
			if (!defined($width[$i]) || length($row->[$i]) > $width[$i]) {
				$width[$i] = length($row->[$i]);
			}
		}
	}
	foreach my $row (@{$table}) {
		my ($max) = ($#{$row});
		foreach my $i (0..$max) {
			if ($i != 0) {
				print $out ("  ");
			}
			print $out ($row->[$i]);
			if ($i != $max) {
				print $out (" " x ($width[$i] - length($row->[$i])));
			}
		}
		print $out ("\n");
	}
}

sub array_to_hash(@) {
	my ($result) = {};

	foreach my $arg (@_) {
		$result->{$arg} = 1;
	}
	return $result;
}

sub normalize_pathname($) {
	my ($fname) = @_;

	# strip "." path components
	$fname =~ s,^(?:\./)+,,;
	$fname =~ s,/(?:\./)+,/,g;
	$fname =~ s,/+,/,g;

	# strip intermediate "../.." path components
	while ($fname =~ s,/[^.][^/]*/[^.][^/]*/\.\./\.\./,/,) {
	}

	return $fname;
}
#== End of PkgLint::Util ==================================================

1;
