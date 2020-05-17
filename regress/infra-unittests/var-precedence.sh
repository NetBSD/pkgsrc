#! /bin/sh
# $NetBSD: var-precedence.sh,v 1.1 2020/05/17 13:35:35 rillig Exp $
#
# Demonstrates how environment variables interact with variables defined
# in the Makefiles and variables defined in the command line.
#
# Everything works exactly as documented in the bmake manual page.
#

set -eu

. './test.subr'

# usage: vartest <testname> <command> <expected>
vartest() {
	test_case_begin "$1" || return 0

	create_file_lines 'var.mk'	\
		'.if defined(DEFAULT)'	\
		'VAR?=	default'	\
		'.endif'		\
		''			\
		'.if defined(SET)'	\
		'VAR=	set'		\
		'.endif'		\
		''			\
		'.if defined(APPEND)'	\
		'VAR+=	append'		\
		'.endif'		\
		''			\
		'.if defined(RESET)'	\
		'.undef VAR'		\
		'VAR=	reset'		\
		'.endif'		\
		''			\
		'all:'			\
		'	@printf '\''%s\n'\'' '\'\''${VAR:Q}'

	unset DEFAULT SET APPEND VAR

	eval "$2" 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '0'
	assert_that "$tmpdir/output" --file-is-lines \
		"$3"

	test_case_end
}

vartest 'undefined'			'	 run_bmake var.mk'			''
vartest 'env'				'VAR=env run_bmake var.mk'			'env'
vartest 'env + flag'			'VAR=env run_bmake var.mk VAR=flag'		'flag'
vartest 'env + default'			'VAR=env run_bmake var.mk DEFAULT=yes'		'env'
vartest 'env + set'			'VAR=env run_bmake var.mk SET=yes'		'set'
vartest 'env + append'			'VAR=env run_bmake var.mk APPEND=yes'		'env append'
vartest 'env + reset'			'VAR=env run_bmake var.mk RESET=yes'		'reset'
vartest 'flag'				'	 run_bmake var.mk VAR=flag'		'flag'
vartest 'flag + default'		'	 run_bmake var.mk VAR=flag DEFAULT=yes'	'flag'
vartest 'flag + set'			'	 run_bmake var.mk VAR=flag SET=yes'	'flag'
vartest 'flag + append'			'	 run_bmake var.mk VAR=flag APPEND=yes'	'flag'
vartest 'flag + reset'			'	 run_bmake var.mk VAR=flag RESET=yes'	'flag'

# The override flag is not used in pkgsrc.
vartest 'env + override'		'VAR=env run_bmake var.mk -e'			'env'
vartest 'env + override + flag'		'VAR=env run_bmake var.mk -e VAR=flag'		'flag'
vartest 'env + override + default'	'VAR=env run_bmake var.mk -e DEFAULT=yes'	'env'
vartest 'env + override + set'		'VAR=env run_bmake var.mk -e SET=yes'		'env'
vartest 'env + override + append'	'VAR=env run_bmake var.mk -e APPEND=yes'	'env'
vartest 'env + override + reset'	'VAR=env run_bmake var.mk -e RESET=yes'		'env'
