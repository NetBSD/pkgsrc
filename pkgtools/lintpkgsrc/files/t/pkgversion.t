# $NetBSD: pkgversion.t,v 1.8 2022/08/03 22:03:43 rillig Exp $

use strict;
use warnings;
use IO::Null;
use Test;

BEGIN { plan tests => 6, onfail => sub { die } }

require('../lintpkgsrc.pl');

ok(pkgversioncmp('3.4', '<', '3.4'), '');
ok(pkgversioncmp('3.4', '<=', '3.4'), 1);
ok(pkgversioncmp('3.4', '>=', '3.4.0.0.0'), 1);
ok(pkgversioncmp('3.4nb13', '>=', '3.4'), 1);
ok(pkgversioncmp('3.4nb13', '<', '3.4'), '');
ok(pkgversioncmp('3.4nb13', '>', '3.4nb5'), 1);
ok(pkgversioncmp('1.1ab', '>', '1.1aa'), 1);
ok(pkgversioncmp('1.1ab', '<=', '1.1.1.2'), 1);
ok(pkgversioncmp('1.1ab', '>=', '1.1.1.2'), 1);

ok(pkgversioncmp('1nb1', '<', '1.0.0.0.0.0.0.1'), 1);
ok(pkgversioncmp('1.0', '<', '1nb1'), 1);

# See pkgtools/pkglint/files/pkgver/vercmp_test.go.
my @split_version_tests = (
    [ "5.0", [ [ 5, 0, 0 ], 0 ] ],
    [ "5.0nb5", [ [ 5, 0, 0 ], 5 ] ],
    [ "0.0.1-SNAP", [ [ 0, 0, 0, 0, 1, 0, 19, 0, 14, 0, 1, 0, 16 ], 0 ] ],
    [ "1.0alpha3", [ [ 1, 0, 0, -3, 3 ], 0 ] ],
    [ "1_0alpha3", [ [ 1, 0, 0, -3, 3 ], 0 ] ],
    [ "2.5beta", [ [ 2, 0, 5, -2 ], 0 ] ],
    [ "20151110", [ [ 20151110 ], 0 ] ],
    [ "0", [ [ 0 ], 0 ] ],
    [ "nb1", [ [], 1 ] ],
    [ "1.0.1a", [ [ 1, 0, 0, 0, 1, 0, 1 ], 0 ] ],
    [ "1.1.1dnb2", [ [ 1, 0, 1, 0, 1, 0, 4 ], 2 ] ],
    [ "1.0.1z", [ [ 1, 0, 0, 0, 1, 0, 26 ], 0 ] ],
    [ "0pre20160620", [ [ 0, -1, 20160620 ], 0 ] ],
    [ "3.5.DEV1710", [ [ 3, 0, 5, 0, 0, 4, 0, 5, 0, 22, 1710 ], 0 ] ],
);

foreach my $test (@split_version_tests) {
	my ($version, $expected) = @$test;
	my @actual = split_pkgversion($version);
	my @expected = ($expected->[1]);
	push(@expected, @{$expected->[0]});
	ok("$version: " . join(',', @actual), "$version: " . join(',', @expected));
}

# See pkgtools/pkglint/files/pkgver/vercmp_test.go.
my $versions = [
    [ "0pre20160620" ],
    [ "0" ],
    [ "nb1" ],
    [ "0.0.1-SNAPSHOT" ],
    [ "1.0alpha" ],
    [ "1.0alpha3" ],
    [ "1", "1.0", "1.0.0" ],
    [ "1.0nb1" ],
    [ "1.0nb2", "1_0nb2" ],
    [ "1.0.aa" ],
    [ "1.0.a1" ],
    [ "1.0.k" ],
    [ "1.0.1a" ],
    [ "1.0.1z" ],
    [ "1.0.11", "1.0k" ],
    [ "2.0pre", "2.0rc" ],
    [ "2.0", "2.0pl" ],
    [ "2.0.1nb4" ],
    [ "2.0.1nb17" ],
    [ "2.5beta" ],
    [ "5.0" ],
    [ "5.0nb5" ],
    [ "5.5", "5.005" ],
    [ "2021.06.17", "2021.6.17" ],
    [ "2021.12.01", "2021.12.1" ],
    [ "20151110" ],
];

my $prev = $Test::TESTOUT;
$Test::TESTOUT = IO::Null->new;
for (my $i = 0; $i < $#{$versions}; $i++) {
	for (my $j = 0; $j < $#{$versions}; $j++) {
		foreach my $vi (@{$versions->[$i]}) {
			foreach my $vj (@{$versions->[$j]}) {
				my $actual = pkgversioncmp($vi, '<', $vj) ? '<'
				    : pkgversioncmp($vi, '<=', $vj) ? '=='
				    : '>';
				my $expected = $i < $j ? '<'
				    : $i == $j ? '=='
				    : '>';
				ok("$vi $actual $vj", "$vi $expected $vj");
			}
		}
	}
}
$Test::TESTOUT = $prev;
