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

task_load directories
task_load unittest

test_setup()
{
	: ${MKDIR:=mkdir}

	PKGNAME=${0##*/}
	PKG_PREFIX=${TEST_CURDIR}
	PKG_DESTDIR=

	PKG_DBDIR="${TEST_CURDIR}/var/db/pkg"
	PKG_REFCOUNT_DBDIR="${PKG_DBDIR}.refcount"
	${MKDIR} -p "${PKG_DBDIR}"
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}"
	${MV} var "${PKG_DESTDIR}${PKG_PREFIX}"
}

test1()
{
	describe="make dir"
	if echo "# DIR: etc/pkg1 m" | task_directories add; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 m" | task_directories check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ ! -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir missing!"
		return 1
	fi
	if task_refcount exists dirs "${PKG_PREFIX}/etc/pkg1"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test2()
{
	describe="skip make dir"
	if echo "# DIR: etc/pkg1 ." | task_directories add; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 ." | task_directories check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

test3()
{
	describe="remove make dir"
	echo "# DIR: etc/pkg1 m" | task_directories add
	if echo "# DIR: etc/pkg1 m" | task_directories remove; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 m" | task_directories check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	if task_refcount exists dirs "${PKG_PREFIX}/etc/pkg1"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test4()
{
	describe="remove skipped make dir"
	echo "# DIR: etc/pkg1 ." | task_directories add
	if echo "# DIR: etc/pkg1 ." | task_directories remove; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 ." | task_directories check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

test5()
{
	describe="remove skipped made dir"
	echo "# DIR: etc/pkg1 ." | task_directories add
	${MKDIR} -p etc/pkg1
	if echo "# DIR: etc/pkg1 ." | task_directories remove; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 ." | task_directories check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

test6()
{
	describe="make dir for 2 packages"
	( PKGNAME="package1"
	  echo "# DIR: etc/common m" | task_directories add )
	( PKGNAME="package2"
	  echo "# DIR: etc/common m" | task_directories add )
	if [ ! -d "${PKG_PREFIX}/etc/common" ]; then
		describe="$describe: dir missing!"
		return 1
	fi
	if task_refcount exists dirs "${PKG_PREFIX}/etc/common"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test7()
{
	describe="remove after make dir for 2 packages"
	( PKGNAME="package1"
	  echo "# DIR: etc/common m" | task_directories add )
	( PKGNAME="package2"
	  echo "# DIR: etc/common m" | task_directories add )
	( PKGNAME="package1"
	  echo "# DIR: etc/common m" | task_directories remove )
	if [ ! -d "${PKG_PREFIX}/etc/common" ]; then
		describe="$describe: dir missing!"
		return 1
	fi
	( PKGNAME="package2"
	  echo "# DIR: etc/common m" | task_directories remove )
	if [ -d "${PKG_PREFIX}/etc/common" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

test8()
{
	describe="remove owned directory"
	echo "# DIR: etc/pkg1 mo" | task_directories add
	echo "# DIR: etc/pkg1 mo" | task_directories remove
	if [ -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

test9()
{
	describe="conflicting owner"
	( PKGNAME="package1"
	  echo "# DIR: etc/common mo" | task_directories add )
	( PKGNAME="package2"
	  echo "# DIR: etc/common mo" | task_directories add )
	if [ $? -eq 0 ]; then
		return 1
	fi
	return 0
}

test10()
{
	describe="remove owned directory used by another package"
	( PKGNAME="package1"
	  echo "# DIR: etc/common mo" | task_directories add )
	( PKGNAME="package2"
	  echo "# DIR: etc/common m" | task_directories add )
	( PKGNAME="package1"
	  echo "# DIR: etc/common mo" | task_directories remove )
	if [ $? -eq 0 ]; then
		return 1
	fi
	return 0
}

test11()
{
	describe="owned dir with permissions"
	task_requires_root || return 0
	if echo "# DIR: etc/pkg1 mo 0700 root wheel" |
	   task_directories add; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 mo 0700 root wheel" |
	   task_directories check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if echo "# DIR: etc/pkg1 mo 0700 root wheel" |
	   task_directories check-perms; then
		: "success"
	else
		describe="$describe: check-perms"
		return 1
	fi
	if [ ! -d "${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir missing!"
		return 1
	fi
}

test12()
{
	describe="make dir with PKG_DESTDIR"
	test_destdir_setup
	if echo "# DIR: etc/pkg1 m" | task_directories add; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 m" | task_directories check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ ! -d "${PKG_DESTDIR}${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir missing!"
		return 1
	fi
	if task_refcount exists dirs "${PKG_PREFIX}/etc/pkg1"; then
		: "success"
	else
		describe="$describe: refcount missing!"
		return 1
	fi
	return 0
}

test13()
{
	describe="skip make dir with PKG_DESTDIR"
	test_destdir_setup
	if echo "# DIR: etc/pkg1 ." | task_directories add; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 ." | task_directories check-add; then
		: "success"
	else
		describe="$describe: check-add"
		return 1
	fi
	if [ -d "${PKG_DESTDIR}${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

test14()
{
	describe="remove make dir with PKG_DESTDIR"
	test_destdir_setup
	echo "# DIR: etc/pkg1 m" | task_directories add
	if echo "# DIR: etc/pkg1 m" | task_directories remove; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 m" | task_directories check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -d "${PKG_DESTDIR}${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	if task_refcount exists dirs "${PKG_PREFIX}/etc/pkg1"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	return 0
}

test15()
{
	describe="remove skipped made dir with PKG_DESTDIR"
	test_destdir_setup
	echo "# DIR: etc/pkg1 ." | task_directories add
	${MKDIR} -p ${PKG_DESTDIR}${PKG_PREFIX}/etc/pkg1
	if echo "# DIR: etc/pkg1 ." | task_directories remove; then
		: "success"
	else
		return 1
	fi
	if echo "# DIR: etc/pkg1 ." | task_directories check-remove; then
		: "success"
	else
		describe="$describe: check-remove"
		return 1
	fi
	if [ -d "${PKG_DESTDIR}${PKG_PREFIX}/etc/pkg1" ]; then
		describe="$describe: dir exists!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
