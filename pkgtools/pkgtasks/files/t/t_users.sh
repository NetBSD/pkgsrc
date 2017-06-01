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
task_load users

# Mock platform_useradd() needed by usergroup.subr, and task_user_exists()
# needed by users.subr.
#
platform_useradd()
{
	mock_useradd "$@"
}

task_user_exists()
{
	mock_user_exists "$@"
}

test_setup()
{
	: ${CAT:=cat}
	: ${MKDIR:=mkdir}

	PKG_DBDIR="${TEST_CURDIR}/var/db/pkg"
	PKG_REFCOUNT_DBDIR="${PKG_DBDIR}.refcount"
	${MKDIR} -p "${PKG_DBDIR}"

	ETC_GROUP="${TEST_CURDIR}/etc.group"
	ETC_PASSWD="${TEST_CURDIR}/etc.passwd"
	mock_usergroup_setup

	datafile="datafile"
	${CAT} > $datafile << EOF
# USER: userD:groupD
# USER: userE:groupE:200
# USER: userF:groupF:205
EOF
}

test1()
{
	describe="check-add missing users"
	if task_users check-add < $datafile; then
		return 1
	fi
	return 0
}

test2()
{
	describe="add nonexistent users"
	if task_users add < $datafile; then
		: "success"
	else
		return 1
	fi
	local name
	for name in userD userE userF; do
		if task_user_exists "$name"; then
			: "success"
		else
			describe="$describe: missing $name"
			return 1
		fi
	done
	return 0
}

test3()
{
	describe="add existent and nonexistent users"
	task_adduser userE groupE 200
	if task_users add < $datafile; then
		: "success"
	else
		return 1
	fi
	local name
	for name in userD userE userF; do
		if task_user_exists "$name"; then
			: "success"
		else
			describe="$describe: missing $name"
			return 1
		fi
	done
	return 0
}

test4()
{
	describe="add conflicting user"
	task_adduser userE groupE 300
	if task_users add < $datafile; then
		return 1
	fi
	return 0
}

test5()
{
	describe="check-add users with all users added"
	task_users add < $datafile
	if task_users check-add < $datafile; then
		: "success"
	else
		return 1
	fi
	return 0
}

test6()
{
	describe="check-remove users with no users removed"
	task_users add < $datafile
	if task_users check-remove < $datafile; then
		return 1
	fi
	return 0
}

test7()
{
	describe="remove existent users"
	task_users add < $datafile
	# This always returns 0 because no users are ever removed.
	if task_users remove < $datafile; then
		: "success"
	else
		return 1
	fi
	local name
	for name in userD userE userF; do
		# No users should have been removed.
		if task_user_exists "$name"; then
			: "success"
		else
			describe="$describe: missing $name"
			return 1
		fi
	done
	return 0
}

test8()
{
	describe="remove nonexistent users"
	# This always returns 0 because no users are ever removed.
	if task_users remove < $datafile; then
		: "success"
	else
		return 1
	fi
	return 0
}

test9()
{
	describe="check-remove users with users already removed"
	if task_users check-remove < $datafile; then
		: "success"
	else
		return 1
	fi
	return 0
}

task_run_tests "$@"
