#! @PERL5@
# $NetBSD: url2pkg.pl,v 1.75 2019/10/01 19:41:23 rillig Exp $
#

# Copyright (c) 2010 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Roland Illig.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

use strict;
use warnings;

my $make		= '@MAKE@';
my $libdir		= '@LIBDIR@';
my $pythonbin		= '@PYTHONBIN@';
my $pkgsrcdir		= '@PKGSRCDIR@';

use constant true	=> 1;
use constant false	=> 0;

sub run_editor($$) {
	my ($fname, $lineno) = @_;

	my $editor = $ENV{"PKGEDITOR"} || $ENV{"EDITOR"} || "vi";

	my @args;
	push(@args, $editor);
	push(@args, "+$lineno") if $editor =~ qr"(^|/)(mcedit|nano|pico|vi|vim)$";
	push(@args, $fname);

	system { $args[0] } (@args);
}

sub get_maintainer() {

	return $ENV{"PKGMAINTAINER"} || $ENV{"REPLYTO"} || "INSERT_YOUR_MAIL_ADDRESS_HERE";
}

sub var($$$) {
	my ($name, $op, $value) = @_;

	return [$name, $op, $value];
}

sub find_package($) {
	my ($pkgbase) = @_;

	my @candidates = <$pkgsrcdir/*/$pkgbase>;
	return "" unless @candidates == 1;
	return $candidates[0] =~ s/\Q$pkgsrcdir\E/..\/../r;
}

sub make(@) {
	my @args = @_;

	(system { $make } ($make, @args)) == 0 or die;
}

package Lines;

use constant false => 0;
use constant true => 1;

sub new($@) {
	my ($class, @lines) = @_;
	my $lines = \@lines;
	bless($lines, $class);
	return $lines;
}

sub read_from($$) {
	my ($class, $filename) = @_;

	my $lines = Lines->new();
	open(F, "<", $filename) or die;
	while (defined(my $line = <F>)) {
		chomp($line);
		$lines->add($line);
	}
	close(F) or die;
	return $lines;
}

sub write_to($@) {
	my ($lines, $filename) = @_;

	open(F, ">", "$filename.tmp") or die;
	foreach my $line (@$lines) {
		print F "$line\n";
	}
	close(F) or die;
	rename("$filename.tmp", $filename) or die;
}

sub add($@) {
	my ($lines, @lines) = @_;

	push(@$lines, @lines);
}

# appends the given variable assignments to the lines, aligning the
# variable values vertically.
sub add_vars($@) {
	my ($lines, @vars) = @_;

	return if @vars == 0;

	my $width = 0;
	foreach my $var (@vars) {
		my ($name, $op, $value) = @$var;
		next if $value eq "";
		my $len = (length("$name$op\t") + 7) & -8;
		$width = $len if $len > $width;
	}

	foreach my $var (@vars) {
		my ($name, $op, $value) = @$var;
		next if $value eq "";
		my $tabs = "\t" x (($width - length("$name$op") + 7) / 8);
		$lines->add("$name$op$tabs$value");
	}

	$lines->add("");
}

# changes the value of an existing variable in the lines.
sub set($$$) {
	my ($lines, $varname, $new_value) = @_;

	my $i = 0;
	foreach my $line (@$lines) {
		if ($line =~ qr"^#?\Q$varname\E(\+?=)([ \t]*)([^#\\]*?)(\s*)(#.*|)$") {
			my ($op, $indent, $old_value, $space_after_value, $comment) = ($1, $2, $3, $4, $5);

			$lines->[$i] = "$varname$op$indent$new_value";
			return true;
		}
		$i++;
	}

	return false;
}

# appends to the value of an existing variable in the lines.
sub append($$$) {
	my ($lines, $varname, $value) = @_;

	return if $value eq "";

	my $i = 0;
	foreach my $line (@$lines) {
		if ($line =~ qr"^\Q$varname\E(\+?=)([ \t]*)([^#\\]*?)(\s*)(#.*|)$") {
			my ($op, $indent, $old_value, $space_after_value, $comment) = ($1, $2, $3, $4, $5);

			my $before = $old_value =~ qr"\S$" ? " " : "";
			my $after = $comment eq "" ? "" : " ";
			$lines->[$i] = "$varname$op$indent$old_value$before$value$after$comment";
			return true;
		}
		$i++;
	}

	return false;
}

# removes a variable assignment from the lines.
sub remove($$) {
	my ($lines, $varname) = @_;

	my $i = 0;
	foreach my $line (@$lines) {
		if ($line =~ qr"^\Q$varname\E(\+?=)") {
			splice(@$lines, $i, 1);
			return true;
		}
		$i++;
	}

	return false;
}

# returns the variable value from the only variable assignment, or an empty
# string.
sub get($$) {
	my ($lines, $varname) = @_;

	my $only_value = "";
	foreach my $line (@$lines) {
		if ($line =~ qr"^\Q$varname\E(\+?=)([ \t]*)([^#\\]*?)(\s*)(#.*|)$") {
			my ($op, $indent, $value, $space_after_value, $comment) = ($1, $2, $3, $4, $5);

			return "" if $only_value ne "";
			$only_value = $value;
		}
	}
	return $only_value;
}

# removes a variable assignment from the lines if its value is the
# expected one.
sub remove_if($$$) {
	my ($lines, $varname, $expected_value) = @_;

	my $i = 0;
	foreach my $line (@$lines) {
		if ($line =~ qr"^\Q$varname\E(\+?=)([ \t]*)([^#\\]*?)(\s*)(#.*|)$") {
			my ($op, $indent, $old_value, $space_after_value, $comment) = ($1, $2, $3, $4, $5);

			if ($old_value eq $expected_value) {
				splice(@$lines, $i, 1);
				return true;
			}
		}
		$i++;
	}

	return false;
}

sub index($$) {
	my ($lines, $re) = @_;

	foreach my $i (0 .. $#$lines) {
		return $i if $lines->[$i] =~ $re;
	}
	return -1;
}

1;

package main;

# The following adjust_* subroutines are called after the distfiles have
# been downloaded and extracted. They inspect the extracted files
# and adjust the variable definitions in the package Makefile.

#
# The following variables may be used in the adjust_* subroutines:
#

# the package name, including the version number.
our $distname;

# the absolute pathname to the working directory, containing
# the extracted distfiles.
our $abs_wrkdir;

# the absolute pathname to a subdirectory of $abs_wrkdir, typically
# containing package-provided Makefiles or configure scripts.
our $abs_wrksrc;

our @wrksrc_files;
our @wrksrc_dirs;
# the regular files and directories relative to abs_wrksrc.

#
# The following variables may be set by the adjust_* subroutines and
# will later appear in the package Makefile:
#

# categories for the package, in addition to the usual
# parent directory.
our @categories;

# the dependencies of the package, in the form
# "package>=version:../../category/package".
our @depends;
our @build_depends;
our @test_depends;

# .include, interleaved with BUILDLINK3_API_DEPENDS.
# These lines are added at the bottom of the Makefile.
our @bl3_lines;

# a list of pathnames relative to the package path.
# All these files will be included at the bottom of the Makefile.
our @includes;

# a list of variable assignments that will make up the fourth
# paragraph of the package Makefile, where the build configuration
# takes place.
our @build_vars;

# similar to the @build_vars, but separated by an empty line in
# the Makefile, thereby forming the fifth paragraph.
our @extra_vars;

# variables from the initial Makefile whose values are replaced
our %update_vars;

# these are inserted below the second paragraph in the Makefile.
our @todos;

# the package name is $pkgname_prefix${DISTNAME$pkgname_transform}.
our $pkgname_prefix = "";     # example: ${PYPKGPREFIX}-
our $pkgname_transform = "";  # example: :S,-v,-,

# all lines of the package Makefile, for direct modification.
our $makefile_lines;

our $regenerate_distinfo = false;

# Example:
# add_dependency("DEPENDS", "package", ">=1", "../../category/package");
#
sub add_dependency($$$$) {
	my ($type, $pkgbase, $constraint, $dep_dir) = @_;

	if ($dep_dir ne "" && -f "$dep_dir/buildlink3.mk") {
		# TODO: add type to bl3_lines (BUILDLINK_DEPENDS)
		# TODO: add constraint to bl3_lines (BUILDLINK_API_DEPENDS)
		push(@bl3_lines, ".include \"$dep_dir/buildlink3.mk\"");
		return;
	}

	my $value = $dep_dir ne "" && -f "$dep_dir/Makefile"
		? "$pkgbase$constraint:$dep_dir"
		: "# TODO: $pkgbase$constraint";

	if ($type eq "DEPENDS") {
		push(@depends, $value);
	} elsif ($type eq "BUILD_DEPENDS") {
		push(@build_depends, $value);
	} elsif ($type eq "TEST_DEPENDS") {
		push(@test_depends, $value);
	} else {
		push(@todos, "dependency $type $value");
	}
}

sub read_dependencies($$$) {
	my ($cmd, $env, $pkgnameprefix) = @_;
	my @dep_lines;

	my %prev_ENV = %ENV;
	foreach my $name (keys %$env) {
		$ENV{$name} = $env->{$name};
	}
	open(DEPS, "$cmd |") or die;
	%ENV = %prev_ENV;

	while (defined (my $line = <DEPS>)) {
		chomp($line);

		if ($line =~ qr"^(\w+)\t([^\s:>]+)(>[^\s:]+|)(?::(\.\./\.\./\S+))?$") {
			push(@dep_lines, [ $1, $2, $3 || ">=0", $4 || "" ]);
		} elsif ($line =~ qr"^var\t(\S+)\t(.+)$") {
			$main::update_vars{$1} = $2;
		} elsif ($line ne "") {
			printf STDERR "url2pkg: info: unknown dependency line: %s\n", $line;
		}
	}

	close(DEPS) or die;

	foreach my $dep_line (@dep_lines) {
		my ($type, $pkgbase, $constraint, $dir) = @$dep_line;

		if ($dir eq "" && $pkgnameprefix ne "") {
			$dir = find_package("$pkgnameprefix$pkgbase");
			if ($dir ne "") {
				$pkgbase = "$pkgnameprefix$pkgbase";
			}
		}
		if ($dir eq "") {
			$dir = find_package($pkgbase);
		}

		add_dependency($type, $pkgbase, $constraint, $dir);
	}
}

sub adjust_configure() {
	my $gnu_configure = false;

	open(CONF, "<", "$abs_wrksrc/configure") or return;
	while (defined(my $line = <CONF>)) {
		if ($line =~ qr"autoconf|Free Software Foundation"i) {
			$gnu_configure = true;
			last;
		}
	}
	close(CONF);

	my $varname = ($gnu_configure ? "GNU_CONFIGURE" : "HAS_CONFIGURE");
	push(@build_vars, var($varname, "=", "yes"));
}

sub adjust_cmake() {
	if (-f "$abs_wrksrc/CMakeLists.txt") {
		push(@build_vars, var("USE_CMAKE", "=", "yes"));
	}
}

sub adjust_meson() {
	if (-f "$abs_wrksrc/meson.build") {
		push(@includes, "../../devel/py-meson/build.mk");
	}
}

sub adjust_gconf2_schemas() {
	my @gconf2_files = grep(/schemas(?:\.in.*)$/, @wrksrc_files);
	if (@gconf2_files) {
		foreach my $f (@gconf2_files) {
			if ($f =~ qr"(.*schemas)") {
				push(@extra_vars, var("GCONF_SCHEMAS", "+=", $1));
			}
		}
		push(@includes, "../../devel/GConf/schemas.mk");
	}
}

sub adjust_libtool() {
	if (-f "$abs_wrksrc/ltconfig" || -f "$abs_wrksrc/ltmain.sh") {
		push(@build_vars, var("USE_LIBTOOL", "=", "yes"));
	}
	if (-d "$abs_wrksrc/libltdl") {
		push(@includes, "../../devel/libltdl/convenience.mk");
	}
}

# Example packages:
# devel/p5-Algorithm-CheckDigits
sub adjust_perl_module_Build_PL() {

	read_dependencies("cd '$abs_wrksrc' && perl -I$libdir -I. Build.PL", {}, "");

	push(@build_vars, var("PERL5_MODULE_TYPE", "=", "Module::Build"));
}

# Example packages:
# devel/p5-Algorithm-Diff (no dependencies)
# devel/p5-Carp-Assert-More (dependencies without version numbers)
# www/p5-HTML-Quoted (dependency with version number)
sub adjust_perl_module_Makefile_PL() {

	# To avoid fix_up_makefile error for p5-HTML-Quoted, generate Makefile first.
	system("cd '$abs_wrksrc' && perl -I. Makefile.PL < /dev/null 1>&0 2>&0") == 0 or do {};

	read_dependencies("cd '$abs_wrksrc' && perl -I$libdir -I. Makefile.PL", {}, "");
}

sub adjust_perl_module_homepage($) {
	my ($url) = @_;

	if ($makefile_lines->get("MASTER_SITES") =~ qr"\$\{MASTER_SITE_PERL_CPAN:") {
		my $homepage = $makefile_lines->get("HOMEPAGE");
		if ($homepage ne "" && index($url, $homepage) == 0) {
			my $module_name = $distname =~ s/-v?[0-9].*//r =~ s/-/::/gr;
			$makefile_lines->set("HOMEPAGE", "https://metacpan.org/pod/$module_name");
		}
	}
}

sub adjust_perl_module($) {
	my ($url) = @_;

	if (-f "$abs_wrksrc/Build.PL") {
		adjust_perl_module_Build_PL();
	} elsif (-f "$abs_wrksrc/Makefile.PL") {
		adjust_perl_module_Makefile_PL();
	} else {
		return;
	}

	my $packlist = $distname =~ s/-v?[0-9].*//r =~ s/-/\//gr;
	push(@build_vars, var("PERL5_PACKLIST", "=", "auto/$packlist/.packlist"));
	push(@includes, "../../lang/perl5/module.mk");
	$pkgname_prefix = "p5-";
	push(@categories, "perl5");
	adjust_perl_module_homepage($url);

	unlink("PLIST") or do {};
}

# Example packages:
#
# devel/py-ZopeComponent (dependencies, test dependencies)
# devel/py-gflags (uses distutils.core instead of setuptools; BSD license)
# devel/py-gcovr (uses setuptools; BSD license)
sub adjust_python_module() {

	return unless -f "$abs_wrksrc/setup.py";

	my $cmd = "cd '$abs_wrksrc' && $pythonbin setup.py build";
	my $env = {
		"PYTHONDONTWRITEBYTECODE" => "x",
		"PYTHONPATH"              => $libdir
	};
	read_dependencies($cmd, $env, "py-");

	$pkgname_prefix = "\${PYPKGPREFIX}-";
	push(@categories, "python");
	push(@includes, "../../lang/python/egg.mk");
}

sub adjust_cargo() {
	open(CONF, "<", "$abs_wrksrc/Cargo.lock") or return;

	while (defined(my $line = <CONF>)) {
		# "checksum cargo-package-name cargo-package-version
		if ($line =~ qr"^\"checksum\s(\S+)\s(\S+)") {
			push(@build_vars, var("CARGO_CRATE_DEPENDS", "+=", "$1-$2"));
		}
	}
	close(CONF);

	push(@includes, "../../lang/rust/cargo.mk");
}


sub adjust_pkg_config() {
	my @pkg_config_files = grep { /\.pc\.in$/ && ! /-uninstalled\.pc\.in$/ } @wrksrc_files;
	if (@pkg_config_files) {
		push(@build_vars, var("USE_TOOLS", "+=", "pkg-config"));
	}
	foreach my $f (@pkg_config_files) {
		push(@extra_vars, var("PKGCONFIG_OVERRIDE", "+=", $f));
	}
}

sub adjust_po() {
	if (grep(/\.g?mo$/, @wrksrc_files)) {
		push(@build_vars, var("USE_PKGLOCALEDIR", "=", "yes"));
	}
}

sub adjust_use_languages() {
	my @languages;

	grep(/\.(c|xs)$/, @wrksrc_files) and push(@languages, "c");
	grep(/\.(cpp|c\+\+|cxx|cc|C)$/, @wrksrc_files) and push(@languages, "c++");
	grep(/\.f$/, @wrksrc_files) and push(@languages, "fortran");

	my $use_languages = join(" ", @languages);
	if ($use_languages eq "") {
		$use_languages = "# none";
	}
	if ($use_languages ne "c") {
		push(@build_vars, var("USE_LANGUAGES", "=", $use_languages));
	}
}

#
# Subroutines for generating the initial package and adjusting it after
# the distfiles have been extracted.
#

sub generate_initial_package_Makefile_lines($) {
	my ($url) = @_;

	my $master_site = "";
	my $master_sites = "";
	my $distfile = "";
	my $homepage = "";
	my $extract_sufx = "";
	my $categories = "";
	my $github_project = "";
	my $github_release = "";
	my $dist_subdir = "";

	open(SITES, "<", "../../mk/fetch/sites.mk") or die;
	while (defined(my $line = <SITES>)) {
		chomp($line);

		if ($line =~ qr"^(MASTER_SITE_.*)\+=") {
			$master_site = $1;

		} elsif ($line =~ qr"^\t(.*?)(?:\s+\\)?$") {
			my ($site) = ($1);

			if (index($url, $site) == 0) {
				if ($url =~ qr"^\Q$site\E(.+)/([^/]+)$") {
					my $subdir = $1;
					$distfile = $2;

					$master_sites = "\${$master_site:=$subdir/}";
					if ($master_site eq "MASTER_SITE_SOURCEFORGE") {
						$homepage = "http://$subdir.sourceforge.net/";
					} elsif ($master_site eq "MASTER_SITE_GNU") {
						$homepage = "http://www.gnu.org/software/$subdir/";
					} else {
						$homepage = substr($url, 0, -length($distfile));
					}
				} else {
					$master_sites = "\${$master_site}";
				}
			}
		}
	}
	close(SITES) or die;

	if ($url =~ qr"^https://downloads\.sourceforge\.net/project/([^/?]+)/[^?]+/([^/?]+)(?:[?].*)?$") {
		my ($project, $filename) = ($1, $2);

		$master_sites = "\${MASTER_SITE_SOURCEFORGE:=$project/}";
		$homepage = "https://$project.sourceforge.net/";
		$distfile = $filename;
	}

	if ($url =~ qr"^https://github\.com/") {
		if ($url =~ qr"^https://github\.com/(.+)/(.+)/archive/(.+)(\.tar\.gz|\.zip)$") {
			my ($org, $proj, $tag, $ext) = ($1, $2, $3, $4);

			$github_project = $proj;
			$master_sites = "\${MASTER_SITE_GITHUB:=$org/}";
			$homepage = "https://github.com/$org/$proj/";
			if (index($tag, $github_project) == -1) {
				$pkgname_prefix = "\${GITHUB_PROJECT}-";
				$dist_subdir = "\${GITHUB_PROJECT}";
			}
			$distfile = "$tag$ext";

		} elsif ($url =~ qr"^https://github\.com/(.+)/(.+)/releases/download/(.+)/(.+)(\.tar\.gz|\.zip)$") {
			my ($org, $proj, $tag, $base, $ext) = ($1, $2, $3, $4, $5);

			$github_project = $proj;
			$master_sites = "\${MASTER_SITE_GITHUB:=$org/}";
			$homepage = "https://github.com/$org/$proj/";
			if (index($base, $proj) == -1) {
				$github_project = $proj;
				$dist_subdir = "\${GITHUB_PROJECT}";
			}
			$github_release = $tag eq $base ? "\${DISTNAME}" : $tag;
			$distfile = "$base$ext";

		} else {
			print("$0: ERROR: Invalid GitHub URL: $url, handling as normal URL\n");
		}
	}

	if ($master_sites eq "") {
		if ($url =~ qr"^(.*/)(.*)$") {
			$master_sites = $1;
			$distfile = $2;
			$homepage = $master_sites;
		} else {
			die("$0: ERROR: Invalid URL: $url\n");
		}
	}

	if ($distfile =~ qr"^(.*?)((?:\.tar)?\.\w+)$") {
		$distname = $1;
		$extract_sufx = $2;
	} else {
		$distname = $distfile;
		$extract_sufx = "# none";
	}

	if ($distname =~ qr"^v\d") {
		$pkgname_transform = ":S,^v,,";
	} elsif ($distname =~ qr"-v\d" && $distname !~ qr"-v.*-v\d") {
		$pkgname_transform = ":S,-v,-,";
	}

	`pwd` =~ qr".*/([^/]+)/[^/]+$" or die;
	$categories = $1 eq "wip" ? "# TODO: add primary category" : $1;

	if ($extract_sufx eq ".tar.gz" || $extract_sufx eq ".gem") {
		$extract_sufx = "";
	}

	my $pkgname = "$pkgname_prefix\${DISTNAME$pkgname_transform}";
	$pkgname = "" if $pkgname eq "\${DISTNAME}";

	my $lines = Lines->new();
	$lines->add("# \$" . "NetBSD\$");
	$lines->add("");

	$lines->add_vars(
		var("GITHUB_PROJECT", "=", $github_project),
		var("DISTNAME", "=", $distname),
		var("PKGNAME", "=", $pkgname),
		var("CATEGORIES", "=", $categories),
		var("MASTER_SITES", "=", $master_sites),
		var("GITHUB_RELEASE", "=", $github_release),
		var("EXTRACT_SUFX", "=", $extract_sufx),
		var("DIST_SUBDIR", "=", $dist_subdir),
	);

	$lines->add_vars(
		var("MAINTAINER", "=", get_maintainer()),
		var("HOMEPAGE", "=", $homepage),
		var("COMMENT", "=", "TODO: Short description of the package"),
		var("#LICENSE", "=", "# TODO: (see mk/license.mk)"),
	);

	$lines->add("# url2pkg-marker (please do not remove this line.)");
	$lines->add(".include \"../../mk/bsd.pkg.mk\"");

	return $lines;
}

sub generate_initial_package($) {
	my ($url) = @_;

	rename("Makefile", "Makefile-url2pkg.bak") or do {};
	generate_initial_package_Makefile_lines($url)->write_to("Makefile");
	Lines->new("\@comment \$" . "NetBSD\$")->write_to("PLIST");
	Lines->new()->write_to("DESCR");
	run_editor("Makefile", 5);

	make("distinfo");
	make("extract");
}

sub adjust_lines_python_module($$) {
	my ($lines, $url) = @_;

	my $initial_lines = generate_initial_package_Makefile_lines($url);
	my $current_lines = Lines->read_from("Makefile");

	return unless $initial_lines->get("CATEGORIES") =~ qr"python";
	my $pkgbase = $initial_lines->get("GITHUB_PROJECT");
	return if $pkgbase eq "";
	my $pkgbase1 = substr($pkgbase, 0, 1);
	my $pkgversion_norev = $initial_lines->get("DISTNAME") =~ s/^v//r;

	# don't risk to overwrite any changes made by the package developer.
	if (join('\n', @$current_lines) ne join('\n', @$initial_lines)) {
		splice(@$lines, -2, 0, "# TODO: Migrate MASTER_SITES to PYPI");
		return;
	}

	my $tx_lines = Lines->new(@$makefile_lines);
	if ($tx_lines->remove("GITHUB_PROJECT")
		&& $tx_lines->set("DISTNAME", "$pkgbase-$pkgversion_norev")
		&& $tx_lines->set("PKGNAME", "\${PYPKGPREFIX}-\${DISTNAME}")
		&& $tx_lines->set("MASTER_SITES", "\${MASTER_SITE_PYPI:=$pkgbase1/$pkgbase/}")
		&& $tx_lines->remove("DIST_SUBDIR")
		&& ($tx_lines->remove_if("EXTRACT_SUFX", ".zip") || true)) {

		@$makefile_lines = @$tx_lines;
		$regenerate_distinfo = true
	}
}

# sets $abs_wrksrc depending on $abs_wrkdir and the files found there.
sub determine_wrksrc() {
	my @files = ();
	opendir(WRKDIR, $abs_wrkdir) or die;
	while (defined(my $f = readdir(WRKDIR))) {
		next if $f =~ qr"^\."
			|| $f eq "pax_global_header"
			|| $f eq "package.xml"
			|| $f =~ qr"\.gemspec$";
		push(@files, $f);
	}
	closedir(WRKDIR);

	if (@files == 1) {
		if ($files[0] ne $distname) {
			push(@build_vars, var("WRKSRC", "=", "\${WRKDIR}/$files[0]"));
		}
		$abs_wrksrc = "$abs_wrkdir/$files[0]";
	} else {
		push(@build_vars, var("WRKSRC", "=", "\${WRKDIR}" .
		    ((@files > 1) ? " # More than one possibility -- please check manually." : "")));
		$abs_wrksrc = $abs_wrkdir;
	}
}

sub adjust_package_from_extracted_distfiles($) {
	my ($url) = @_;

	print("url2pkg> Adjusting the Makefile\n");

	chomp($abs_wrkdir = `$make show-var VARNAME=WRKDIR`);
	determine_wrksrc();
	chomp(@wrksrc_files = `cd "$abs_wrksrc" && find * -type f -print`);
	chomp(@wrksrc_dirs = `cd "$abs_wrksrc" && find * -type d -print`);

	$makefile_lines = Lines->read_from("Makefile");

	adjust_configure();
	adjust_cmake();
	adjust_meson();
	adjust_gconf2_schemas();
	adjust_libtool();
	adjust_perl_module($url);
	adjust_python_module();
	adjust_cargo();
	adjust_pkg_config();
	adjust_po();
	adjust_use_languages();

	generate_adjusted_Makefile_lines($url)->write_to("Makefile");

	if ($regenerate_distinfo) {
		make("distinfo");
	}
}

sub generate_adjusted_Makefile_lines($) {
	my ($url) = @_;

	my $marker_index = $makefile_lines->index(qr"^# url2pkg-marker");
	if ($marker_index == -1) {
		die("$0: ERROR: didn't find the url2pkg marker in the Makefile.\n");
	}

	my $lines = Lines->new(@$makefile_lines[0 .. $marker_index - 1]);

	if ($lines->index(qr"^PKGNAME=") == -1) {
		my $distname_index = $lines->index(qr"^DISTNAME=(\t+)");
		if ($distname_index != -1) {
			my $pkgname_line = "PKGNAME=\t$pkgname_prefix\${DISTNAME$pkgname_transform}";
			splice(@$lines, $distname_index + 1, 0, $pkgname_line);
		}
	}

	if (@todos) {
		foreach my $todo (@todos) {
			$lines->add("# TODO: $todo");
		}
		$lines->add("");
	}

	my @depend_vars;
	push(@depend_vars, map { var("BUILD_DEPENDS", "+=", $_) } @build_depends);
	push(@depend_vars, map { var("DEPENDS", "+=", $_) } @depends);
	push(@depend_vars, map { var("TEST_DEPENDS", "+=", $_) } @test_depends);
	$lines->add_vars(@depend_vars);

	$lines->add_vars(@build_vars);
	$lines->add_vars(@extra_vars);

	$lines->add(@bl3_lines);
	$lines->add(map { $_ = ".include \"$_\"" } @includes);

	$lines->add(@$makefile_lines[$marker_index + 1 .. $#$makefile_lines]);

	$lines->append("CATEGORIES", join(" ", @categories));

	adjust_lines_python_module($lines, $url);

	foreach my $varname (keys %update_vars) {
		$lines->set($varname, $update_vars{$varname});
	}

	return $lines;
}

sub main() {
	if (!-f "../../mk/bsd.pkg.mk") {
		die("ERROR: $0 must be run from a package directory (.../pkgsrc/category/package).\n");
	}

	my $url;
	if (scalar(@ARGV) == 0) {
		print("URL: ");
		if (!defined($url = <STDIN>)) {
			print("\n");
			exit(0);
		}
		chomp($url);
	} else {
		$url = shift(@ARGV);
	}

	my @extract_cookie = <w*/.extract_done>;
	if (scalar(@extract_cookie) == 0 || !-f "Makefile") {

		generate_initial_package($url);
	} else {
		chomp($distname = `$make show-var VARNAME=DISTNAME`);
	}

	adjust_package_from_extracted_distfiles($url);

	print("\n");
	print("Remember to run pkglint when you're done.\n");
	print("See ../../doc/pkgsrc.txt to get some help.\n");
	print("\n");
}

main() unless caller();
