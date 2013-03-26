#! @PERL@
# $NetBSD: pkglint.t,v 1.4 2013/03/26 15:04:30 schmonz Exp $
#

require 'pkglint.pl';			# so we can test its internals
$main::program = 'pkglint.pl';		# because it self-greps for vartypes

package PkgLint::Test;			# pkglint.pl uses 'main', so we mustn't

use Test::More tests => 28;
use Test::Trap;

use warnings;
use strict;

sub test_unit {
	my ($unit, $params, $exitcode, $stdout_re, $stderr_re) = @_;
	$stdout_re ||= '^$';
	$stderr_re ||= '^$';

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

	my @results = test_unit($unit);
	my %types = %{$results[0]};
	is($types{BuildlinkDepmethod}, 1, q{a couple expected types are here});
	is($types{YesNo_Indirectly}, 1, q{a couple expected types are here});
}

sub test_get_vartypes_map {
	my $unit = \&main::get_vartypes_map;

	my @results = test_unit($unit);
	my %map = %{$results[0]};
	is($map{'BSD_MAKE_ENV'}->basic_type(), 'ShellWord',
	   q{a couple expected vars are typed right});
	is($map{'USE_BUILTIN.*'}->basic_type(), 'YesNo_Indirectly',
	   q{a couple expected vars are typed right});
}

sub test_checkline_mk_vartype_basic {
	# this is what gets self-grepped: all that "elsif ($type eq"
	# sub doesn't return anything, just warns or errors if need be
	#
	# TODO:
	#
	# test a shallow one and then a deeply nested one
	# (type='Restricted', value='incorrect')
	# (type='Restricted', value='RESTRICTED')
	# (type='SedCommands', a few different values')
	# once test coverage is persuasive, refactor to a dispatch table
	# once refactored, get rid of the $main::program global
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

	@ARGV = ('/does/not/exist');
	test_unit($unit, undef, 1, '^ERROR:.+not exist', '^$');

	@ARGV = ($ENV{HOME});
	test_unit($unit, undef, 1, '^ERROR:.+outside a pkgsrc', '^$');
}

sub main {
	test_get_vartypes_basictypes();
	test_get_vartypes_map();
	test_checkline_mk_vartype_basic();
	test_main();
}

main();
