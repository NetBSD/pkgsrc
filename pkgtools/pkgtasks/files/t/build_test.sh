#! __POSIX_SHELL__
#
# Copyright (c) 2017 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
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
#
# NAME
#	build_test -- build standalone test scripts
#
# SYNOPSIS
#	build_test [-o <target>] <source>
#
# DESCRIPTION
#	build_test takes a script that uses pkgtask modules and generates an
#	executable script with the necessary boilerplate to run standalone.
#
#	The <source> is the path to the file to build.  The built script is
#	written to the standard output.
#
#	The options are as follows:
#
#	-o <output>
#		The path to the output file to write the built script.
#		If this option is given, then the built script is also made
#		executable.
#
# EXIT STATUS
#	The script exits with a value of 0 on success, and >0 if an error
#	occurs.
#
# ENVIRONMENT
#	The following variables are used if they are set:
#
#	TASK_MODULE_DIR
#		The location of the pkgtask modules.  The default value is
#		"__TASK_MODULE_DIR__".
#
#	TASK_TESTS_DIR
#		The location of the pkgtask tests directory.  The default
#		value is "__TASK_TESTS_DIR__".
#
#	POSIX_SHELL
#		The path of the shell interpreter to add to the shebang
#		boilerplate of the built script.  The default value is
#		"__POSIX_SHELL__".
#

: ${TASK_MODULE_DIR:=__TASK_MODULE_DIR__}
: ${TASK_TESTS_DIR:=__TASK_TESTS_DIR__}
: ${POSIX_SHELL:=__POSIX_SHELL__}

. "${TASK_MODULE_DIR}/load.subr"

task_load maketemp

build_test()
{
	: ${CAT:=cat}
	: ${CHMOD:=chmod}
	: ${MV:=mv}

	local output=
	local arg
	local OPTIND=1
	while getopts ":o:" arg "$@"; do
		case $arg in
		o)	output="${OPTARG}" ;;
		*)	return 127 ;;
		esac
	done
	shift $(( ${OPTIND} - 1 ))

	# Setting the output file to "-" means to write to standard output.
	if [ "$output" = "-" ]; then
		output=
	fi

	# Use standard input unless source files are given.
	[ $# -gt 0 ] || set -- "-"

	if [ -n "$output" ]; then
		local output_tmp
		output_tmp=$( task_maketemp $output.XXXXXXXXXX ) &&
		( _build_test_boilerplate && ${CAT} "$@" ) > $output_tmp &&
		${MV} -f "$output_tmp" "$output" &&
		${CHMOD} +x "$output"
	else
		# Write script to standard output.
		 _build_test_boilerplate && ${CAT} "$@"
	fi
}

_build_test_boilerplate()
{
	: ${CAT:=cat}

	${CAT} << EOF
#! ${POSIX_SHELL}

: \${TASK_MODULE_DIR:=__TASK_MODULE_DIR__}
: \${TASK_TESTS_DIR:=__TASK_TESTS_DIR__}

[ -f "\${TASK_MODULE_DIR}/load.subr" ] ||
	echo "\${0##*/}: missing file \`\`\${TASK_MODULE_DIR}/load.subr''"

. "\${TASK_MODULE_DIR}/load.subr"

EOF
}

build_test "$@"
