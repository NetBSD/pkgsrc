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
task_load postinstall
task_load unittest

test_setup()
{
	datafile="empty"
	task_createfile "$datafile"

	TASK_DIRECTORIES_SUCCESS="yes"
	TASK_FILES_SUCCESS="yes"
	TASK_FONTS_SUCCESS="yes"
	TASK_FUNCTION_SUCCESS="yes"
	TASK_INFO_FILES_SUCCESS="yes"
	TASK_OCAML_FINDLIB_SUCCESS="yes"
	TASK_PERMISSIONS_SUCCESS="yes"
	TASK_SHELLS_SUCCESS="yes"
	TASK_SHLIBS_SUCCESS="yes"
}

# Mock actions that return the truthiness of environment variables.
task_directories()
{
	[ "${TASK_DIRECTORIES_SUCCESS}" = "yes" ]
}

task_files()
{
	[ "${TASK_FILES_SUCCESS}" = "yes" ]
}

task_fonts()
{
	[ "${TASK_FONTS_SUCCESS}" = "yes" ]
}

task_function()
{
	[ "${TASK_FUNCTION_SUCCESS}" = "yes" ]
}

task_info_files()
{
	[ "${TASK_INFO_FILES_SUCCESS}" = "yes" ]
}

task_ocaml_findlib()
{
	[ "${TASK_OCAML_FINDLIB_SUCCESS}" = "yes" ]
}

task_permissions()
{
	[ "${TASK_PERMISSIONS_SUCCESS}" = "yes" ]
}

task_shells()
{
	[ "${TASK_SHELLS_SUCCESS}" = "yes" ]
}

task_shlibs()
{
	[ "${TASK_SHLIBS_SUCCESS}" = "yes" ]
}

# Only succeed if all of the actions were successful.

test1()
{
	describe="dirs fail"
	TASK_DIRECTORIES_SUCCESS="no"
	if task_postinstall "$datafile"; then
		: "dirs should only be used to check"
	else
		return 1
	fi
	return 0
}

test2()
{
	describe="files fail"
	TASK_FILES_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test3()
{
	describe="fonts fail"
	TASK_FONTS_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test4()
{
	describe="function fail"
	TASK_FUNCTION_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test5()
{
	describe="info_files fail"
	TASK_INFO_FILES_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test6()
{
	describe="ocaml_findlib fail"
	TASK_OCAML_FINDLIB_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test7()
{
	describe="permissions fail"
	TASK_PERMISSIONS_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test8()
{
	describe="shells fail"
	TASK_SHELLS_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test9()
{
	describe="shlibs fail"
	TASK_SHLIBS_SUCCESS="no"
	if task_postinstall "$datafile"; then
		return 1
	fi
	return 0
}

test10()
{
	describe="all succeed"
	if task_postinstall "$datafile"; then
		: "success"
	else
		return 1
	fi
	return 0
}

task_run_tests "$@"
