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

# Mock uname() to select usergroup_MirBSD.subr.
uname()
{
	echo "MirBSD"
}

task_load unittest
task_load usergroup

test_setup()
{
	: ${CAT:=cat}
	: ${GREP:=grep}
	: ${MV:=mv}

	ETC_GROUP="${TEST_CURDIR}/etc.group"
	${CAT} > ${ETC_GROUP} << EOF
groupA:*:100:
groupB:*:105:
groupC:*:110:
EOF
	existent_gid=110
	existent_group="groupB"
	matching_gid=105
	nonexistent_gid=300
	nonexistent_group="groupG"

	ETC_PASSWD="${TEST_CURDIR}/etc.master.passwd"
	${CAT} > ${ETC_PASSWD} << EOF
userA:*:100:100::0:0:package A user:/nonexistent:/bin/sh
userB:*:105:105::0:0:package B user:/nonexistent:/bin/sh
userC:*:110:110::0:0:package C user:/nonexistent:/bin/sh
EOF
	existent_uid=110
	existent_user="userB"
	nonexistent_uid=300
	nonexistent_user="userG"

	# Set CHOWN and PWD_MKDB to "working" mocks.
	CHOWN="chown"
	PWD_MKDB="pwd_mkdb"
}

# Mock utilities needed by MirBSD platform_groupadd() and platform_useradd().
chown()
{
	return 0
}

mock_false()
{
	return 1
}

pwd_mkdb()
{
	local arg
	local OPTIND=1
	while getopts ":cd:psu:" arg "$@"; do
		case $arg in
		[cpsdu])
			: "silently ignore" ;;
		*)	return 127 ;;
		esac
	done
	shift $(( ${OPTIND} - 1 ))
	[ $# -gt 0 ] || return 127

	${MV} -f "$1" "${ETC_PASSWD}"
}

test1()
{
	describe="nonexistent group, no groupid"
	if task_addgroup "$nonexistent_group"; then
		: "success"
	else
		return 1
	fi
	if ${GREP} -q "^$nonexistent_group:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group missing!"
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
	if ${GREP} -q "^$nonexistent_group:[^:]*:$nonexistent_gid:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group missing!"
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
	if ${GREP} -q "^$nonexistent_group:" "${ETC_GROUP}"; then
		describe="$describe: group exists!"
		return 1
	fi
	if ${GREP} -q "^[^:]*:[^:]*:$existent_gid:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group ID missing!"
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
	if ${GREP} -q "^$existent_group:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group missing!"
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
	if ${GREP} -q "^$existent_group:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group missing!"
		return 1
	fi
	if ${GREP} -q "^[^:]*:[^:]*:$nonexistent_gid:" "${ETC_GROUP}"; then
		describe="$describe: group ID exists!"
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
	if ${GREP} -q "^$existent_group:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group missing!"
		return 1
	fi
	if ${GREP} -q "^[^:]*:[^:]*:$existent_gid:" "${ETC_GROUP}"; then
		: "success"
	else
		describe="$describe: group ID missing!"
		return 1
	fi
	return 0
}

test7()
{
	describe="broken chown(8) when adding group"
	CHOWN="mock_false"
	if task_addgroup "$nonexistent_group"; then
		return 1
	fi
	if ${GREP} -q "^$nonexistent_group:" "${ETC_GROUP}"; then
		describe="$describe: group exists!"
		return 1
	fi
	set -- ${ETC_GROUP}.tmp.*
	case $1 in
	"${ETC_GROUP}.tmp.*")
		: "group tmpdir not found" ;;
	*)	describe="$describe: group tmpdir exists!"
		return 1 ;;
	esac
	return 0
}

test8()
{
	describe="nonexistent user, no userid"
	if task_adduser "$nonexistent_user" "$existent_group"; then
		: "success"
	else
		return 1
	fi
	if ${GREP} -q "^$nonexistent_user:[^:]*:[^:]*:$matching_gid:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user missing!"
		return 1
	fi
	return 0
}

test9()
{
	describe="nonexistent user, nonexistent userid"
	if task_adduser "$nonexistent_user" "$existent_group" "$nonexistent_uid"; then
		: "success"
	else
		return 1
	fi
	if ${GREP} -q "^$nonexistent_user:[^:]*:$nonexistent_uid:$matching_gid:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user missing!"
		return 1
	fi
	return 0
}

test10()
{
	describe="nonexistent user, existent userid"
	if task_adduser "$nonexistent_user" "$existent_group" "$existent_uid"; then
		return 1
	fi
	if ${GREP} -q "^$nonexistent_user:" "${ETC_PASSWD}"; then
		describe="$describe: user exists!"
		return 1
	fi
	if ${GREP} -q "^[^:]*:[^:]*:[^:]*:$existent_uid:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user ID missing!"
		return 1
	fi
	return 0
}

test11()
{
	describe="existent user, no userid"
	if task_adduser "$existent_user" "$existent_group"; then
		return 1
	fi
	if ${GREP} -q "^$existent_user:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user missing!"
		return 1
	fi
	return 0
}

test12()
{
	describe="existent user, nonexistent userid"
	if task_adduser "$existent_user" "$existent_group" "$nonexistent_uid"; then
		return 1
	fi
	if ${GREP} -q "^$existent_user:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user missing!"
		return 1
	fi
	if ${GREP} -q "^[^:]*:[^:]*:[^:]*:$nonexistent_uid:" "${ETC_PASSWD}"; then
		describe="$describe: user ID exists!"
		return 1
	fi
	return 0
}

test13()
{
	describe="existent user, existent userid"
	if task_adduser "$existent_user" "$existent_group" "$existent_uid"; then
		return 1
	fi
	if ${GREP} -q "^$existent_user:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user missing!"
		return 1
	fi
	if ${GREP} -q "^[^:]*:[^:]*:[^:]*:$existent_uid:" "${ETC_PASSWD}"; then
		: "success"
	else
		describe="$describe: user ID missing!"
		return 1
	fi
	return 0
}

test14()
{
	describe="broken chown(8) when adding user"
	CHOWN="mock_false"
	if task_adduser "$nonexistent_user" "$existent_group"; then
		return 1
	fi
	if ${GREP} -q "^$nonexistent_user:" "${ETC_PASSWD}"; then
		describe="$describe: user exists!"
		return 1
	fi
	set -- ${ETC_PASSWD}.tmp.*
	case $1 in
	"${ETC_PASSWD}.tmp.*")
		: "user tmpdir not found" ;;
	*)	describe="$describe: user tmpdir exists!"
		return 1 ;;
	esac
	return 0
}

test15()
{
	describe="broken pwd_mkdb(8) when adding user"
	PWD_MKDB="mock_false"
	if task_adduser "$nonexistent_user" "$existent_group"; then
		return 1
	fi
	if ${GREP} -q "^$nonexistent_user:" "${ETC_PASSWD}"; then
		describe="$describe: user exists!"
		return 1
	fi
	set -- ${ETC_PASSWD}.tmp.*
	case $1 in
	"${ETC_PASSWD}.tmp.*")
		: "user tmpdir not found" ;;
	*)	describe="$describe: user tmpdir exists!"
		return 1 ;;
	esac
	return 0
}

task_run_tests "$@"
