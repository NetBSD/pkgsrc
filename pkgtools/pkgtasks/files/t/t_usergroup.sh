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

task_load unittest
task_load usergroup
task_load usergroup_mock

# If this script is not directly included by another script, then define
# mock platform_groupadd() and platform_useradd() functions needed by
# usergroup.subr.
#
if [ -z "$__platform_usergroup__" ]; then
	platform_groupadd()
	{
		mock_groupadd "$@"
	}

	platform_useradd()
	{
		mock_useradd "$@"
	}
fi

test_setup()
{
	ETC_GROUP="${TEST_CURDIR}/etc.group"
	ETC_PASSWD="${TEST_CURDIR}/etc.master.passwd"
	mock_usergroup_setup

	existent_gid=110
	existent_group="groupB"
	nonexistent_gid=300
	nonexistent_group="groupG"

	existent_uid=110
	existent_user="userB"
	nonexistent_uid=300
	nonexistent_user="userG"

	# Run any platform-specific setup.
	if task_is_function platform_test_setup; then
		platform_test_setup
	fi
}

test_teardown()
{
	# Run any platform-specific teardown.
	if task_is_function platform_test_teardown; then
		platform_test_teardown
	fi
}

test1()
{
	describe="nonexistent group, no groupid"
	if task_addgroup "$nonexistent_group"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test2()
{
	describe="nonexistent group, nonexistent groupid"
	if task_addgroup "$nonexistent_group" "$nonexistent_gid"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test3()
{
	describe="nonexistent group, existent groupid"
	if task_addgroup "$nonexistent_group" "$existent_gid"; then
		return 1
	fi
	return 0
}

test4()
{
	describe="existent group, no groupid"
	if task_addgroup "$existent_group"; then
		return 1
	fi
	return 0
}

test5()
{
	describe="existent group, nonexistent groupid"
	if task_addgroup "$existent_group" "$nonexistent_gid"; then
		return 1
	fi
	return 0
}

test6()
{
	describe="existent group, existent groupid"
	if task_addgroup "$existent_group" "$existent_gid"; then
		return 1
	fi
	return 0
}

test7()
{
	describe="nonexistent user, no userid"
	if task_adduser "$nonexistent_user" "$existent_group"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test8()
{
	describe="nonexistent user, nonexistent userid"
	if task_adduser "$nonexistent_user" "$existent_group" "$nonexistent_uid"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test9()
{
	describe="nonexistent user, existent userid"
	if task_adduser "$nonexistent_user" "$existent_group" "$existent_uid"; then
		return 1
	fi
	return 0
}

test10()
{
	describe="existent user, no userid"
	if task_adduser "$existent_user" "$existent_group"; then
		return 1
	fi
	return 0
}

test11()
{
	describe="existent user, nonexistent userid"
	if task_adduser "$existent_user" "$existent_group" "$nonexistent_uid"; then
		return 1
	fi
	return 0
}

test12()
{
	describe="existent user, existent userid"
	if task_adduser "$existent_user" "$existent_group" "$existent_uid"; then
		return 1
	fi
	return 0
}

task_run_tests "$@"
