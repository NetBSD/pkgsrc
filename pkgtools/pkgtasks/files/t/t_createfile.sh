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
	: ${CAT:=cat}
}

test1()
{
	describe="make one file"
	task_createfile a
	if [ ! -f "a" ]; then
		return 1
	fi
	return 0
}

test2()
{
	describe="make two files"
	task_createfile a b
	if [ ! -f "a" -o ! -f "b" ]; then
		return 1
	fi
	return 0
}

test3()
{
	describe="make file with mode"
	task_createfile -m 600 a
	if [ ! -f "a" ]; then
		return 1
	fi
	if task_check_permissions a 600; then
		: "success"
	else
		describe="$describe: wrong mode!"
		return 1
	fi
	return 0
}

test4()
{
	describe="overwrite existing file"
	${CAT} > a << 'EOF'
content
EOF
	task_createfile a
	if [ ! -f "a" ]; then
		return 1
	fi
	local line
	while read line; do
		describe="$describe: non-empty file!"
		return 1
	done < a
	return 0
}

task_run_tests "$@"
