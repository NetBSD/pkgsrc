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
task_load usergroup_mock

test_setup()
{
	ETC_GROUP="${TEST_CURDIR}/etc.group"
	ETC_PASSWD="${TEST_CURDIR}/etc.passwd"
	mock_usergroup_setup

	existent_gid=110
	existent_group="groupB"
	matching_gid=105
	nonexistent_gid=300
	nonexistent_group="groupG"

	existent_uid=110
	existent_user="userB"
	matching_gid=105
	nonexistent_uid=200
	nonexistent_user="userD"
}

test1()
{
	describe="exists: nonexistent group, no groupid"
	mock_group_exists $nonexistent_group
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test2()
{
	describe="exists: nonexistent group, nonexistent groupid"
	mock_group_exists $nonexistent_group $nonexistent_gid
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test3()
{
	describe="exists: nonexistent group, existent groupid"
	mock_group_exists $nonexistent_group $existent_gid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test4()
{
	describe="exists: existent group, no groupid"
	mock_group_exists $existent_group
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test5()
{
	describe="exists: existent group, nonexistent groupid"
	mock_group_exists $existent_group $nonexistent_gid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test6()
{
	describe="exists: existent group, existent groupid"
	mock_group_exists $existent_group $existent_gid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test7()
{
	describe="exists: existent group, matching groupid"
	mock_group_exists $existent_group $matching_gid
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test8()
{
	describe="exists: nonexistent user, no userid"
	mock_user_exists $nonexistent_user
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test9()
{
	describe="exists: nonexistent user, nonexistent userid"
	mock_user_exists $nonexistent_user $nonexistent_uid
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test10()
{
	describe="exists: nonexistent user, existent userid"
	mock_user_exists $nonexistent_user $existent_uid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test11()
{
	describe="exists: existent user, no userid"
	mock_user_exists $existent_user
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test12()
{
	describe="exists: existent user, nonexistent userid"
	mock_user_exists $existent_user $nonexistent_uid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test13()
{
	describe="exists: existent user, existent userid"
	mock_user_exists $existent_user $existent_uid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test14()
{
	describe="exists: existent user, matching userid"
	mock_user_exists $existent_user $matching_uid
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test15()
{
	describe="add: nonexistent group, no groupid"
	if mock_groupadd "$nonexistent_group"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test16()
{
	describe="add: nonexistent group, nonexistent groupid"
	if mock_groupadd -g "$nonexistent_gid" "$nonexistent_group"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test17()
{
	describe="add: nonexistent group, existent groupid"
	if mock_groupadd -g "$existent_gid" "$nonexistent_group"; then
		return 1
	fi
	return 0
}

test18()
{
	describe="add: existent group, no groupid"
	if mock_groupadd "$existent_group"; then
		return 1
	fi
	return 0
}

test19()
{
	describe="add: existent group, nonexistent groupid"
	if mock_groupadd -g "$nonexistent_gid" "$existent_group"; then
		return 1
	fi
	return 0
}

test20()
{
	describe="add: existent group, existent groupid"
	if mock_groupadd -g "$existent_gid" "$existent_group"; then
		return 1
	fi
	return 0
}

test21()
{
	describe="add: nonexistent user, no userid"
	if mock_useradd -g "$existent_group" "$nonexistent_user"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test22()
{
	describe="add: nonexistent user, nonexistent userid"
	if mock_useradd -g "$existent_group" -u "$nonexistent_uid" "$nonexistent_user"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test23()
{
	describe="add: nonexistent user, existent userid"
	if mock_useradd -g "$existent_group" -u "$existent_uid" "$nonexistent_user"; then
		return 1
	fi
	return 0
}

test24()
{
	describe="add: existent user, no userid"
	if mock_useradd -g "$existent_group" "$existent_user"; then
		return 1
	fi
	return 0
}

test25()
{
	describe="add: existent user, nonexistent userid"
	if mock_useradd -g "$existent_group" -u "$nonexistent_uid" "$existent_user"; then
		return 1
	fi
	return 0
}

test26()
{
	describe="add: existent user, existent userid"
	if mock_useradd -g "$existent_group" -u "$existent_uid" "$existent_user"; then
		return 1
	fi
	return 0
}

task_run_tests "$@"
