# -*-perl-*-

# Copyright (c) 2019 The NetBSD Foundation, Inc.
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

# This is a drop-in replacement for the Module::Build Perl module. Instead
# of generating a Makefile, it extracts the dependency information for
# other Perl modules. It is used to simplify the generation of pkgsrc
# packages for Perl modules.

package Module::Build;

use strict;
use warnings FATAL => 'all';

our $VERSION = 0.4224; # from Perl-5.30

sub url2pkg_write_dependencies($$$) {
	my ($self, $varname, $key) = @_;
	return unless defined $self->{$key};

	my $deps = $self->{$key};
	foreach my $item (keys %$deps) {
		my $pkgbase = "p5-$item" =~ s/::/-/gr;
		printf("%s\t%s>=%s\n", $varname, $pkgbase, $deps->{$item});
	}
}

sub url2pkg_write_var($$$) {
	my ($self, $varname, $value) = @_;
	return unless defined($value) && $value ne "";
	printf("var\t%s\t%s\n", $varname, $value);
}

sub url2pkg_write_cmd($$) {
	my ($self, $cmd, $arg) = @_;
	printf("cmd\t%s\t%s\n", $cmd, $arg);
}

sub VERSION($$) {
	my ($class, $min_version) = @_;
	return $min_version <= $VERSION;
}

sub new(%) {
	my ($class, %args) = @_;
	my $self = \%args;
	bless($self, $class);
	return $self;
}

sub create_build_script($) {
	my ($self) = @_;

	$self->url2pkg_write_dependencies("BUILD_DEPENDS", "configure_requires");
	$self->url2pkg_write_dependencies("BUILD_DEPENDS", "build_requires");
	$self->url2pkg_write_dependencies("DEPENDS", "requires");
	$self->url2pkg_write_dependencies("TEST_DEPENDS", "test_requires");
	$self->url2pkg_write_dependencies("#RECOMMENDS", "recommends");

	$self->url2pkg_write_var("COMMENT", $self->{"dist_abstract"});
	my $license = $self->{"license"} || "";
	if ($license ne "") {
		$self->url2pkg_write_cmd("license", $license);
		$self->url2pkg_write_var("license_default", "# TODO: $license (from Build.PL)")
	}
}

1;
