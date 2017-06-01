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

task_load compare
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CP:=cp}
}

test1()
{
	describe="identical files"
	${CAT} > a << EOF
line1
line2
line3
EOF
	${CP} a b
	if task_compare a b; then
		: "success"
	else
		return 1
	fi
	return 0
}

test2()
{
	describe="truncated first file"
	${CAT} > a << EOF
line1
line2
EOF
	${CAT} > b << EOF
line1
line2
line3
EOF
	if task_compare a b; then
		return 1
	else
		: "success"
	fi
	return 0
}

test3()
{
	describe="truncated second file"
	${CAT} > a << EOF
line1
line2
line3
EOF
	${CAT} > b << EOF
line1
line2
EOF
	if task_compare a b; then
		return 1
	else
		: "success"
	fi
	return 0
}

test4()
{
	describe="leading whitespace differences"
	${CAT} > a << EOF
line1
line2
line3
EOF
	${CAT} > b << EOF
line1
  line2
    line3
EOF
	if task_compare a b; then
		return 1
	else
		: "success"
	fi
	return 0
}

test5()
{
	describe="trailing whitespace differences"
	${CAT} > a << EOF
line1
line2
line3
EOF
	${CAT} > b << EOF
line1
line2 
line3  
EOF
	if task_compare a b; then
		return 1
	else
		: "success"
	fi
	return 0
}

test6()
{
	describe="different content"
	${CAT} > a << EOF
line1
line2
line3
EOF
	${CAT} > b << EOF
LINE1
LINE2
LINE3
EOF
	if task_compare a b; then
		return 1
	else
		: "success"
	fi
	return 0
}

task_run_tests "$@"
