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

task_load createfile
task_load preinstall
task_load unittest

test_setup()
{
	datafile="empty"
	task_createfile "$datafile"

	TASK_DIRECTORIES_SUCCESS="yes"
	TASK_FUNCTION_SUCCESS="yes"
	TASK_GROUPS_SUCCESS="yes"
	TASK_USERS_SUCCESS="yes"
}

# Mock actions that return the truthiness of environment variables.
task_directories()
{
	[ "${TASK_DIRECTORIES_SUCCESS}" = "yes" ]
}

task_function()
{
	[ "${TASK_FUNCTION_SUCCESS}" = "yes" ]
}

task_groups()
{
	[ "${TASK_GROUPS_SUCCESS}" = "yes" ]
}

task_users()
{
	[ "${TASK_USERS_SUCCESS}" = "yes" ]
}

test1()
{
	describe="dirs fail"
	TASK_DIRECTORIES_SUCCESS="no"
	if task_preinstall "$datafile"; then
		: "dirs errors in preinstall are non-fatal"
	else
		return 1
	fi
	return 0
}

test2()
{
	describe="function fail"
	TASK_FUNCTION_SUCCESS="no"
	if task_preinstall "$datafile"; then
		return 1
	fi
	return 0
}

test3()
{
	describe="groups fail"
	TASK_GROUPS_SUCCESS="no"
	if task_preinstall "$datafile"; then
		return 1
	fi
	return 0
}

test4()
{
	describe="users fail"
	TASK_USERS_SUCCESS="no"
	if task_preinstall "$datafile"; then
		return 1
	fi
	return 0
}

test5()
{
	describe="all succeed"
	if task_preinstall "$datafile"; then
		: "success"
	else
		return 1
	fi
	return 0
}

task_run_tests "$@"
