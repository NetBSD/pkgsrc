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

task_load refcount
task_load unittest

test_setup()
{
	PKG_REFCOUNT_DBDIR="${TEST_CURDIR}/refcount"
	PKG_DESTDIR=

	nonexistent="${TEST_CURDIR}/nonexistent"
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${TEST_CURDIR}"
}

test1()
{
	describe="add nonexistent file"
	if task_refcount add refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		: "success"
	else
	   	describe="$describe: reference missing!"
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" permissions; then
		describe="$describe: permissions found!"
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" preexist; then
		describe="$describe: preexist found!"
		return 1
	fi
	return 0
}

test2()
{
	describe="put permissions"
	local permissions="0400 root wheel"
	task_refcount add refs "$nonexistent"
	if task_refcount prop_put refs "$nonexistent" permissions $permissions; then
		: "success"
	else
		return 1
	fi
	if task_refcount prop_match refs "$nonexistent" permissions $permissions; then
		: "success"
	else
		describe="$describe: permissions not matching!"
		return 1
	fi
	return 0
}

test3()
{
	describe="put preexist"
	task_refcount add refs "$nonexistent"
	if task_refcount prop_put refs "$nonexistent" preexist; then
		: "success"
	else
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" preexist; then
		: "success"
	else
		describe="$describe: preexist not found!"
		return 1
	fi
	return 0
}

test4()
{
	describe="remove after add twice"
	task_refcount add refs "$nonexistent"
	task_refcount add refs "$nonexistent"
	if task_refcount remove refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: reference found!"
		return 1
	fi
	return 0
}

test5()
{
	describe="remove pkg1 after add pkg1 and pkg2"
	( PKGNAME="package1"; task_refcount add refs "$nonexistent" )
	( PKGNAME="package2"; task_refcount add refs "$nonexistent" )
	( PKGNAME="package1"; task_refcount remove refs "$nonexistent" )
	if task_refcount exists refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
}

test6()
{
	describe="put property with no refcount"
	local permissions="0400 root wheel"
	if task_refcount prop_put refs "$nonexistent" permissions $permissions; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: refcount exists!"
		return 1
	fi
}

test7()
{
	describe="delete refcount"
	task_refcount add refs "$nonexistent"
	task_refcount prop_put refs "$nonexistent" owner
	if task_refcount delete refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: reference found!"
		return 1
	fi
}

test8()
{
	describe="remove refcount after putting property"
	task_refcount add refs "$nonexistent"
	task_refcount prop_put refs "$nonexistent" owner
	if task_refcount remove refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: reference found!"
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" owner; then
		: "success"
	else
		describe="$describe: property not found!"
		return 1
	fi
}

test9()
{
	describe="delete property"
	task_refcount prop_put refs "$nonexistent" owner
	if task_refcount prop_delete refs "$nonexistent" owner; then
		: "success"
	else
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" owner; then
		describe="$describe: property found!"
		return 1
	fi
}

test10()
{
	describe="add nonexistent file with PKG_DESTDIR"
	test_destdir_setup
	if task_refcount add refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		: "success"
	else
	   	describe="$describe: reference missing!"
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" permissions; then
		describe="$describe: permissions found!"
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" preexist; then
		describe="$describe: preexist found!"
		return 1
	fi
	if [ -d "${PKG_REFCOUNT_DBDIR}" ]; then
		describe="$describe: wrong refcount directory!"
		return 1
	fi
	return 0
}

test11()
{
	describe="put permissions with PKG_DESTDIR"
	test_destdir_setup
	local permissions="0400 root wheel"
	task_refcount add refs "$nonexistent"
	if task_refcount prop_put refs "$nonexistent" permissions $permissions; then
		: "success"
	else
		return 1
	fi
	if task_refcount prop_match refs "$nonexistent" permissions $permissions; then
		: "success"
	else
		describe="$describe: permissions not matching!"
		return 1
	fi
	if [ -d "${PKG_REFCOUNT_DBDIR}" ]; then
		describe="$describe: wrong refcount directory!"
		return 1
	fi
	return 0
}

test12()
{
	describe="put preexist with DESTDIR"
	test_destdir_setup
	task_refcount add refs "$nonexistent"
	if task_refcount prop_put refs "$nonexistent" preexist; then
		: "success"
	else
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" preexist; then
		: "success"
	else
		describe="$describe: preexist not found!"
		return 1
	fi
	if [ -d "${PKG_REFCOUNT_DBDIR}" ]; then
		describe="$describe: wrong refcount directory!"
		return 1
	fi
	return 0
}

test13()
{
	describe="remove after add twice with PKG_DESTDIR"
	test_destdir_setup
	task_refcount add refs "$nonexistent"
	task_refcount add refs "$nonexistent"
	if task_refcount remove refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: reference found!"
		return 1
	fi
	return 0
}

test14()
{
	describe="remove pkg1 after add pkg1 and pkg2 with PKG_DESTDIR"
	test_destdir_setup
	( PKGNAME="package1"; task_refcount add refs "$nonexistent" )
	( PKGNAME="package2"; task_refcount add refs "$nonexistent" )
	( PKGNAME="package1"; task_refcount remove refs "$nonexistent" )
	if task_refcount exists refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
}

test15()
{
	describe="put property with no refcount with PKG_DESTDIR"
	test_destdir_setup
	local permissions="0400 root wheel"
	if task_refcount prop_put refs "$nonexistent" permissions $permissions; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: refcount exists!"
		return 1
	fi
	if [ -d "${PKG_REFCOUNT_DBDIR}" ]; then
		describe="$describe: wrong refcount directory!"
		return 1
	fi
}

test16()
{
	describe="delete refcount with PKG_DESTDIR"
	test_destdir_setup
	task_refcount add refs "$nonexistent"
	task_refcount prop_put refs "$nonexistent" owner
	if task_refcount delete refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: reference found!"
		return 1
	fi
}

test17()
{
	describe="remove refcount after putting property with PKG_DESTDIR"
	test_destdir_setup
	task_refcount add refs "$nonexistent"
	task_refcount prop_put refs "$nonexistent" owner
	if task_refcount remove refs "$nonexistent"; then
		: "success"
	else
		return 1
	fi
	if task_refcount exists refs "$nonexistent"; then
		describe="$describe: reference found!"
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" owner; then
		: "success"
	else
		describe="$describe: property not found!"
		return 1
	fi
	if [ -d "${PKG_REFCOUNT_DBDIR}" ]; then
		describe="$describe: wrong refcount directory!"
		return 1
	fi
}

test18()
{
	describe="delete property with PKG_DESTDIR"
	test_destdir_setup
	task_refcount prop_put refs "$nonexistent" owner
	if task_refcount prop_delete refs "$nonexistent" owner; then
		: "success"
	else
		return 1
	fi
	if task_refcount prop_exists refs "$nonexistent" owner; then
		describe="$describe: property found!"
		return 1
	fi
}

task_run_tests "$@"
