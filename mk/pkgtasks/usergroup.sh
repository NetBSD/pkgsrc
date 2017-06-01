#!/bin/sh
#
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

# NAME
#	usergroup.sh -- add and check for groups and users
#
# SYNOPSIS
#	usergroup.sh <groupdata> <userdata>
#
# DESCRIPTION
#	usergroup.sh ensures that all required groups and users as
#	listed in the datafiles exist.
#
#	The datafiles contains lines of the format needed by the
#	"group" and "users" tasks.
#
# EXIT STATUS
#	Exits 0 if the groups and users all exist, and >0 otherwise.
#

: ${LOCALBASE:=/usr/pkg}
: ${TASK_MODULE_DIR:=${LOCALBASE}/share/pkgtasks-1}
. "${TASK_MODULE_DIR}/load.subr"

: ${TASK_PLATFORM:=NetBSD}

task_load groups
task_load users
task_load usergroup_${TASK_PLATFORM}

do_usergroup()
{
	[ $# -ge 2 ] || return 127
	local groupdata="$1"; shift
	local userdata="$1"; shift

	[ -f "$groupdata" ] || return 1
	[ -f "$userdata" ] || return 1

	local result=0

	# Groups
	if [ $result -eq 0 ]; then
		task_groups add < $groupdata || result=1
		task_groups check-add < $groupdata || result=1
	fi

	# Users
	if [ $result -eq 0 ]; then
		task_users add < $userdata || result=1
		task_users check-add < $userdata || result=1
	fi

	return $result
}

do_usergroup "$@"
