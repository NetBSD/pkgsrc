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

task_load quote
task_load unittest
task_load usergroup_mock

# Mock uname() to select usergroup_Linux.subr.
uname()
{
	echo "Linux"
}

# Mock groupadd and useradd needed for usergroup_Linux.subr.
groupadd()
{
	# Skip "-r" and pass all other options through to mock_groupadd().
	local groupadd_args=
	local quoted
	local arg
	local OPTIND=1
	while getopts ":g:r" arg "$@"; do
		case $arg in
		g)	task_quote "${OPTARG}"
			groupadd_args="$groupadd_args -$arg $quoted" ;;
		r)	: "silently accept" ;;
		*)	return 127 ;;
		esac
	done
	shift $(( ${OPTIND} - 1 ))
	[ $# -eq 1 ] || return 127
	local group="$1"; shift

	[ -n "$group" ] || return 1
	task_quote "$group"
	groupadd_args="$groupadd_args $quoted"

	eval mock_groupadd $groupadd_args
}

useradd()
{
	# Skip "-M" and "-r" and pass all other options through to
	# mock_useradd().
	#
	local useradd_args=
	local quoted
	local arg
	local OPTIND=1
	while getopts ":c:d:g:Mrs:u:" arg "$@"; do
		case $arg in
		[Mr])	: "silently accept" ;;
		[cdgsu])
			task_quote "${OPTARG}"
			useradd_args="$useradd_args -$arg $quoted" ;;
		*)	return 127 ;;
		esac
	done
	shift $(( ${OPTIND} - 1 ))
	[ $# -eq 1 ] || return 127
	local user="$1"; shift

	[ -n "$user" ] || return 1
	task_quote "$user"
	useradd_args="$useradd_args $quoted"

	eval mock_useradd $useradd_args
}

platform_test_setup()
{
	LOGIN_DEFS="${TEST_CURDIR}/etc.login.defs"
	echo "CREATE_HOME	yes" > ${LOGIN_DEFS}
}

__platform_usergroup__="yes"

task_load_test t_usergroup "$@"
