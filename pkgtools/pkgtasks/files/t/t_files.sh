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
task_load files
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CHMOD:=chmod}
	: ${MKDIR:=mkdir}

	PKGNAME=${0##*/}
	PKG_PREFIX=${TEST_CURDIR}
	PKG_DESTDIR=

	PKG_DBDIR="${PKG_PREFIX}/var/db/pkg"
	PKG_REFCOUNT_DBDIR="${PKG_DBDIR}.refcount"
	${MKDIR} -p "${PKG_DBDIR}"

	${MKDIR} -p etc
	${MKDIR} -p etc/rc.d
	${MKDIR} -p share/examples/pkg1
	${MKDIR} -p share/examples/pkg2
	${CAT} > share/examples/pkg2/conffile2 << EOF
line 1
line 2
EOF
	${MKDIR} -p share/examples/rc.d

	# Unwriteable directory.
	${MKDIR} -p unwriteable
	${CHMOD} 0400 unwriteable

	# Don't copy rc.d scripts.
	PKG_INIT_SCRIPTS="no"
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}"
	${MV} etc share var "${PKG_DESTDIR}${PKG_PREFIX}"

	# Unwriteable directory.
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}/unwriteable"
	${CHMOD} 0400 "${PKG_DESTDIR}${PKG_PREFIX}/unwriteable"
}

test1()
{
	describe="missing example file"
	if echo "# FILE: \
		etc/conffile1 c \
		share/examples/pkg1/conffile1" | task_files add; then
		return 1
	fi
	if echo "# FILE: \
		etc/conffile1 c \
		share/examples/pkg1/conffile1" | task_files check-add; then
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_PREFIX}/etc/conffile1" ]; then
		describe="$describe: copied file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile1"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test2()
{
	describe="missing target directory"
	if echo "# FILE: \
		nonexistent/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add; then
		return 1
	fi
	if echo "# FILE: \
		nonexistent/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_PREFIX}/nonexistent/conffile2" ]; then
		describe="$describe: copied file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/nonexistent/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test3()
{
	describe="copy"
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test4()
{
	describe="skip copy"
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test5()
{
	describe="copy rc.d script"
	if echo "# FILE: \
		etc/rc.d/conffile2 cr \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/rc.d/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_PREFIX}/etc/rc.d/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	return 0
}

test6()
{
	describe="remove after copy"
	echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test7()
{
	: ${CP:=cp}

	describe="remove after skipped but copied"
	echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files add
	${CP} share/examples/pkg2/conffile2 etc/conffile2
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test8()
{
	describe="remove after modification"
	echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add
	echo "extra line" >> "${PKG_PREFIX}/etc/conffile2"
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		describe="$describe: check-remove"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test9()
{
	: ${CP:=cp}

	describe="remove after skipped but copied and modification"
	echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files add
	${CP} share/examples/pkg2/conffile2 etc/conffile2
	echo "extra line" >> "${PKG_PREFIX}/etc/conffile2"
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		describe="$describe: check-remove"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test10()
{
	describe="copy with preexisting"
	task_createfile etc/conffile2
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	if task_refcount prop_exists files "${PKG_PREFIX}/etc/conffile2" preexist; then
		: "success"
	else
		describe="$describe: property missing!"
		return 1
	fi
	return 0
}

test11()
{
	describe="remove after copy with preexisting"
	task_createfile etc/conffile2
	echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		describe="$describe: check-remove"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test12()
{
	describe="copy with permissions"
	task_requires_root || return 0
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2 \
		0400 root wheel" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2 \
		0400 root wheel" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2 \
		0400 root wheel" | task_files check-perms; then
		: "success"
	else
		describe="$describe: check-perms"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
}

test13()
{
	describe="missing example file with PKG_DESTDIR"
	test_destdir_setup
	if echo "# FILE: \
		etc/conffile1 c \
		share/examples/pkg1/conffile1" | task_files add; then
		return 1
	fi
	if echo "# FILE: \
		etc/conffile1 c \
		share/examples/pkg1/conffile1" | task_files check-add; then
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile1" ]; then
		describe="$describe: copied file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile1"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test14()
{
	describe="missing target directory with PKG_DESTDIR"
	test_destdir_setup
	if echo "# FILE: \
		nonexistent/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add; then
		return 1
	fi
	if echo "# FILE: \
		nonexistent/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/nonexistent/conffile2" ]; then
		describe="$describe: copied file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/nonexistent/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test15()
{
	describe="copy with PKG_DESTDIR"
	test_destdir_setup
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test16()
{
	describe="skip copy with PKG_DESTDIR"
	test_destdir_setup
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test17()
{
	describe="copy rc.d script with PKG_DESTDIR"
	test_destdir_setup
	if echo "# FILE: \
		etc/rc.d/conffile2 cr \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/rc.d/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		describe="$describe: check-add"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/rc.d/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	return 0
}

test18()
{
	describe="remove after copy with PKG_DESTDIR"
	test_destdir_setup
	echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test19()
{
	: ${CP:=cp}

	describe="remove after skipped but copied with PKG_DESTDIR"
	test_destdir_setup
	echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files add
	${CP} ${PKG_DESTDIR}${PKG_PREFIX}/share/examples/pkg2/conffile2 \
		${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file exists!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test20()
{
	describe="remove after modification with PKG_DESTDIR"
	test_destdir_setup
	echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add
	echo "extra line" >> "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2"
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		describe="$describe: check-remove"
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test21()
{
	: ${CP:=cp}

	describe="remove after skipped but copied and modification with PKG_DESTDIR"
	test_destdir_setup
	echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files add
	${CP} ${PKG_DESTDIR}${PKG_PREFIX}/share/examples/pkg2/conffile2 \
		${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2
	echo "extra line" >> "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2"
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files remove; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 . \
		share/examples/pkg2/conffile2" | task_files check-remove; then
		describe="$describe: check-remove"
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test22()
{
	describe="copy with preexisting with PKG_DESTDIR"
	test_destdir_setup
	task_createfile "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2"
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files add; then
		: "success"
	else
		return 1
	fi
	if echo "# FILE: \
		etc/conffile2 c \
		share/examples/pkg2/conffile2" | task_files check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ ! -f "${PKG_DESTDIR}${PKG_PREFIX}/etc/conffile2" ]; then
		describe="$describe: file missing!"
		return 1
	fi
	if task_refcount exists files "${PKG_PREFIX}/etc/conffile2"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	if task_refcount prop_exists files "${PKG_PREFIX}/etc/conffile2" preexist; then
		: "success"
	else
		describe="$describe: property missing!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
