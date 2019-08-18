# -*- perl -*-
# $NetBSD: url2pkg.t,v 1.2 2019/08/18 13:50:32 rillig Exp $

require "url2pkg.pl";

use Test::More;

use strict;
use warnings;

sub test_add_section__simple() {
	my $lines = [];

	add_section($lines, [
		var("1", "=", "one"),
		var("6", "=", "six"),
	]);

	is_deeply($lines, [
		"1=\tone",
		"6=\tsix",
		"",
	]);
}

sub test_add_section__alignment() {
	my $lines = [];

	add_section($lines, [
		var("short", "=", "value"),
		var("long_name", "=", "value # comment"),
	]);

	is_deeply($lines, [
		"short=\t\tvalue",
		"long_name=\tvalue # comment",
		"",
	]);
}

sub test_add_section__operators() {
	my $lines = [];

	add_section($lines, [
		var("123456", "+=", "value"),
	]);

	is_deeply($lines, [
		"123456+=\tvalue",
		"",
	]);
}

sub test_var_append__not_found() {
	my $lines = [];

	update_var_append($lines, "VARNAME", "value");

	is_deeply($lines, []);
}

sub test_var_append__only_comment() {
	my $lines = ["VARNAME=\t\t\t# none"];

	update_var_append($lines, "VARNAME", "value");

	is_deeply($lines, ["VARNAME=\t\t\tvalue # none"]);
}

sub test_var_append__value_with_comment() {
	my $lines = ["VARNAME=\tvalue # comment"];

	update_var_append($lines, "VARNAME", "appended");

	is_deeply($lines, ["VARNAME=\tvalue appended # comment"]);
}

sub test_var_append__value_without_comment() {
	my $lines = ["VARNAME+=\tvalue"];

	update_var_append($lines, "VARNAME", "appended");

	is_deeply($lines, ["VARNAME+=\tvalue appended"]);
}

sub test_generate_initial_package_Makefile_lines__GitHub() {
	my $url = "https://github.com/org/proj/archive/v1.0.0.tar.gz";
	my $pkgsrcdir = $ENV{"PKGSRCDIR"} or die;
	chdir("$pkgsrcdir/pkgtools/url2pkg") or die;

	my @lines = generate_initial_package_Makefile_lines($url);

	is_deeply(\@lines, [
		"# \$" . "NetBSD\$",
		"",
		"GITHUB_PROJECT=\tproj",
		"DISTNAME=\tv1.0.0",
		"CATEGORIES=\tpkgtools",
		"MASTER_SITES=\t\${MASTER_SITE_GITHUB:=org/}",
		"DIST_SUBDIR=\t\${GITHUB_PROJECT}",
		"",
		"MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE",
		"HOMEPAGE=\thttps://github.com/org/proj/",
		"COMMENT=\tTODO: Short description of the package",
		"#LICENSE=\t# TODO: (see mk/license.mk)",
		"",
		"# url2pkg-marker (please do not remove this line.)",
		".include \"../../mk/bsd.pkg.mk\""
	]);
}

sub test_all() {
	test_add_section__simple();
	test_add_section__alignment();
	test_add_section__operators();
	test_var_append__not_found();
	test_var_append__only_comment();
	test_var_append__value_with_comment();
	test_var_append__value_without_comment();
	test_generate_initial_package_Makefile_lines__GitHub();

	done_testing();
}

test_all();
