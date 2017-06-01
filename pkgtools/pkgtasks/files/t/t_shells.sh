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
task_load shells
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${MKDIR:=mkdir}

	PKG_PREFIX="${TEST_CURDIR}"
	PKG_DESTDIR=

	shelldb="etc/shells"
	shelldb_lock="$shelldb.lock"

	datafile="datafile"
	${CAT} > $datafile << EOF
# SHELL: bin/pdksh $shelldb
# SHELL: bin/bash $shelldb
# SHELL: ${PKG_PREFIX}/bin/pdksh $shelldb
EOF

	${MKDIR} -p etc
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}"
	${MV} etc "${PKG_DESTDIR}${PKG_PREFIX}"
}

test1()
{
	describe="check-add shells with empty shell database"
	if task_shells check-add < $datafile; then
		return 1
	fi
	return 0
}

test2()
{
	describe="add shells"
	if task_shells add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test3()
{
	describe="verify uniqueness"
	task_shells add < $datafile
	local count=0
	local line
	while read line; do
		case $line in
		*/pdksh*) count="$count + 1" ;;
		esac
	done < $shelldb
	count=$(( $count ))
	if [ $count -gt 1 ]; then
		describe="$describe: too many pdksh!"
		return 1
	fi
	if [ -f "$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test4()
{
	describe="check-add shells with all shells added"
	task_shells add < $datafile
	if task_shells check-add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test5()
{
	describe="check-remove shells with no shells removed"
	task_shells add < $datafile
	if task_shells check-remove < $datafile; then
		return 1
	fi
	if [ -f "$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test6()
{
	describe="remove shells"
	task_shells add < $datafile
	if task_shells remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test7()
{
	describe="verify empty shell database"
	task_shells add < $datafile
	task_shells remove < $datafile
	local count=0
	while read line; do
		count="$count + 1"
	done < $shelldb
	count=$(( $count ))
	if [ $count -gt 0 ]; then
		return 1
	fi
	return 0
}

test8()
{
	describe="check-remove shells with empty shell database"
	task_createfile "$shelldb"
	if task_shells check-remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test9()
{
	describe="add shells with PKG_DESTDIR"
	test_destdir_setup
	if task_shells add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

test10()
{
	describe="verify uniqueness with PKG_DESTDIR"
	test_destdir_setup
	task_shells add < $datafile
	local count=0
	local line
	while read line; do
		case $line in
		*/pdksh*) count="$count + 1" ;;
		esac
	done < "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb"
	count=$(( $count ))
	if [ $count -gt 1 ]; then
		describe="$describe: too many pdksh!"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

test11()
{
	describe="check-add shells with all shells added with PKG_DESTDIR"
	test_destdir_setup
	task_shells add < $datafile
	if task_shells check-add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

test12()
{
	describe="check-remove shells with no shells removed with PKG_DESTDIR"
	test_destdir_setup
	task_shells add < $datafile
	if task_shells check-remove < $datafile; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

test13()
{
	describe="remove shells with PKG_DESTDIR"
	test_destdir_setup
	task_shells add < $datafile
	if task_shells remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

test14()
{
	describe="verify empty shell database"
	test_destdir_setup
	task_shells add < $datafile
	task_shells remove < $datafile
	local count=0
	while read line; do
		count="$count + 1"
	done < "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb"
	count=$(( $count ))
	if [ $count -gt 0 ]; then
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

test15()
{
	describe="check-remove shells with empty shell database"
	test_destdir_setup
	task_createfile "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb"
	if task_shells check-remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$shelldb_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$shelldb" ]; then
		describe="$describe: $shelldb exists!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
