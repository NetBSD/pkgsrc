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
task_load usergroup_exists

test_setup()
{
	: ${MKDIR:=mkdir}

	TMPDIR="${TEST_CURDIR}/tmp"
	${MKDIR} -p "${TMPDIR}"

	# These values may need to be corrected.
	existent_gid=32766
	existent_group="nogroup"
	nonexistent_gid=27777
	nonexistent_group="nonexistent_group"

	existent_uid=32767
	existent_user="nobody"
	nonexistent_uid=27777
	nonexistent_user="nonexistent_user"
}

test1()
{
	describe="nonexistent group, no groupid"
	task_requires_root || return 0
	task_group_exists $nonexistent_group
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test2()
{
	describe="nonexistent group, nonexistent groupid"
	task_requires_root || return 0
	task_group_exists $nonexistent_group $nonexistent_gid
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test3()
{
	describe="nonexistent group, existent groupid"
	task_requires_root || return 0
	task_group_exists $nonexistent_group $existent_gid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test4()
{
	describe="existent group, no groupid"
	task_requires_root || return 0
	task_group_exists $existent_group
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test5()
{
	describe="existent group, nonexistent groupid"
	task_requires_root || return 0
	task_group_exists $existent_group $nonexistent_gid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test6()
{
	describe="existent group, existent groupid"
	task_requires_root || return 0
	task_group_exists $existent_group $existent_gid
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test7()
{
	describe="nonexistent user, no userid"
	task_requires_root || return 0
	task_user_exists $nonexistent_user
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test8()
{
	describe="nonexistent user, nonexistent userid"
	task_requires_root || return 0
	task_user_exists $nonexistent_user $nonexistent_uid
	local result=$?
	if [ $result -ne 1 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test9()
{
	describe="nonexistent user, existent userid"
	task_requires_root || return 0
	task_user_exists $nonexistent_user $existent_uid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test10()
{
	describe="existent user, no userid"
	task_requires_root || return 0
	task_user_exists $existent_user
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test11()
{
	describe="existent user, nonexistent userid"
	task_requires_root || return 0
	task_user_exists $existent_user $nonexistent_uid
	local result=$?
	if [ $result -ne 2 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

test12()
{
	describe="existent user, existent userid"
	task_requires_root || return 0
	task_user_exists $existent_user $existent_uid
	local result=$?
	if [ $result -ne 0 ]; then
		describe="$describe: $result"
		return 1
	fi
	return 0
}

task_run_tests "$@"
