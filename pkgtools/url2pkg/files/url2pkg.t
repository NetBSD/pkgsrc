# -*- perl -*-
# $NetBSD: url2pkg.t,v 1.6 2019/08/18 18:02:48 rillig Exp $

require "url2pkg.pl";

use Test::More;

use strict;
use warnings;

sub test_lines_add_vars__simple() {
	my $lines = [];

	lines_add_vars($lines, [
		var("1", "=", "one"),
		var("6", "=", "six"),
	]);

	is_deeply($lines, [
		"1=\tone",
		"6=\tsix",
		"",
	]);
}

sub test_lines_add_vars__alignment() {
	my $lines = [];

	lines_add_vars($lines, [
		var("short", "=", "value"),
		var("long_name", "=", "value # comment"),
	]);

	is_deeply($lines, [
		"short=\t\tvalue",
		"long_name=\tvalue # comment",
		"",
	]);
}

sub test_lines_add_vars__operators() {
	my $lines = [];

	lines_add_vars($lines, [
		var("123456", "+=", "value"),
	]);

	is_deeply($lines, [
		"123456+=\tvalue",
		"",
	]);
}

sub test_lines_append__not_found() {
	my $lines = [];

	lines_append($lines, "VARNAME", "value");

	is_deeply($lines, []);
}

sub test_lines_append__only_comment() {
	my $lines = ["VARNAME=\t\t\t# none"];

	lines_append($lines, "VARNAME", "value");

	is_deeply($lines, ["VARNAME=\t\t\tvalue # none"]);
}

sub test_lines_append__value_with_comment() {
	my $lines = ["VARNAME=\tvalue # comment"];

	lines_append($lines, "VARNAME", "appended");

	is_deeply($lines, ["VARNAME=\tvalue appended # comment"]);
}

sub test_lines_append__value_without_comment() {
	my $lines = ["VARNAME+=\tvalue"];

	lines_append($lines, "VARNAME", "appended");

	is_deeply($lines, ["VARNAME+=\tvalue appended"]);
}

sub test_generate_initial_package_Makefile_lines__GitHub_archive() {
	my $url = "https://github.com/org/proj/archive/v1.0.0.tar.gz";

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

sub test_generate_initial_package_Makefile_lines__GitHub_release_containing_project_name() {
	my $url = "https://github.com/org/proj/releases/download/1.0.0/proj.zip";

	my @lines = generate_initial_package_Makefile_lines($url);

	is_deeply(\@lines, [
		"# \$" . "NetBSD\$",
		"",
		"DISTNAME=\tproj",
		"CATEGORIES=\tpkgtools",
		"MASTER_SITES=\t\${MASTER_SITE_GITHUB:=org/}",
		"GITHUB_RELEASE=\t1.0.0",
		"EXTRACT_SUFX=\t.zip",
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

sub test_generate_initial_package_Makefile_lines__GitHub_release_not_containing_project_name() {
	my $url = "https://github.com/org/proj/releases/download/1.0.0/data.zip";

	my @lines = generate_initial_package_Makefile_lines($url);

	is_deeply(\@lines, [
		"# \$" . "NetBSD\$",
		"",
		"GITHUB_PROJECT=\tproj",
		"DISTNAME=\tdata",
		"CATEGORIES=\tpkgtools",
		"MASTER_SITES=\t\${MASTER_SITE_GITHUB:=org/}",
		"GITHUB_RELEASE=\t1.0.0",
		"EXTRACT_SUFX=\t.zip",
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
	my $pkgsrcdir = $ENV{"PKGSRCDIR"} or die;
	chdir("$pkgsrcdir/pkgtools/url2pkg") or die;

	test_lines_add_vars__simple();
	test_lines_add_vars__alignment();
	test_lines_add_vars__operators();
	test_lines_append__not_found();
	test_lines_append__only_comment();
	test_lines_append__value_with_comment();
	test_lines_append__value_without_comment();
	test_generate_initial_package_Makefile_lines__GitHub_archive();
	test_generate_initial_package_Makefile_lines__GitHub_release_containing_project_name();
	test_generate_initial_package_Makefile_lines__GitHub_release_not_containing_project_name();

	done_testing();
}

test_all();
