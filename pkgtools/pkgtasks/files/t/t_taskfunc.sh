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
task_load taskfunc
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CMP:=cmp}

	${CAT} > data << EOF
# ( ) junk
# TASK: hello	# GREET: world one
# TASK: bye	# FAREWELL: dear one
# TASK: hello	# GREET: world two
# TASK: bye	# FAREWELL: dear two
# TASK: hello	# GREET: world three
# TASK: bye	# FAREWELL: dear three
EOF
	${CAT} > expected-add << EOF
hello add: world one
hello add: world two
hello add: world three
bye add: dear one
bye add: dear two
bye add: dear three
EOF
	${CAT} > expected-remove << EOF
hello remove: world one
hello remove: world two
hello remove: world three
bye remove: dear one
bye remove: dear two
bye remove: dear three
EOF
}

mock_function()
{
	local name="$1"; shift
	local nametag="$1"; shift
	local action="$1"; shift
	local stage="$1"

	case $action in
	add|remove|check-add|check-remove)
		: "valid action" ;;
	*)	return 0 ;;
	esac
	case $stage in
	postinstall|"")
		: "valid stage" ;;
	*)	return 0 ;;
	esac

	local hash tag line
	while read hash tag line; do
		case $hash/$tag in
		"#/$nametag")
			case $line in FAIL) return 1 ;; esac
			echo "$name $action: $line" ;;
		esac
	done
}

hello()
{
	mock_function hello "GREET:" "$@"
}

bye()
{
	mock_function bye "FAREWELL:" "$@"
}

test1()
{
	describe="missing function"
	if echo "# TASK: missing arg1 arg2 arg3" | task_function add; then
		return 1
	fi
	return 0
}

test2()
{
	describe="add"
	task_function add < data > value
	if ${CMP} -s expected-add value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	return 0
}

test3()
{
	describe="remove"
	task_function remove < data > value
	if ${CMP} -s expected-remove value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	return 0
}

test4()
{
	describe="add fail"
	if echo "# TASK: hello # GREET: FAIL" | task_function add; then
		return 1
	fi
	return 0
}

test5()
{
	describe="wrong stage"
	task_function add preinstall < data > value
	task_createfile expected
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	return 0
}

test6()
{
	describe="correct stage"
	task_function add postinstall < data > value
	if ${CMP} -s expected-add value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	return 0
}

task_run_tests "$@"
