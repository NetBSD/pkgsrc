# $NetBSD: packages.t,v 1.5 2022/08/03 19:22:34 rillig Exp $

use strict;
use warnings;
use Capture::Tiny 'capture';
use Test;

BEGIN { plan tests => 11, onfail => sub { die } }

require('../lintpkgsrc.pl');

sub test_pkgver() {
	my $pkgver = PkgVer->new('base', '1.0nb4');

	ok($pkgver->pkg , 'base');
	ok($pkgver->ver , '1.0nb4');
	ok($pkgver->pkgname , 'base-1.0nb4');
}

sub test_package_variables() {
	my $pkglist = PkgList->new();
	my $pkgbase_1_0 = $pkglist->add('pkgbase', '1.0');

	$pkgbase_1_0->var('NAME', 'value');

	ok($pkgbase_1_0->var('NAME'), 'value');
	ok($pkgbase_1_0->var('undefined'), undef);

	my $pkgbase_2_0 = $pkglist->add('pkgbase', '2.0');
	my $pkgbase_1_5 = $pkglist->add('pkgbase', '1.5');
	my $pkgbase_1_10 = $pkglist->add('pkgbase', '1.10');

	$pkgbase_2_0->var('COMMENT', 'Version 2 of the package');

	ok($pkglist->pkgs('unknown-pkgbase'), undef);

	# The versions are sorted in decreasing alphabetical order.
	my $versions = join(', ', $pkglist->pkgs('pkgbase')->versions());
	ok($versions, '2.0, 1.5, 1.10, 1.0');

	# The versioned packages are sorted in decreasing alphabetical order.
	my @pkgvers = $pkglist->pkgver('pkgbase');
	ok(join(', ', map { $_->ver } @pkgvers), '2.0, 1.5, 1.10, 1.0');
	ok($pkgvers[0], $pkgbase_2_0);
	ok($pkgvers[3], $pkgbase_1_0);
}

# Demonstrate how the package data is stored in the cache file.
sub test_store_order() {
	my $pkglist = PkgList->new();

	my $pkgbase_1_0 = $pkglist->add('pkgbase', '1.0');
	my $pkgbase_1_3nb4 = $pkglist->add('pkgbase', '1.3nb4');
	my $pkgbase_1_15 = $pkglist->add('pkgbase', '1.15');

	my $stdout = capture {
		$pkglist->store();
	};

	# XXX: 1.3nb4 should be sorted before 1.15.
	# On the other hand, this is just an internal cache file format.
	ok($stdout, ''
	    . "package\tpkgbase\t1.0\n"
	    . "package\tpkgbase\t1.15\n"
	    . "package\tpkgbase\t1.3nb4\n");
}

test_pkgver();
test_package_variables();
test_store_order();
