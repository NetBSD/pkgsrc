# -*-perl-*-

# Copyright (c) 2010, 2019 The NetBSD Foundation, Inc.
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

# This is a drop-in replacement for the MakeMaker Perl module. Instead
# of generating a Makefile, it extracts the dependency information for
# other Perl modules. It is used to simplify the generation of pkgsrc
# packages for Perl modules.

package ExtUtils::MakeMaker;

require 5.013002;

use strict;
use warnings FATAL => 'all';

my $url2pkg_pkgsrcdir = '@PKGSRCDIR@';

BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT);
	@ISA = qw(Exporter);
}

# From lib/perl5/5.18.0/ExtUtils/MakeMaker.pm
our $VERSION = '6.66';

our $Verbose	= 0;	# exported
our @EXPORT	= qw(&WriteMakefile &prompt $Verbose $version);
our @EXPORT_OK	= qw(&neatvalue &_sprintf562);

# Finds and returns the category a given package lies in.
# If the package does not exist, an empty string is returned.
# If the package exists more than once, it is unspecified which
# of the categories is returned.
sub url2pkg_find_category($) {
	my ($pkg) = @_;

	opendir(D, $url2pkg_pkgsrcdir) or die;
	my @categories = readdir(D);
	closedir(D) or die;

	foreach my $cat (@categories) {
		next if $cat =~ qr"^\.";

		if (-f "$url2pkg_pkgsrcdir/$cat/$pkg/Makefile") {
			return $cat;
		}
	}
	return "";
}

sub url2pkg_write_dependency($$$) {
	my ($type, $dep, $ver) = @_;

	my $pkgbase = "p5-$dep" =~ s/::/-/gr;
	my $category = url2pkg_find_category($pkgbase);

	if ($category ne "") {
		printf("%s\t%s>=%s:../../%s/%s\n", $type, $pkgbase, $ver, $category, $pkgbase);
		return;
	}

	# If the package does not exist but the Perl module can be loaded, assume
	# that it is a built-in module and no dependency declaration is needed.
	return if eval("use $dep $ver; 1;");

	printf("%s\t%s>=%s\n", $type, $pkgbase, $ver);
}

sub url2pkg_write_var($$) {
	my ($varname, $value) = @_;
	return unless defined($value) && $value ne "";
	printf("var\t%s\t%s\n", $varname, $value);
}

sub url2pkg_write_depends($$) {
	my ($type, $deps) = @_;

	return unless $deps;
	foreach my $dep (sort(keys(%$deps))) {
		url2pkg_write_dependency($type, $dep, $deps->{$dep});
	}
}

sub WriteMakefile(%) {
	my (%options) = @_;

	url2pkg_write_depends("DEPENDS", $options{"PREREQ_PM"});
	url2pkg_write_depends("TEST_DEPENDS", $options{"TEST_DEPENDS"});

	my $license = $options{"LICENSE"} || "";
	if ($license eq "perl") {
		url2pkg_write_var("LICENSE", "\${PERL5_LICENSE}");
	} elsif ($license ne "") {
		url2pkg_write_var("#LICENSE", "# TODO: $license (from Makefile.PL)")
	}
}

sub prompt(@) {
	my ($message, $default) = @_;

	return $default || "";
}

sub neatvalue {
	return;
}

sub _sprintf562 {
	return sprintf(@_);
}

1;
