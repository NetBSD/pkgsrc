# $NetBSD: packages.t,v 1.12 2022/08/11 07:18:47 rillig Exp $

use strict;
use warnings;
use File::Slurp 'read_file';
use File::Temp;
use Test;

BEGIN { plan tests => 30, onfail => sub { die } }

require('../lintpkgsrc.pl');

sub test_pkgver() {
	my $pkgver = PkgVer->new('base', '1.0nb4');

	ok($pkgver->pkgbase, 'base');
	ok($pkgver->pkgversion, '1.0nb4');
	ok($pkgver->pkgname, 'base-1.0nb4');
}

sub test_pkgs() {
	my $pkgs = Pkgs->new('base');

	ok($pkgs->pkgbase, 'base');

	$pkgs->add('base', '1.0nb4');

	ok(($pkgs->pkgver)[0]->pkgbase, 'base');
	ok(($pkgs->pkgver)[0]->pkgversion, '1.0nb4');

	$pkgs->add('base', '1.0nb20');

	# FIXME: The latest version is actually 1.0nb20, not 1.0nb4.
	ok($pkgs->latestver->pkgversion, '1.0nb4');
}

sub test_pkgdb() {
	my $pkgdb = PkgDb->new();

	ok(scalar $pkgdb->pkgvers_all, 0);
	ok(join(', ', map { $_->pkgname } $pkgdb->pkgvers_all), '');

	$pkgdb->add('base', '1.0');

	ok(scalar $pkgdb->pkgvers_all, 1);

	$pkgdb->add('other', '5.7');

	ok(scalar $pkgdb->pkgvers_all, 2);

	my $base_8_0 = $pkgdb->add('base', '8.0');

	ok(scalar $pkgdb->pkgvers_all, 3);
	ok($base_8_0->pkgname, 'base-8.0');

	my $actual = join(', ', map { $_->pkgname } $pkgdb->pkgvers_all);
	ok($actual, 'base-8.0, base-1.0, other-5.7');

	$actual = join(', ', map { $_->pkgname } $pkgdb->pkgvers_by_pkgbase('base'));
	ok($actual, 'base-8.0, base-1.0');

	$actual = join(', ', map { $_->pkgname } $pkgdb->pkgvers_by_pkgbase('unknown'));
	ok($actual, '');

	ok($pkgdb->pkgver('base', '1.0')->pkgname, 'base-1.0');
	ok($pkgdb->pkgver('unknown', '1.0'), undef);
	ok($pkgdb->pkgver('base', '3.0'), undef);

	ok(join(', ', map { $_->pkgbase } $pkgdb->pkgs), 'base, other');
	ok($pkgdb->pkgs('base')->pkgbase, 'base');
	ok($pkgdb->pkgs('unknown'), undef);
}

sub test_package_variables() {
	my $pkgdb = PkgDb->new();
	my $pkgbase_1_0 = $pkgdb->add('pkgbase', '1.0');

	$pkgbase_1_0->var('NAME', 'value');

	ok($pkgbase_1_0->var('NAME'), 'value');
	ok($pkgbase_1_0->var('undefined'), undef);

	my $pkgbase_2_0 = $pkgdb->add('pkgbase', '2.0');
	my $pkgbase_1_5 = $pkgdb->add('pkgbase', '1.5');
	my $pkgbase_1_10 = $pkgdb->add('pkgbase', '1.10');

	$pkgbase_2_0->var('COMMENT', 'Version 2 of the package');

	ok($pkgdb->pkgs('unknown-pkgbase'), undef);

	# The versions are sorted in decreasing alphabetical order.
	my $versions = join(', ', $pkgdb->pkgs('pkgbase')->versions());
	ok($versions, '2.0, 1.5, 1.10, 1.0');

	# The versioned packages are sorted in decreasing alphabetical order.
	my @pkgvers = $pkgdb->pkgvers_by_pkgbase('pkgbase');
	ok(join(', ', map { $_->pkgversion } @pkgvers), '2.0, 1.5, 1.10, 1.0');
	ok($pkgvers[0], $pkgbase_2_0);
	ok($pkgvers[3], $pkgbase_1_0);
}

# Demonstrate how the package data is stored in the cache file.
sub test_store_order() {
	my $pkgdb = PkgDb->new();

	my $pkgbase_1_0 = $pkgdb->add('pkgbase', '1.0');
	my $pkgbase_1_3nb4 = $pkgdb->add('pkgbase', '1.3nb4');
	my $pkgbase_1_15 = $pkgdb->add('pkgbase', '1.15');

	# Ensure that variables are stored in alphabetical order.
	$pkgbase_1_0->var('COMMENT', 'Version 1');
	$pkgbase_1_0->var('HOMEPAGE', 'https://example.org/pkgbase');
	$pkgbase_1_0->var('MAINTAINER', 'pkgsrc-users@NetBSD.org');
	$pkgbase_1_0->var('LICENSE', 'modified-bsd');

	$pkgbase_1_15->var('COMMENT', 'Version 1.15');

	my $tmpfile = File::Temp->new();
	store_pkgsrc_makefiles($pkgdb, $tmpfile->filename);
	my $stored = read_file($tmpfile->filename);

	# XXX: 1.3nb4 should be sorted before 1.15.
	# On the other hand, this is just an internal cache file format.
	ok($stored, ''
	    . "package\tpkgbase\t1.3nb4\n"
	    . "package\tpkgbase\t1.15\n"
	    . "var\tCOMMENT\tVersion 1.15\n"
	    . "package\tpkgbase\t1.0\n"
	    . "var\tCOMMENT\tVersion 1\n"
	    . "var\tHOMEPAGE\thttps://example.org/pkgbase\n"
	    . "var\tLICENSE\tmodified-bsd\n"
	    . "var\tMAINTAINER\tpkgsrc-users\@NetBSD.org\n"
	);
}

test_pkgver();
test_pkgs();
test_pkgdb();
test_package_variables();
test_store_order();
