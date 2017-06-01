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

task_load match
task_load unittest

test_setup()
{
	: ${CAT:=cat}

	data="data"
	newline="
"

	${CAT} > $data << EOF
aaa
bbb ccc
bbbccc

ddd aaa

aaa eee
* Menu:
EOF
}

test1()
{
	describe="exact plain match one line"
	local expected value
	expected="bbb ccc"
	value=$( task_match "bbb ccc" < $data )
	if [ "$value" != "$expected" ]; then
		task_match "bbb ccc" < $data
		return 1
	fi
	return 0
}

test2()
{
	describe="word plain match one line"
	local expected value
	expected="bbb ccc"
	value=$( task_match -w bbb < $data )
	if [ "$value" != "$expected" ]; then
		return 1
	fi
	return 0
}

test3()
{
	describe="word plain match multiple lines"
	local expected value
	value=$( task_match -w aaa < $data )
	expected="aaa${newline}aaa eee"
	if [ "$value" != "$expected" ]; then
		return 1
	fi
	return 0
}

test4()
{
	describe="word reverse match one line"
	local expected value
	value=$( task_match -vw bbb < $data )
	expected="aaa${newline}bbbccc${newline}${newline}ddd aaa${newline}${newline}aaa eee${newline}* Menu:"
	if [ "$value" != "$expected" ]; then
		return 1
	fi
	return 0
}

test5()
{
	describe="word reverse match multiple lines"
	local expected value
	value=$( task_match -vw aaa < $data )
	expected="bbb ccc${newline}bbbccc${newline}${newline}ddd aaa${newline}${newline}* Menu:"
	if [ "$value" != "$expected" ]; then
		return 1
	fi
	return 0
}

test6()
{
	describe="exact plain match no lines"
	local value
	value=$( task_match ccc < $data )
	if [ -n "$value" ]; then
		return 1
	fi
	return 0
}

test7()
{
	describe="word plain match silent"
	if task_match -qw aaa < $data; then
		: "success"
	else
		return 1
	fi
	return 0
}

test8()
{
	describe="word reverse match silent"
	if task_match -qvw aaa < $data; then
		: "success"
	else
		return 1
	fi
	return 0
}

test9()
{
	describe="exact plain match no lines silent"
	if task_match -q ccc < $data; then
		return 1
	fi
	return 0
}

test10()
{
	describe="exact reverse match no lines silent"
	if task_match -qv ccc < $data; then
		return 1
	fi
	return 0
}

test11()
{
	describe="plain glob match one line"
	local expected value
	value=$( task_match "[*][ 	][mM]enu:*" < $data )
	expected="* Menu:"
	if [ "$value" != "$expected" ]; then
		return 1
	fi
	return 0
}

task_run_tests "$@"
