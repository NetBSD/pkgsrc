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

task_load groups
task_load unittest
task_load usergroup_mock

# Mock platform_groupadd() needed by usergroup.subr, and task_group_exists()
# needed by groups.subr.
#
platform_groupadd()
{
	mock_groupadd "$@"
}

task_group_exists()
{
	mock_group_exists "$@"
}

test_setup()
{
	: ${CAT:=cat}
	: ${MKDIR:=mkdir}

	PKG_DBDIR="${TEST_CURDIR}/var/db/pkg"
	PKG_REFCOUNT_DBDIR="${PKG_DBDIR}.refcount"
	${MKDIR} -p "${PKG_DBDIR}"

	ETC_GROUP="${TEST_CURDIR}/etc.group"
	mock_usergroup_setup

	datafile="datafile"
	${CAT} > $datafile << EOF
# GROUP: groupG
# GROUP: groupH:300
# GROUP: groupI:305
EOF
}

test1()
{
	describe="check-add missing groups"
	if task_groups check-add < $datafile; then
		return 1
	fi
	return 0
}

test2()
{
	describe="add nonexistent groups"
	if task_groups add < $datafile; then
		: "success"
	else
		return 1
	fi
	local name
	for name in groupG groupH groupI; do
		if task_group_exists "$name"; then
			: "success"
		else
			describe="$describe: missing $name!"
			return 1
		fi
	done
	return 0
}

test3()
{
	describe="add existent and nonexistent groups"
	task_addgroup groupH 300
	if task_groups add < $datafile; then
		: "success"
	else
		return 1
	fi
	local name
	for name in groupG groupH groupI; do
		if task_group_exists "$name"; then
			: "success"
		else
			describe="$describe: missing $name!"
			return 1
		fi
	done
	return 0
}

test4()
{
	describe="add conflicting group"
	task_addgroup groupH 3000
	if task_groups add < $datafile; then
		return 1
	fi
	return 0
}

test5()
{
	describe="check-add groups with all groups added"
	task_groups add < $datafile
	if task_groups check-add < $datafile; then
		: "success"
	else
		return 1
	fi
	return 0
}

test6()
{
	describe="check-remove groups with no groups removed"
	task_groups add < $datafile
	if task_groups check-remove < $datafile; then
		return 1
	fi
	return 0
}

test7()
{
	describe="remove existent groups"
	task_groups add < $datafile
	# This always returns 0 because no groups are ever removed.
	if task_groups remove < $datafile; then
		: "success"
	else
		return 1
	fi
	local name
	for name in groupG groupH groupI; do
		# No groups should have been removed.
		if task_group_exists "$name"; then
			: "success"
		else
			describe="$describe: $name remains!"
			return 1
		fi
	done
	return 0
}

test8()
{
	describe="remove nonexistent groups"
	# This always returns 0 because no groups are ever removed.
	if task_groups remove < $datafile; then
		: "success"
	else
		return 1
	fi
	return 0
}

test9()
{
	describe="check-remove groups with groups already removed"
	if task_groups check-remove < $datafile; then
		: "success"
	else
		return 1
	fi
	return 0
}

task_run_tests "$@"
