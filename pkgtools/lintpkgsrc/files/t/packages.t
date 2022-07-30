# $NetBSD: packages.t,v 1.1 2022/07/30 16:20:18 rillig Exp $

use strict;
use warnings;
use Capture::Tiny 'capture';
use Test;

BEGIN { plan tests => 1; }

$ENV{'TESTING_LINTPKGSRC'} = 'yes';
require('../lintpkgsrc.pl');

sub test_package_variables() {
	my $pkglist = PkgList->new();
	my $pkgbase_1_0 = $pkglist->add('pkgbase', '1.0');

	$pkgbase_1_0->var('NAME', 'value');

	ok($pkgbase_1_0->var('NAME'), 'value');
	ok($pkgbase_1_0->var('undefined'), undef);
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

test_package_variables();
test_store_order();
