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
task_load quote
task_load unittest

test_setup()
{
	# Create files in the test directory to catch wildcard expansion.
	task_createfile a b c
}

test1()
{
	describe="6 words"
	local quoted
	task_quote "1 *" "2 *" "3 *"
	set -- $quoted
	if [ $# -eq 6 ]; then
		: "success"
	else
		return 1
	fi
}

test2()
{
	describe="1 word"
	local quoted
	task_quote "1 *" "2 *" "3 *"
	set -- "$quoted"
	if [ $# -eq 1 ]; then
		: "success"
	else
		return 1
	fi
}

test3()
{
	describe="3 words (correct quoting)"
	local quoted
	task_quote "1 *" "2 *" "3 *"
	eval set -- $quoted
	if [ $# -eq 3 ]; then
		: "success"
	else
		return 1
	fi
}

test4()
{
	describe="3 words, extraneous quotes (correct quoting)"
	local quoted
	task_quote "1 *" "2 *" "3 *"
	eval set -- "$quoted"
	if [ $# -eq 3 ]; then
		: "success"
	else
		return 1
	fi
}

test5()
{
	describe="1 word (correct quoting)"
	local quoted
	task_quote "*"
	eval set -- $quoted
	local arg; for arg; do echo "$arg"; done
	if [ $# -eq 1 ]; then
		: "success"
	else
		return 1
	fi
}

test6()
{
	describe="1 word, extraneous quotes (correct quoting)"
	local quoted
	task_quote "*"
	eval set -- "$quoted"
	local arg; for arg; do echo "$arg"; done
	if [ $# -eq 1 ]; then
		: "success"
	else
		return 1
	fi
}

task_run_tests "$@"
