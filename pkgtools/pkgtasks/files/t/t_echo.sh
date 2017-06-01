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
task_load echo
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CMP:=cmp}

	# Explicitly set TASK_LOGFILE to empty string to prevent unintended
	# duplicate output.
	#
	TASK_LOGFILE=
}

test1()
{
	describe="task_echo -b buffers text"
	task_echo -bc "line 1"
	task_echo -b "line 2"
	task_echo "line 3" > value
	${CAT} > expected << 'EOF'
line 1
line 2
line 3
EOF
	if ${CMP} -s expected value; then
		: "success"
	else
		return 1
	fi
	task_echo "only line" > value
	echo "only line" > expected
	if ${CMP} -s expected value; then
		: "success"
	else
		describe="$describe: next write has extra output!"
		return 1
	fi
	for entry in *; do
		case $entry in
		expected|value)
			: "can exist" ;;
		*)	describe="$describe: unknown file!"
			return 1 ;;
		esac
	done
	return 0
}

test2()
{
	describe="task_echo -c clears buffer"
	task_echo -bc "line 1"
	task_echo -b "line 2"
	task_echo -cn
	task_echo "only line" > value
	echo "only line" > expected
	if ${CMP} -s expected value; then
		: "success"
	else
		return 1
	fi
	for entry in *; do
		case $entry in
		expected|value)
			: "can exist" ;;
		*)	describe="$describe: unknown file!"
			return 1 ;;
		esac
	done
	return 0
}

test3()
{
	describe="task_echo -bc clears buffer"
	task_echo -bc "line 1"
	task_echo -b "line 2"
	task_echo -bc "line 3"
	task_echo "line 4" > value
	${CAT} > expected << 'EOF'
line 3
line 4
EOF
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	for entry in *; do
		case $entry in
		expected|value)
			: "can exist" ;;
		*)	describe="$describe: unknown file!"
			return 1 ;;
		esac
	done
	return 0
}

test4()
{
	describe="task_echo -n skips trailing newline"
	task_echo -bcn "list: 1"
	task_echo -bn ", 2"
	task_echo -bn ", 3"
	task_echo > value
	echo "list: 1, 2, 3" > expected
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	for entry in *; do
		case $entry in
		expected|value)
			: "can exist" ;;
		*)	describe="$describe: unknown file!"
			return 1 ;;
		esac
	done
	return 0
}

test5()
{
	describe="task_echo preserves leading whitespace"
	task_echo "    1 2 3 4" > value
	echo      "    1 2 3 4" > expected
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	for entry in *; do
		case $entry in
		expected|value)
			: "can exist" ;;
		*)	describe="$describe: unknown file!"
			return 1 ;;
		esac
	done
	return 0
}

test6()
{
	describe="task_echo preserves leading whitespace after buffer output"
	task_echo -bc "header"
	task_echo "    1 2 3 4" > value
	${CAT} > expected << 'EOF'
header
    1 2 3 4
EOF
	if ${CMP} -s expected value; then
		: "success"
	else
		${CAT} value
		return 1
	fi
	for entry in *; do
		case $entry in
		expected|value)
			: "can exist" ;;
		*)	describe="$describe: unknown file!"
			return 1 ;;
		esac
	done
	return 0
}


test7()
{
	describe="task_echo -b buffers text with log"
	TASK_LOGFILE="${TEST_CURDIR}/log"
	task_echo -bc "line 1"
	if [ -f "${TASK_LOGFILE}" ]; then
		describe="$describe: log exists after first buffered echo!"
		return 1
	fi
	task_echo -b "line 2"
	if [ -f "${TASK_LOGFILE}" ]; then
		describe="$describe: log exists after second buffered echo!"
		return 1
	fi
	task_echo "line 3" > value
	if [ ! -f "${TASK_LOGFILE}" ]; then
		describe="$describe: log missing!"
		return 1
	fi
	${CAT} > expected << 'EOF'
line 1
line 2
line 3
EOF
	if ${CMP} -s expected value; then
		: "success"
	else
		return 1
	fi
	if ${CMP} -s value log; then
		: "success"
	else
		describe="$describe: log doesn't match standard output!"
		${CAT} log
		return 1
	fi
	task_echo "only line" > value
	echo "only line" >> expected
	if ${CMP} -s expected log; then
		: "success"
	else
		describe="$describe: log doesn't match all writes!"
		${CAT} log
		return 1
	fi
	return 0
}

test8()
{
	describe="task_echo -c clears buffer with log"
	TASK_LOGFILE="${TEST_CURDIR}/log"
	task_echo -bc "line 1"
	task_echo -b "line 2"
	task_echo -cn
	task_echo "only line" > value
	echo "only line" > expected
	if ${CMP} -s expected log; then
		: "success"
	else
		${CAT} log
		return 1
	fi
	if ${CMP} -s value log; then
		: "success"
	else
		describe="$describe: log doesn't match output"
		${CAT} log
		return 1
	fi
	return 0
}

test9()
{
	describe="task_echo -bc clears buffer with log"
	TASK_LOGFILE="${TEST_CURDIR}/log"
	task_echo -bc "line 1"
	task_echo -b "line 2"
	task_echo -bc "line 3"
	task_echo "line 4" > value
	${CAT} > expected << 'EOF'
line 3
line 4
EOF
	if ${CMP} -s expected log; then
		: "success"
	else
		${CAT} log
		return 1
	fi
	if ${CMP} -s value log; then
		: "success"
	else
		describe="$describe: log doesn't match output"
		${CAT} log
		return 1
	fi
	return 0
}

test10()
{
	describe="task_echo -n skips trailing newline with log"
	TASK_LOGFILE="${TEST_CURDIR}/log"
	task_echo -bcn "list: 1"
	task_echo -bn ", 2"
	task_echo -bn ", 3"
	task_echo > value
	echo "list: 1, 2, 3" > expected
	if ${CMP} -s expected log; then
		: "success"
	else
		${CAT} log
		return 1
	fi
	if ${CMP} -s value log; then
		: "success"
	else
		describe="$describe: log doesn't match output"
		${CAT} log
		return 1
	fi
	return 0
}

test11()
{
	describe="task_echo preserves leading whitespace with log"
	TASK_LOGFILE="${TEST_CURDIR}/log"
	task_echo "    1 2 3 4" > value
	echo      "    1 2 3 4" > expected
	if ${CMP} -s expected log; then
		: "success"
	else
		${CAT} log
		return 1
	fi
	if ${CMP} -s value log; then
		: "success"
	else
		describe="$describe: log doesn't match output"
		${CAT} log
		return 1
	fi
	return 0
}

test12()
{
	describe="task_echo preserves leading whitespace after buffer output with log"
	TASK_LOGFILE="${TEST_CURDIR}/log"
	task_echo -bc "header"
	task_echo "    1 2 3 4" > value
	${CAT} > expected << 'EOF'
header
    1 2 3 4
EOF
	if ${CMP} -s expected log; then
		: "success"
	else
		${CAT} log
		return 1
	fi
	if ${CMP} -s value log; then
		: "success"
	else
		describe="$describe: log doesn't match output"
		${CAT} log
		return 1
	fi
	return 0
}

task_run_tests "$@"
