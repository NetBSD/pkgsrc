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
task_load sort
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CMP:=cmp}

	${CAT} > data << EOF
c
e
d
a
d
b
c
b
e
a
EOF
	${CAT} > sorted << EOF
a
a
b
b
c
c
d
d
e
e
EOF
	${CAT} > reversed << EOF
e
e
d
d
c
c
b
b
a
a
EOF
	${CAT} > unique-sorted << EOF
a
b
c
d
e
EOF
	${CAT} > unique-reversed << EOF
e
d
c
b
a
EOF
}

test1()
{
	describe="sort"
	task_sort < data > output
	if ${CMP} -s output sorted; then
		: "success"
	else
		${CAT} output
		return 1
	fi
	return 0
}

test2()
{
	describe="reverse sort"
	task_sort -r < data > output
	if ${CMP} -s output reversed; then
		: "success"
	else
		${CAT} output
		return 1
	fi
	return 0
}

test3()
{
	describe="empty input"
	task_createfile empty
	task_sort < empty > output
	if ${CMP} -s output empty; then
		: "success"
	else
		${CAT} output
		return 1
	fi
	return 0
}

test4()
{
	describe="unique sort"
	task_sort -u < data > output
	if ${CMP} -s output unique-sorted; then
		: "success"
	else
		${CAT} output
		return 1
	fi
	return 0
}

test5()
{
	describe="unique reverse-sort"
	task_sort -ru < data > output
	if ${CMP} -s output unique-reversed; then
		: "success"
	else
		${CAT} output
		return 1
	fi
	return 0
}

task_run_tests "$@"
