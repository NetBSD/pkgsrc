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
#	run_tests -- run all of the test scripts for pkgtasks
#
# SYNOPSIS
#	run_tests [-v] [<script> ...]
#
# DESCRIPTION
#	run_tests runs the test scripts in the ${TASK_TESTS_DIR} directory
#	and reports a summary of the test results.  By default, all of the
#	test scripts are run, but a subset may be selected by passing their
#	names as optional parameters.
#
#	The options are as follows:
#
#	-v	Verbose; run the tests so they produce output to the
#		standard output and error.  By default, the tests are run
#		in quiet mode.
#
#	If this script is run with a basename ending in ".sh", then the
#	tests are assumed to be named also ending in ".sh" and located in
#	the current directory.  This is to allow the tests to be run from
#	their source directory.
#
# EXIT STATUS
#	The script exits with a value of the number of failed tests.
#

case ${0##*/} in
*.sh)	# Invoked from source directory.
	: ${TASK_MODULE_DIR:=..}
	: ${TASK_TESTS_DIR:=.}
	;;
*)	# Invoked from installed tests directory.
	: ${TASK_MODULE_DIR:=__TASK_MODULE_DIR__}
	: ${TASK_TESTS_DIR:=__TASK_TESTS_DIR__}
	;;
esac

. ${TASK_MODULE_DIR}/load.subr

# Use the same TASK_MODULE_DIR for all test scripts.
export TASK_MODULE_DIR="${TASK_MODULE_DIR}"

# Use the same TASK_TEST_DIR for all test scripts.
export TASK_TESTS_DIR="${TASK_TESTS_DIR}"

task_load say

run_tests()
{
	local quiet="-q"
	local arg
	local OPTIND=1
	while getopts ":s:v" arg "$@"; do
		case $arg in
		v)	quiet= ;;
		*)	return 127 ;;
		esac
	done
	shift $(( ${OPTIND} - 1 ))

	local suffix
	case $0 in
	*.sh)	suffix=".sh" ;;
	*)	suffix= ;;
	esac

	# glob pattern to match test scripts
	local test_pattern="${TASK_TESTS_DIR}/t_*$suffix"

	[ $# -gt 0 ] || set -- $test_pattern

	local count=0
	local missing=
	local failures=

	local script
	local script_args
	while [ $# -gt 0 ]; do
		script=$1; shift
		if ! [ -f "$script" ]; then
			missing="$missing $script"
			continue
		fi
		case $script in
		*/*)	name=${script##*/}
			: "script unchanged" ;;
		*)	name=$script
			script="./$script" ;;
		esac

		# Set up the script parameters.  If the next parameter is
		# "--", then all remaining arguments are used as parameters
		# for the script.
		#
		script_args="$quiet"
		if [ "$1" = "--" ]; then
			shift
			script_args="$@"
			# shift away the remaining arguments so the loop will end
			shift $#
		fi

		count=$(( $count + 1 ))
		task_say info "*** $name ***"
		#
		# Run the test scripts by explicitly loading load.subr,
		# setting up the parameters, and sourcing the script file,
		# all within a subshell.  This allows the test scripts to be
		# run without being built.
		#
		( . ${TASK_MODULE_DIR}/load.subr
		  set -- dummy $script_args; shift
		  . $script )
		[ $? -eq 0 ] || failures="$failures $name"
	done

	set -o noglob; set -- $missing; set +o noglob
	for script; do
		task_say warn "# run_tests: missing: $script"
	done

	set -o noglob; set -- $failures; set +o noglob
	for script; do
		task_say error "# run_tests: failed: $script"
	done

	local msg="$count test script(s)"
	if [ $# -gt 0 ]; then
		task_say error "# run_tests: failed $# among $msg"
	else
		task_say pass "# run_tests: passed all $msg"
	fi

	return $#
}

run_tests "$@"
