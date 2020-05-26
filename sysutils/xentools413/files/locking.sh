#!/bin/sh
#
# Copyright (c) 2016, Christoph Badura.  All rights reserved.
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
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

LOCK_BASEDIR="$XEN_LOCK_DIR/xen-hotplug"

_lockfd=9
_have_lock=0	# lock not taken yet.

SHLOCK="shlock ${_shlock_debug-}"

_lock_set_vars() {
	_lockfile="$LOCK_BASEDIR/$1.lock"
	_lockfifo="$LOCK_BASEDIR/$1.fifo"
}

_lock_init() {
	mkdir -p "$LOCK_BASEDIR" 2>/dev/null || true
	mkfifo $_lockfifo 2>/dev/null || true
}

#
# use a named pipe as condition variable
# opening for read-only blocks when there's no writer.
# opening for read-write never blocks but unblocks any waiting readers.
# 
_lock_wait_cv() {
	eval "exec $_lockfd<  $_lockfifo ; exec $_lockfd<&-"
}
_lock_signal_cv() {
	eval "exec $_lockfd<> $_lockfifo ; exec $_lockfd<&-"
}

claim_lock() {
	_lock_set_vars $1
	_lock_init
	until $SHLOCK -f $_lockfile -p $$; do
		_lock_wait_cv
	done
	_have_lock=1
	# be sure to release the lock when the shell exits
	trap "release_lock $1" 0 1 2 15
}

release_lock() {
	_lock_set_vars $1
	[ "$_have_lock" != 0 -a -f $_lockfile ] && rm $_lockfile
	_have_lock=0
	_lock_signal_cv;
}
