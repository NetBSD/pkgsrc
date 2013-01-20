#! @PERL@
# $NetBSD: pkglint.t,v 1.2 2013/01/20 02:57:37 schmonz Exp $
#

require 'pkglint.pl';			# so we can test its internals
$main::program = 'pkglint.pl';		# because it self-greps for vartypes

package PkgLint::Test;			# pkglint.pl uses 'main', so we mustn't

use Test::More tests => 17;
use Test::Trap;

use warnings;
use strict;

sub test_unit {
	my ($unit, $params, $exitcode, $stdout_re, $stderr_re) = @_;

	my @results = trap { $unit->(@{$params}) };

	if (defined $exitcode) {
		is($trap->exit, $exitcode, qq{exits $exitcode});
	} else {
		is($trap->exit, undef, q{doesn't exit});
	}
	like($trap->stdout, qr/$stdout_re/, qq{stdout matches $stdout_re});
	like($trap->stderr, qr/$stderr_re/, qq{stderr matches $stderr_re});
	
	return @results;
}

sub test_get_vartypes_basictypes {
	my $unit = \&main::get_vartypes_basictypes;

	my @results = test_unit($unit, undef, undef, '^$', '^$');
	my %types = %{$results[0]};
	is($types{YesNo_Indirectly}, 1, q{a couple expected types are here});
	is($types{BuildlinkDepmethod}, 1, q{a couple expected types are here});
}

sub test_main {
	my $unit = \&main::main;

	@ARGV = ('-h');
	test_unit($unit, undef, 0, '^usage: pkglint ', '^$');

	@ARGV = ();
	test_unit($unit, undef, 1, '^ERROR:.+how to check', '^$');

	@ARGV = ('.');
	test_unit($unit, undef, 1, '^ERROR:.+how to check', '^$');

	@ARGV = ('..');
	test_unit($unit, undef, 1, '^ERROR:.+LICENSE', '^$');
}

sub main {
	test_get_vartypes_basictypes();
	test_main();
}

main();
