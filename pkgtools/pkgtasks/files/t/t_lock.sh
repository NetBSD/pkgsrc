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
task_load lock
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${CMP:=cmp}
	: ${SLEEP:=sleep}

	lockfile="lock"
}

test1()
{
	describe="create lock"
	if task_lock "$lockfile"; then
		: "success"
	else
		return 1
	fi
	if [ ! -f "$lockfile" ]; then
		describe="$describe: $lockfile missing!"
		return 1
	fi
	return 0
}

test2()
{
	describe="create nonblocking lock, pre-existing lock file"
	task_createfile "$lockfile"
	if task_lock -n "$lockfile"; then
		return 1
	fi
	return 0
}

test3()
{
	describe="release lock"
	task_lock "$lockfile"
	if task_lock -r "$lockfile"; then
		: "success"
	else
		return 1
	fi
	if [ -f "$lockfile" ]; then
		describe="$describe: $lockfile exists!"
		return 1
	fi
	return 0
}

test4()
{
	describe="create lock, competing processes"
	local timeout=3
	# Create a child process that writes to "value".
	( if task_lock "$lockfile"; then
		echo "child" >> value
		${SLEEP} $timeout
		task_lock -r "$lockfile"
	  fi ) &
	#
	# Wait for up to $timeout seconds for the child to write to the
	# datefile.
	#
	while [ $timeout -gt 0 ]; do
		[ ! -f value ] || break
		${SLEEP} 1
		timeout=$(( $timeout - 1 ))
	done
	# Block waiting for background process to unlock.
	if task_lock "$lockfile"; then
		echo "parent" >> value
		task_lock -r "$lockfile"
	fi
	# Check that the writes were serialized: child, then parent.
	${CAT} > expected << 'EOF'
child
parent
EOF
	if ${CMP} -s expected value; then
		: "success"
	else
		describe="$describe: child after parent!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
