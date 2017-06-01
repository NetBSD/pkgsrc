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

task_load maketemp
task_load unittest

# Mock a broken utility.
broken()
{
	return 1
}

test_setup()
{
	: ${MKDIR:=mkdir}

	# Set MKTEMP to a broken utility to force following the shell code path.
	MKTEMP=broken

	etcdir="${TEST_CURDIR}/etc"
	TMPDIR="${TEST_CURDIR}/tmp"

	${MKDIR} -p "$etcdir"
	${MKDIR} -p "${TMPDIR}"
}

test1()
{
	describe="maketemp"
	local temp
	temp=$( task_maketemp )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	local temp_dirname="${temp%/*}"
	if [ "$temp_dirname" != "${TMPDIR}" ]; then
		describe="$describe: $temp_dirname is wrong parent!"
		return 1
	fi
	return 0
}

test2()
{
	describe="maketemp -p $etcdir"
	local temp
	temp=$( task_maketemp -p "$etcdir" )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	local temp_dirname="${temp%/*}"
	if [ "$temp_dirname" != "$etcdir" ]; then
		describe="$describe: $temp_dirname is wrong parent!"
		return 1
	fi
	return 0
}

test3()
{
	describe="maketemp -t foobar"
	local temp
	temp=$( task_maketemp -t foobar )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	case $temp in
	${TMPDIR}/foobar.*)
		: "success" ;;
	*)	describe="$describe: $temp doesn't match template!"
		return 1 ;;
	esac
	return 0
}

test4()
{
	describe="maketemp $etcdir/group.XXX"
	local temp
	temp=$( task_maketemp "$etcdir/group.XXX" )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -f "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	case $temp in
	$etcdir/group.???)
		: "success" ;;
	*)	describe="$describe: $temp doesn't match template!"
		return 1 ;;
	esac
	return 0
}

test5()
{
	describe="maketemp -d"
	local temp
	temp=$( task_maketemp -d )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	local temp_dirname="${temp%/*}"
	if [ "$temp_dirname" != "${TMPDIR}" ]; then
		describe="$describe: $temp_dirname is the wrong parent!"
		return 1
	fi
	return 0
}

test6()
{
	describe="maketemp -d -p $etcdir"
	local temp
	temp=$( task_maketemp -d -p "$etcdir" )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	local temp_dirname="${temp%/*}"
	if [ "$temp_dirname" != "$etcdir" ]; then
		describe="$describe: $temp_dirname is the wrong prefix!"
		return 1
	fi
	return 0
}

test7()
{
	describe="maketemp -d -t foobar"
	local temp
	temp=$( task_maketemp -d -t foobar )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	case $temp in
	${TMPDIR}/foobar.*)
		: "success" ;;
	*)	describe="$describe: $temp doesn't match template!"
		return 1 ;;
	esac
	return 0
}

test8()
{
	describe="maketemp -d $etcdir/group.XXX"
	local temp
	temp=$( task_maketemp -d "$etcdir/group.XXX" )
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$temp" ]; then
		describe="$describe: $temp missing!"
		return 1
	fi
	case $temp in
	$etcdir/group.???)
		: "success" ;;
	*)	describe="$describe: $temp doesn't match template!"
		return 1 ;;
	esac
	return 0
}

task_run_tests "$@"
