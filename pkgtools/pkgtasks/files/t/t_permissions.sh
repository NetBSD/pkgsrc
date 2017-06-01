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
task_load permissions
task_load unittest

test_setup()
{
	: ${LS:=ls}

	PKG_PREFIX=${TEST_CURDIR}
	PKG_DESTDIR=
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}"
}

test1()
{
	describe="missing file"
	echo "# PERMS: file1 0444" | task_permissions check-add
	if echo "# PERMS: file1 0444" | task_permissions add; then
		return 1
	fi
	return 0
}

test2()
{
	describe="change only file mode"
	task_createfile file1
	echo "# PERMS: file1 0444" | task_permissions add
	echo "# PERMS: file1 0444" | task_permissions check-add
	if task_check_permissions file1 0444; then
		: "success"
	else
		describe="$describe: file1"
		${LS} -ln file1 |
		( read mode
		  if [ "$mode" != "-r--r--r--" ]; then
			describe="$describe: wrong mode \`$mode'"
			return 1
		  fi ) || return 1
	fi
	return 0
}

test3()
{
	describe="change to root/wheel"
	task_requires_root || return 0
	task_createfile file1
	echo "# PERMS: file1 0600 root wheel" | task_permissions add
	echo "# PERMS: file1 0600 root wheel" | task_permissions check-add
	if task_check_permissions file1 0600 root wheel; then
		: "success"
	else
		describe="$describe: file1"
		${LS} -ln file1 |
		( read mode x owner group x;
		  if [ "$mode" != "-rw-------" ]; then
			describe="$describe: wrong mode \`$mode'"
			return 1
		  fi
		  if [ "$owner" != 0 ]; then
			describe="$describe: wrong owner \`$owner'"
			return 1
		  fi
		  if [ "$group" != 0 ]; then
			describe="$describe: wrong group \`$group'"
			return 1
		  fi ) || return 1
	fi
	return 0
}

test4()
{
	describe="missing file with PKG_DESTDIR"
	test_destdir_setup
	echo "# PERMS: file1 0444" | task_permissions check-add
	if echo "# PERMS: file1 0444" | task_permissions add; then
		return 1
	fi
	return 0
}

test5()
{
	describe="change only file mode with PKG_DESTDIR"
	test_destdir_setup
	local file="${PKG_DESTDIR}${PKG_PREFIX}/file1"
	task_createfile $file
	echo "# PERMS: file1 0444" | task_permissions add
	echo "# PERMS: file1 0444" | task_permissions check-add
	if task_check_permissions "$file" 0444; then
		: "success"
	else
		describe="$describe: $file"
		${LS} -ln "$file" |
		( read mode
		  if [ "$mode" != "-r--r--r--" ]; then
			describe="$describe: wrong mode \`$mode'"
			return 1
		  fi ) || return 1
	fi
	return 0
}

test6()
{
	describe="change to root/wheel with PKG_DESTDIR"
	task_requires_root || return 0
	test_destdir_setup
	local file="${PKG_DESTDIR}${PKG_PREFIX}/file1"
	task_createfile "$file"
	echo "# PERMS: file1 0600 root wheel" | task_permissions add
	echo "# PERMS: file1 0600 root wheel" | task_permissions check-add
	if task_check_permissions "$file" 0600 root wheel; then
		: "success"
	else
		describe="$describe: $file"
		${LS} -ln "$file" |
		( read mode x owner group x;
		  if [ "$mode" != "-rw-------" ]; then
			describe="$describe: wrong mode \`$mode'"
			return 1
		  fi
		  if [ "$owner" != 0 ]; then
			describe="$describe: wrong owner \`$owner'"
			return 1
		  fi
		  if [ "$group" != 0 ]; then
			describe="$describe: wrong group \`$group'"
			return 1
		  fi ) || return 1
	fi
	return 0
}

task_run_tests "$@"
