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
task_load info_files
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${GREP:=grep}
	: ${MKDIR:=mkdir}

	PKG_PREFIX=${TEST_CURDIR}
	PKG_DESTDIR=

	infodir="info"
	testinfo="$infodir/test.info"
	dirfile="$infodir/dir"

	${MKDIR} "$infodir"
	${CAT} > "$testinfo" << 'EOF'
INFO-DIR-SECTION Test section
START-INFO-DIR-ENTRY
* t_info-files: (test).		Test info-files.sh.
END-INFO-DIR-ENTRY
EOF
}

test_destdir_setup()

{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}"
	${MV} info "${PKG_DESTDIR}${PKG_PREFIX}"
}

test1()
{
	describe="missing dir file on remove"
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	return 0
}

test2()
{
	describe="missing dir file on add"
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile missing!"
		return 1
	fi
	return 0
}

test3()
{
	describe="empty dir file on remove"
	task_createfile "$dirfile"
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -eq 0 ]; then
		return 1
	fi
	if [ -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	return 0
}

test4()
{
	describe="empty dir file on add"
	task_createfile "$dirfile"
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -eq 0 ]; then
		return 1
	fi
	if [ -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	return 0
}

test5()
{
	describe="invalid dir file on remove"
	echo "asdf" > $dirfile
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	return 0
}

test6()
{
	describe="invalid dir file on add"
	echo "asdf" > $dirfile
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	return 0
}

test7()
{
	describe="remove nonexistent info file from missing dir file"
	echo "# INFO: /nonexistent.info $infodir" | task_info_files remove
	if [ $? -eq 0 ]; then
		return 1
	fi
	return 0
}

test8()
{
	describe="add info file to missing dir file"
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: no dir!"
		return 1
	fi
	return 0
}

test9()
{
	describe="remove info file after successful add"
	echo "# INFO: $testinfo $infodir" | task_info_files add
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	return 0
}

test10()
{
	describe="add info file more than once"
	task_info_files add << EOF
# INFO: $testinfo $infodir
# INFO: $testinfo $infodir
# INFO: $testinfo $infodir
# INFO: $testinfo $infodir
EOF
	if [ $? -gt 0 ]; then
		return 1
	fi
	local count
	count=$( ${GREP} -c '^\* t_info-files:' "$dirfile" )
	if [ $count -gt 1 ]; then
		describe="$describe: $count"
		return 1
	fi
	return 0
}

test11()
{
	describe="missing dir file on remove with PKG_DESTDIR"
	test_destdir_setup
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test12()
{
	describe="missing dir file on add with PKG_DESTDIR"
	test_destdir_setup
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile missing!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test13()
{
	describe="empty dir file on remove with PKG_DESTDIR"
	test_destdir_setup
	task_createfile "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile"
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -eq 0 ]; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test14()
{
	describe="empty dir file on add with PKG_DESTDIR"
	test_destdir_setup
	task_createfile "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile"
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -eq 0 ]; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test15()
{
	describe="invalid dir file on remove with PKG_DESTDIR"
	test_destdir_setup
	echo "asdf" > "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile"
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test16()
{
	describe="invalid dir file on add with PKG_DESTDIR"
	test_destdir_setup
	echo "asdf" > "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile"
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test17()
{
	describe="remove nonexistent info file from missing dir file with PKG_DESTDIR"
	test_destdir_setup
	echo "# INFO: /nonexistent.info $infodir" | task_info_files remove
	if [ $? -eq 0 ]; then
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test18()
{
	describe="add info file to missing dir file with PKG_DESTDIR"
	test_destdir_setup
	echo "# INFO: $testinfo $infodir" | task_info_files add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: no dir!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test19()
{
	describe="remove info file after successful add with PKG_DESTDIR"
	test_destdir_setup
	echo "# INFO: $testinfo $infodir" | task_info_files add
	echo "# INFO: $testinfo $infodir" | task_info_files remove
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$dirfile exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

test20()
{
	describe="add info file more than once with PKG_DESTDIR"
	test_destdir_setup
	task_info_files add << EOF
# INFO: $testinfo $infodir
# INFO: $testinfo $infodir
# INFO: $testinfo $infodir
# INFO: $testinfo $infodir
EOF
	if [ $? -gt 0 ]; then
		return 1
	fi
	local count
	count=$( ${GREP} -c '^\* t_info-files:' "${PKG_DESTDIR}${PKG_PREFIX}/$dirfile" )
	if [ $count -gt 1 ]; then
		describe="$describe: $count"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$infodir" ]; then
		describe="$describe: ${PKG_PREFIX}/$infodir exists!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
