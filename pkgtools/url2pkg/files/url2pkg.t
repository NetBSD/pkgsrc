# -*- perl -*-
# $NetBSD: url2pkg.t,v 1.13 2019/10/01 19:41:23 rillig Exp $

require "url2pkg.pl";

use Test::More;

use strict;
use warnings;

sub test_Lines_add_vars__simple() {
	my $lines = Lines->new();

	$lines->add_vars(
		var("1", "=", "one"),
		var("6", "=", "six"),
	);

	is_deeply($lines, [
		"1=\tone",
		"6=\tsix",
		"",
	]);
}

sub test_Lines_add_vars__alignment() {
	my $lines = Lines->new();

	$lines->add_vars(
		var("short", "=", "value"),
		var("long_name", "=", "value # comment"),
	);

	is_deeply($lines, [
		"short=\t\tvalue",
		"long_name=\tvalue # comment",
		"",
	]);
}

sub test_Lines_add_vars__operators() {
	my $lines = Lines->new();

	$lines->add_vars(
		var("123456", "+=", "value"),
	);

	is_deeply($lines, [
		"123456+=\tvalue",
		"",
	]);
}

sub test_Lines_add_vars__empty() {
	my $lines = Lines->new("# initial");

	$lines->add_vars();

	# No empty line is added.
	is_deeply($lines, [
		"# initial"
	]);
}

sub test_Lines_append__not_found() {
	my $lines = Lines->new();

	$lines->append("VARNAME", "value");

	is_deeply($lines, []);
}

sub test_Lines_append__only_comment() {
	my $lines = Lines->new("VARNAME=\t\t\t# none");

	$lines->append("VARNAME", "value");

	is_deeply($lines, ["VARNAME=\t\t\tvalue # none"]);
}

sub test_Lines_append__value_with_comment() {
	my $lines = Lines->new("VARNAME=\tvalue # comment");

	$lines->append("VARNAME", "appended");

	is_deeply($lines, ["VARNAME=\tvalue appended # comment"]);
}

sub test_Lines_append__value_without_comment() {
	my $lines = Lines->new("VARNAME+=\tvalue");

	$lines->append("VARNAME", "appended");

	is_deeply($lines, ["VARNAME+=\tvalue appended"]);
}

sub test_Lines_set__previously_with_comment() {
	my $lines = Lines->new("LICENSE=\t# TODO: see mk/license.mk");

	$lines->set("LICENSE", "\${PERL5_LICENSE}");

	is_deeply($lines, ["LICENSE=\t\${PERL5_LICENSE}"]);
}

sub test_Lines_set__overwrite_comment_with_comment() {
	my $lines = Lines->new("#LICENSE=\t# TODO: see mk/license.mk");

	$lines->set("#LICENSE", "\${PERL5_LICENSE}");

	is_deeply($lines, ["#LICENSE=\t\${PERL5_LICENSE}"]);
}

sub test_Lines_set__not_found() {
	my $lines = Lines->new("OLD_VAR=\told value # old comment");

	$lines->set("NEW_VAR", "new value");

	is_deeply($lines, ["OLD_VAR=\told value # old comment"]);
}

sub test_Lines_index() {
	my $lines = Lines->new("1", "2", "345");

	is($lines->index("1"), 0);
	is($lines->index("2"), 1);
	is($lines->index("345"), 2);
	is($lines->index("4"), 2);

	is($lines->index(qr"^(\d\d)\d$"), 2);
	is($lines->index(qr"^\d\s\d$"), -1);
	is($lines->index(qr"(\d)"), 0);
	is($1, undef);  # capturing groups do not work here
}

sub test_Lines_get() {
	my $lines = Lines->new(
		"VAR=value",
		"VAR=\tvalue # comment",
		"UNIQUE=\tunique"
	);

	is($lines->get("VAR"), "");     # too many values
	is($lines->get("ENOENT"), "");  # no value at all
	is($lines->get("UNIQUE"), "unique");
}

sub test_generate_initial_package_Makefile_lines__GitHub_archive() {
	my $url = "https://github.com/org/proj/archive/v1.0.0.tar.gz";

	my $lines = generate_initial_package_Makefile_lines($url);

	is_deeply($lines, [
		"# \$" . "NetBSD\$",
		"",
		"GITHUB_PROJECT=\tproj",
		"DISTNAME=\tv1.0.0",
		"PKGNAME=\t\${GITHUB_PROJECT}-\${DISTNAME:S,^v,,}",
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

	my $lines = generate_initial_package_Makefile_lines($url);

	is_deeply($lines, [
		"# \$" . "NetBSD\$",
		"",
		"GITHUB_PROJECT=\tproj",
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

	my $lines = generate_initial_package_Makefile_lines($url);

	is_deeply($lines, [
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

sub test_generate_initial_package_Makefile_lines__distname_version_with_v() {
	my $url = "https://cpan.example.org/Algorithm-CheckDigits-v1.3.2.tar.gz";

	my $lines = generate_initial_package_Makefile_lines($url);

	is_deeply($lines, [
		"# \$" . "NetBSD\$",
		"",
		"DISTNAME=\tAlgorithm-CheckDigits-v1.3.2",
		"PKGNAME=\t\${DISTNAME:S,-v,-,}",
		"CATEGORIES=\tpkgtools",
		"MASTER_SITES=\thttps://cpan.example.org/",
		"",
		"MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE",
		"HOMEPAGE=\thttps://cpan.example.org/",
		"COMMENT=\tTODO: Short description of the package",
		"#LICENSE=\t# TODO: (see mk/license.mk)",
		"",
		"# url2pkg-marker (please do not remove this line.)",
		".include \"../../mk/bsd.pkg.mk\""
	]);
}

sub test_read_dependencies() {
	my $cmd = "printf '%s\n' \"\$URL2PKG_DEPENDENCIES\"";
	my @dep_lines = (
		"DEPENDS\tpackage>=version:../../pkgtools/pkglint",
		"DEPENDS\tpackage>=version:../../pkgtools/x11-links",
		"BUILD_DEPENDS\turl2pkg>=1.0",
		"TEST_DEPENDS\tpkglint",
		"A line that is not a dependency at all",
		""
	);
	my $env = { "URL2PKG_DEPENDENCIES" => join("\n", @dep_lines) };

	read_dependencies($cmd, $env, "");

	is($ENV{"URL2PKG_DEPENDENCIES"}, undef);
	is_deeply(\@main::depends, [
		"package>=version:../../pkgtools/pkglint"
	]);
	is_deeply(\@main::bl3_lines, [
		".include \"../../pkgtools/x11-links/buildlink3.mk\""
	]);
	is_deeply(\@main::build_depends, [
		"url2pkg>=1.0:../../pkgtools/url2pkg"
	]);
	is_deeply(\@main::test_depends, [
		"pkglint>=0:../../pkgtools/pkglint"
	]);
}

sub test_generate_adjusted_Makefile_lines() {
	$main::makefile_lines = Lines->new(
		"# before 1",
		"# before 2",
		"# url2pkg-marker",
		"# after 1",
		"# after 2"
	);

	my $lines = generate_adjusted_Makefile_lines("https://example.org/pkgname-1.0.tar.gz");

	is_deeply($lines, [
		"# before 1",
		"# before 2",
		"# after 1",
		"# after 2"
	]);
}

sub test_generate_adjusted_Makefile_lines__dependencies() {
	$main::makefile_lines = Lines->new(
		"# \$NetBSD\$",
		"",
		"# url2pkg-marker",
		".include \"../../mk/bsd.pkg.mk\""
	);
	# some dependencies whose directory will not be found
	add_dependency("DEPENDS", "depends", ">=5.0", "../../devel/depends");
	add_dependency("TOOL_DEPENDS", "tool-depends", ">=6.0", "../../devel/tool-depends");
	add_dependency("BUILD_DEPENDS", "build-depends", ">=7.0", "../../devel/build-depends");
	add_dependency("TEST_DEPENDS", "test-depends", ">=8.0", "../../devel/test-depends");
	# some dependencies whose directory is explicitly given
	push(@main::depends, "depends>=11.0:../../devel/depends");
	push(@main::build_depends, "build-depends>=12.0:../../devel/build-depends");
	push(@main::test_depends, "test-depends>=13.0:../../devel/test-depends");

	my $lines = generate_adjusted_Makefile_lines("https://example.org/pkgname-1.0.tar.gz");

	is_deeply($lines, [
		"# \$NetBSD\$",
		"",
		"# TODO: dependency TOOL_DEPENDS # TODO: tool-depends>=6.0",
		"",
		"BUILD_DEPENDS+=\t# TODO: build-depends>=7.0",
		"BUILD_DEPENDS+=\tbuild-depends>=12.0:../../devel/build-depends",
		"DEPENDS+=\t# TODO: depends>=5.0",
		"DEPENDS+=\tdepends>=11.0:../../devel/depends",
		"TEST_DEPENDS+=\t# TODO: test-depends>=8.0",
		"TEST_DEPENDS+=\ttest-depends>=13.0:../../devel/test-depends",
		"",
		".include \"../../mk/bsd.pkg.mk\""
	]);
}

sub set_up_test() {
	no warnings 'once';

	$main::distname = "";
	$main::abs_wrkdir = "";
	$main::abs_wrksrc = "";

	@main::wrksrc_files = ();
	@main::wrksrc_dirs = ();
	@main::categories = ();

	@main::depends = ();
	@main::build_depends = ();
	@main::test_depends = ();
	@main::bl3_lines = ();
	@main::includes = ();
	@main::build_vars = ();
	@main::extra_vars = ();
	%main::update_vars = ();
	@main::todos = ();

	$main::pkgname_prefix = "";
	$main::pkgname_transform = "";
	$main::makefile_lines = [];
	$main::regenerate_distinfo = 0;
}

sub t_main() {
	my $pkgsrcdir = $ENV{"PKGSRCDIR"} or die;
	chdir("$pkgsrcdir/pkgtools/url2pkg") or die;

	no strict 'refs';
	foreach my $testname (sort grep { $_ =~ qr"^test_" } keys %{"main::"}) {
		next if $testname eq "test_depends";  # it's an array
		set_up_test();
		&{"main::$testname"}();
	}

	done_testing();
}

t_main();
