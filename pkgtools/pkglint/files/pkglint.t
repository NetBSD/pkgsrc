#! @PERL@
# $NetBSD: pkglint.t,v 1.7 2013/03/26 15:10:32 schmonz Exp $
#

require 'pkglint.pl';			# so we can test its internals
$pkglint::program = 'pkglint.pl';	# because it self-greps for vartypes

use Test::More tests => 36;
use Test::Deep;
use Test::Trap;

use Config;
use File::Basename;
use IO::File;
use IPC::Open3;
use Symbol qw(gensym);

use warnings;
use strict;

sub test_unit {
	my ($unit, $params, $exitcode, $stdout_re, $stderr_re) = @_;
	$stdout_re ||= '^$';
	$stderr_re ||= '^$';

	my @results = trap { $unit->(@$params) };

	if (defined $exitcode) {
		is($trap->exit, $exitcode, qq{exits $exitcode});
	} else {
		is($trap->exit, undef, q{doesn't exit});
	}
	like($trap->stdout, qr/$stdout_re/sm, qq{stdout matches $stdout_re});
	like($trap->stderr, qr/$stderr_re/sm, qq{stderr matches $stderr_re});

	return @results;
}

sub test_program {
	my ($command, $params, $exitcode, $stdout_re, $stderr_re) = @_;
	$stdout_re ||= '^$';
	$stderr_re ||= '^$';

	my $stdout = '';
	my $stderr = '';
	local *CATCHERR = IO::File->new_tmpfile;
	my $pid = open3(gensym(), \*CATCHOUT, ">&CATCHERR", $command, @$params);
	while (my $l = <CATCHOUT>) {
		$stdout .= $l;
	}
	waitpid($pid, 0);
	my $ret = $? >> 8;
	seek CATCHERR, 0, 0;
	while (my $l = <CATCHERR>) {
		$stderr .= $l;
	}

	if (defined $exitcode) {
		is($ret, $exitcode, qq{exits $exitcode});
	}
	like($stdout, qr/$stdout_re/sm, qq{stdout matches $stdout_re});
	like($stderr, qr/$stderr_re/sm, qq{stderr matches $stderr_re});

	# return @results;
}

sub test_get_vartypes_basictypes {
	my $unit = \&pkglint::get_vartypes_basictypes;

	my @results = test_unit($unit);
	my %types = %{$results[0]};

	my @all_vartypes_basictypes = qw(
		ARRAY AwkCommand BrokenIn
		BuildlinkDepmethod BuildlinkDepth BuildlinkPackages
		CFlag Category Comment
		Dependency DependencyWithPath
		DistSuffix EmulPlatform
		FileMode Filemask Filename
		Identifier Integer LdFlag License Mail_Address Message Option
		Pathlist Pathmask Pathname
		Perl5Packlist
		PkgName PkgOptionsVar PkgPath PkgRevision
		PlatformTriple PrefixPathname
		RelativePkgDir RelativePkgPath
		Restricted SVR4PkgName
		SedCommand SedCommands
		ShellCommand ShellWord
		Stage String Tool URL Unchecked UserGroupName Varname Version
		WrapperReorder WrapperTransform
		WrkdirSubdirectory WrksrcSubdirectory
		Yes YesNo YesNo_Indirectly
	);

	cmp_bag(
		[ keys %types ],
		\@all_vartypes_basictypes,
		q{types contains all expected and no unexpected types},
	);
}

sub test_get_vartypes_map {
	my $unit = \&pkglint::get_vartypes_map;

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
	# once refactored, get rid of the $pkglint::program global
}

sub test_pkglint_main {
	my $unit = \&pkglint::main;

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

sub test_lint_some_reference_packages {
	my %reference_packages = (
		'mail/qmail-run' => {
			stdout_re => <<EOT,
^WARN: .*distinfo: File not found\. Please run '.+make makesum'\.
ERROR: .*Makefile: All packages must define their LICENSE\.
WARN: .*Makefile:[0-9]+: Unknown dependency pattern \"qmail-qfilter-1\.5nb1\"\.
WARN: .*Makefile:[0-9]+: The LOCALBASE variable should not be used by packages\.
WARN: .*Makefile:[0-9]+: The LOCALBASE variable should not be used by packages\.
1 errors and 4 warnings found\..*\$
EOT
			stderr_re => undef,
			exitcode => 1,
		},
		'mail/qmail' => {
			stdout_re => <<EOT,
^WARN: .*Makefile:[0-9]+: USERGROUP_PHASE is defined but not used\. Spelling mistake\\?
ERROR: .*patches/patch-hier\.c:[0-9]+: Comment expected\.
ERROR: .*patches/patch-spawn\.c:[0-9]+: Comment expected\.
2 errors and 1 warnings found\..*\$
EOT
			stderr_re => undef,
			exitcode => 1,
		},
		'mail/getmail' => {
			stdout_re => <<EOT,
^looks fine\.\$
EOT
			stderr_re => undef,
			exitcode => 0,
		},
	);

	my $dirprefix = dirname($0) || '.';
	my $pkglint = "$dirprefix/pkglint.pl";
	my $perl = $Config{perlpath};
	for my $package (keys %reference_packages) {
		test_program($perl, [ $pkglint, "../../../$package" ],
			$reference_packages{$package}->{exitcode},
			$reference_packages{$package}->{stdout_re},
			$reference_packages{$package}->{stderr_re});
	}
	# XXX this is JUST like test_unit(), when the tests work, refactor!

}

sub main {
	test_get_vartypes_basictypes();
	test_get_vartypes_map();
	test_checkline_mk_vartype_basic();
	test_pkglint_main();
	test_lint_some_reference_packages();
}

main();
