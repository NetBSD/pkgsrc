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
task_load dirwalk
task_load unittest

# Mock a broken utility.
broken()
{
	return 1
}

test_setup()
{
	: ${CAT:=cat}
	: ${CMP:=cmp}
	: ${MKDIR:=mkdir}

	# Set FIND to a broken utility to force using the shell code path.
	FIND=broken

	output="output"

	# ./
	#   `---root/
	#        |
	#        |---dir1/
	#        |    |---fileA
	#        |    |---dirB/
	#        |    |    |---filea
	#        |    |    `---fileb
	#        |    `---fileC
	#        |---file2
	#        `---dir3/
	#             |---fileD
	#             `---fileE
	#
	${MKDIR} root
	${MKDIR} root/dir1
	task_createfile root/dir1/fileA
	${MKDIR} root/dir1/dirB
	task_createfile root/dir1/dirB/filea
	task_createfile root/dir1/dirB/fileb
	task_createfile root/dir1/fileC
	task_createfile root/file2
	${MKDIR} root/dir3
	task_createfile root/dir3/fileD
	task_createfile root/dir3/fileE

	expected_all="expected_all"
	${CAT} > $expected_all << EOF
root
root/dir1
root/dir1/dirB
root/dir1/dirB/filea
root/dir1/dirB/fileb
root/dir1/fileA
root/dir1/fileC
root/dir3
root/dir3/fileD
root/dir3/fileE
root/file2
EOF
	expected_dirs="expected_dirs"
	${CAT} > $expected_dirs << EOF
root
root/dir1
root/dir1/dirB
root/dir3
EOF
	expected_files="expected_files"
	${CAT} > $expected_files << EOF
root/dir1/dirB/filea
root/dir1/dirB/fileb
root/dir1/fileA
root/dir1/fileC
root/dir3/fileD
root/dir3/fileE
root/file2
EOF
}

test1()
{
	describe="dirwalk root"
	task_dirwalk root > $output
	if ${CMP} -s "$expected_all" "$output"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test2()
{
	describe="dirwalk -d root"
	task_dirwalk -d root > $output
	if ${CMP} -s "$expected_dirs" "$output"; then
		: "success"
	else
		return 1
	fi
	return 0
}

test3()
{
	describe="dirwalk -f root"
	task_dirwalk -f root > $output
	if ${CMP} -s "$expected_files" "$output"; then
		: "success"
	else
		return 1
	fi
	return 0
}

task_run_tests "$@"
