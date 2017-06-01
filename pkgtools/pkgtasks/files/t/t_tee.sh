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

task_load tee
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CMP:=cmp}
	: ${CP:=cp}

	${CAT} > data << EOF
line 1
line 2
line 3
line 4
line 5
EOF
}

test1()
{
	describe="no files"
	${CP} data expected
	task_tee < data > value
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	return 0
}

test2()
{
	describe="output files"
	${CP} data expected
	task_tee out1 out2 < data > value
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	if ${CMP} -s expected out1; then
		: "success"
	else
		describe="$describe: out1"
		${CAT} out1
		return 1
	fi
	if ${CMP} -s expected out2; then
		: "success"
	else
		describe="$describe: out2"
		${CAT} out2
		return 1
	fi
	return 0
}

test3()
{
	describe="overwrite existing files"
	${CP} data expected
	echo "overwritten" > out
	task_tee out < data > value
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	if ${CMP} -s expected out; then
		: "success"
	else
		describe="$describe: out"
		${CAT} out
		return 1
	fi
	return 0
}

test4()
{
	describe="append existing files"
	echo "append" > out
	${CP} out expected
	${CAT} data >> expected
	task_tee -a out < data > value
	if ${CMP} -s data value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	if ${CMP} -s expected out; then
		: "success"
	else
		describe="$describe: out"
		${CAT} out
		return 1
	fi
	return 0
}

task_run_tests "$@"
