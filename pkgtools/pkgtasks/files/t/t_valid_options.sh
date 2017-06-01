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

task_load valid_options
task_load unittest

test1()
{
	describe="valid substring"
	task_valid_options "ab" "abcd."
}

test2()
{
	describe="valid first character"
	task_valid_options "a" "abcd."
}

test3()
{
	describe="valid middle character"
	task_valid_options "b" "abcd."
}

test4()
{
	describe="valid last character"
	task_valid_options "." "abcd."
}

test5()
{
	describe="invalid substring"
	if task_valid_options "abCD" "abcd."; then
		return 1
	fi
}

test6()
{
	describe="invalid first character"
	if task_valid_options "Abc" "abcd."; then
		return 1
	fi
}

test7()
{
	describe="invalid middle character"
	if task_valid_options "aBc" "abcd."; then
		return 1
	fi
}

test8()
{
	describe="invalid last character"
	if task_valid_options "abD" "abcd."; then
		return 1
	fi
}

test9()
{
	describe="invalid only"
	if task_valid_options "C" "abcd."; then
		return 1
	fi
}

task_run_tests "$@"
