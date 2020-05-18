#! /bin/sh
# $NetBSD: replace-interpreter.sh,v 1.1 2020/05/18 06:06:34 rillig Exp $
#
# Tests for mk/configure/replace-interpreter.mk.
#

set -eu

. './test.subr'

test_case_set_up() {
	create_file 'setup.mk' <<-EOF
		# The tools that are used by replace-interpreter.mk
		CHMOD=		chmod
		CMP=		cmp
		MV=		mv
		SED=		sed
		RM=		rm

		# Commands that are specific to pkgsrc
		RUN=		@set -e;
		STEP_MSG=	echo '=>'
		INFO_MSG=	echo 'info:'
		WARNING_MSG=	echo 'warning:'

		# Dummy interpreters
		PERL5=		$tmpdir/bin/perl5

		WRKDIR=		$tmpdir/wrkdir
		WRKSRC=		.
	EOF
}


if test_case_begin 'regular file'; then

	create_file 'test.mk' <<-EOF
		REPLACE_PERL+=		perl-program

		.include "setup.mk"
		.include "mk/configure/replace-interpreter.mk"
	EOF

	create_file_lines 'perl-program' \
		'#! /any/path/perl'

	run_bmake 'test.mk' 'replace-interpreter' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'=> Replacing Perl interpreter in perl-program.'
	assert_that 'perl-program' --file-is-lines \
		"#!$tmpdir/bin/perl5"

	test_case_end
fi


if test_case_begin 'valid symlink'; then

	# Valid symlinks are followed, even though they might point
	# anywhere, even outside WRKSRC.
	# This has "forever" been the behavior.
	# It may make sense to change this, but that requires testing
	# to see whether any packages rely on this behavior.

	# Ouch, this replaces the symlink with a regular file,
	# which is probably unexpected to the upstream author.

	create_file 'test.mk' <<-EOF
		REPLACE_PERL+=		perl-symlink

		.include "setup.mk"
		.include "mk/configure/replace-interpreter.mk"
	EOF
	create_file_lines 'perl-program' \
		'#! /any/path/perl'
	ln -s 'perl-program' 'perl-symlink'

	run_bmake 'test.mk' 'replace-interpreter' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'=> Replacing Perl interpreter in perl-symlink.'
	# This should most probably still be a symlink.
	[ -f 'perl-symlink' ] || assert_fail 'still a symlink\n'
	# This file should be left unmodified since it is not mentioned
	# in REPLACE_PERL.
	assert_that 'perl-program' --file-is-lines \
		"#! /any/path/perl"
	assert_that 'perl-symlink' --file-is-lines \
		"#!$tmpdir/bin/perl5"

	test_case_end
fi


if test_case_begin 'broken symlink'; then

	# Broken symlinks are skipped silently, just like directories.

	create_file 'test.mk' <<-EOF
		REPLACE_PERL+=		perl-symlink

		.include "setup.mk"
		.include "mk/configure/replace-interpreter.mk"
	EOF

	ln -s 'does-not-exist' 'perl-symlink'

	run_bmake 'test.mk' 'replace-interpreter' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'=> Replacing Perl interpreter in perl-symlink.'
	[ -h 'perl-symlink' ] || assert_fail 'not a symlink anymore'

	test_case_end
fi
