#! @PERL@
# $NetBSD: pkglint.t,v 1.1 2013/01/19 22:51:11 schmonz Exp $
#

package PkgLint::Test;			# pkglint.pl uses 'main', so we mustn't

use Test::More tests => 3;
use Test::Trap;

use warnings;
use strict;

require 'pkglint.pl';			# so we can test its internals

sub test_main() {
	my $unit = \&main::main;

	my @r = trap { $unit->() };
	is($trap->exit, 1, q{exit code was 1});
	like($trap->stdout, qr/^ERROR:.+how to check/, q{message on stdout});
	is($trap->stderr, '', q{nothing on stderr});
}

sub main() {
	test_main();
}

main();
