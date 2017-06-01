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
task_load ocaml_findlib
task_load unittest

test_setup()
{
	: ${CAT:=cat}

	PKG_PREFIX=${TEST_CURDIR}
	PKG_DESTDIR=

	ldconf="ld.conf"
	ldconf_lock="$ldconf.lock"

	datafile="datafile"
	${CAT} > $datafile << EOF
# FINDLIB: pcre $ldconf
# FINDLIB: base64 $ldconf
# FINDLIB: expat $ldconf
# FINDLIB: pcre $ldconf
EOF
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
	describe="check-add findlib dirs with empty ld.conf"
	if task_ocaml_findlib check-add < $datafile; then
		return 1
	fi
	return 0
}

test2()
{
	describe="add findlib dirs"
	if task_ocaml_findlib add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ ! -f "$ldconf" ]; then
		describe="$describe: $ldconf missing!"
		return 1
	fi
	if [ -f "$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test3()
{
	describe="verify uniqueness"
	task_ocaml_findlib add < $datafile
	local count=0
	local line
	while read line; do
		case $line in
		*/pcre)	count="$count + 1" ;;
		esac
	done < $ldconf
	count=$(( $count ))
	if [ $count -gt 1 ]; then
		describe="$describe: too many pcre!"
		return 1
	fi
	if [ -f "$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test4()
{
	describe="check-add findlib dirs with all dirs added"
	task_ocaml_findlib add < $datafile
	if task_ocaml_findlib check-add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test5()
{
	describe="check-remove findlib dirs with no dirs removed"
	task_ocaml_findlib add < $datafile
	if task_ocaml_findlib check-remove < $datafile; then
		return 1
	fi
	if [ -f "$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test6()
{
	describe="remove findlib dirs"
	task_ocaml_findlib add < $datafile
	if task_ocaml_findlib remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test7()
{
	describe="verify empty ld.conf"
	task_ocaml_findlib add < $datafile
	task_ocaml_findlib remove < $datafile
	local count=0
	local line
	while read line; do
		count="$count + 1"
	done < $ldconf
	count=$(( $count ))
	if [ $count -gt 0 ]; then
		return 1
	fi
	return 0
}

test8()
{
	describe="check-remove findlib dirs with empty ld.conf"
	task_createfile "$ldconf"
	if task_ocaml_findlib check-remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	return 0
}

test9()
{
	describe="add findlib dirs with PKG_DESTDIR"
	test_destdir_setup
	if task_ocaml_findlib add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf" ]; then
		describe="$describe: ${PKG_DESTDIR}${PKG_PREFIX}/$ldconf missing!"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

test10()
{
	describe="verify uniqueness with PKG_DESTDIR"
	test_destdir_setup
	task_ocaml_findlib add < $datafile
	local count=0
	local line
	while read line; do
		case $line in
		*/pcre)	count="$count + 1" ;;
		esac
	done < ${PKG_DESTDIR}${PKG_PREFIX}/$ldconf
	count=$(( $count ))
	if [ $count -gt 1 ]; then
		describe="$describe: too many pcre!"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

test11()
{
	describe="check-add findlib dirs with all dirs added with PKG_DESTDIR"
	test_destdir_setup
	task_ocaml_findlib add < $datafile
	if task_ocaml_findlib check-add < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

test12()
{
	describe="check-remove findlib dirs with no dirs removed with PKG_DESTDIR"
	test_destdir_setup
	task_ocaml_findlib add < $datafile
	if task_ocaml_findlib check-remove < $datafile; then
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

test13()
{
	describe="remove findlib dirs with PKG_DESTDIR"
	test_destdir_setup
	task_ocaml_findlib add < $datafile
	if task_ocaml_findlib remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

test14()
{
	describe="verify empty ld.conf with PKG_DESTDIR"
	test_destdir_setup
	task_ocaml_findlib add < $datafile
	task_ocaml_findlib remove < $datafile
	local count=0
	local line
	while read line; do
		count="$count + 1"
	done < ${PKG_DESTDIR}${PKG_PREFIX}/$ldconf
	count=$(( $count ))
	if [ $count -gt 0 ]; then
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

test15()
{
	describe="check-remove findlib dirs with empty ld.conf with PKG_DESTDIR"
	test_destdir_setup
	task_createfile "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf"
	if task_ocaml_findlib check-remove < $datafile; then
		: "success"
	else
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/$ldconf_lock" ]; then
		describe="$describe: lock exists!"
		return 1
	fi
	if [ -f "$ldconf" ]; then
		describe="$describe: $ldconf exists!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
