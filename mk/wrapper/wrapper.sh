#! @WRAPPER_SHELL@
#
# $NetBSD: wrapper.sh,v 1.24 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2004 The NetBSD Foundation, Inc.
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

#set -eu

# The list of include files for the wrapper.
empty_file="@_WRAP_EMPTY_FILE@"
arg_pp="@_WRAP_ARG_PP@"
arg_pp_main="@_WRAP_ARG_PP_MAIN@"
arg_source="@_WRAP_ARG_SOURCE@"
buildcmd="@_WRAP_BUILDCMD@"
cache="@_WRAP_CACHE@"
cache_body="@_WRAP_CACHE_BODY@"
cleanup="@_WRAP_CLEANUP@"
cmd_sink="@_WRAP_CMD_SINK@"
logic="@_WRAP_LOGIC@"
reorderlibs="@_WRAP_REORDERLIBS@"
shell_lib="@_WRAP_SHELL_LIB@"
scan="@_WRAP_SCAN@"
transform="@_WRAP_TRANSFORM@"
transform_sed="@_WRAP_TRANSFORM_SED@"
wrapper_subr_sh="@_WRAP_SUBR_SH@"

# Information about the wrapper and its environment.
wrapper_abi="@ABI@"		# see ABI in mk/defaults/mk.conf
wrapper_type="@_WRAP_TYPE@"	# one of AS, CC, CXX, FC, IMAKE, LD, LIBTOOL.
wrapperlog="${WRAPPER_LOG-@_WRAP_LOG@}"
skip_transform="${WRAPPER_SKIP_TRANSFORM-@_WRAP_SKIP_TRANSFORM@}"
debug="${WRAPPER_DEBUG-@WRAPPER_DEBUG@}"

# Tools that can be used by the wrapper.
# XXX: Why is this necessary? Isn't the wrapper only called with
# TOOLS_DIR/bin in the PATH?
#
cat="@CAT@"
echo="@ECHO@"
expr="@EXPR@"
mv="@MV@"
sed="@SED@"
test="@TEST@"
Xsed="$sed -e 1s/^X//"

. $shell_lib
. "$wrapper_subr_sh"

updatecache=${WRAPPER_UPDATE_CACHE-@WRAPPER_UPDATE_CACHE@}
reorder=${WRAPPER_REORDER-no}

case $debug in
yes)	debug_log="msg_log" ;;
*)	debug_log=":" ;;
esac

qcmd="$0"; for arg in ${1+"$@"}; do shquote "$arg"; qcmd="$qcmd $shquoted"; done
msg_log "$wrapperlog" "[*] $0 $qcmd"

cmd="@WRAPPEE@"
case "$*" in
--wrappee-name) $echo $cmd ; exit ;;
esac

libs=""
rellpath=""
do_transform=yes
init_queue argbuf
init_queue cmdbuf

append_extra_args=yes
. $scan

case $append_extra_args in
yes)
	$debug_log $wrapperlog "    (wrapper.sh) append args: @_WRAP_EXTRA_ARGS@"
	set -- "$@" @_WRAP_EXTRA_ARGS@
	;;
*)
	;;
esac

. $arg_source
. $logic
. $cmd_sink

# Reorder the libraries so that the library dependencies are correct.
case $reorder in
yes)
	if $test -n "$libs"; then
		. $reorderlibs
	fi
	;;
esac

cmdline="$cmd $libs"

@_WRAP_ENV@

msg_log $wrapperlog "<.>" "$cmdline"

if [ "${empty_file}" = "${cleanup}" ] && [ "$debug" != "yes" ]; then
	eval "exec $cmdline"
	wrapper_result=$?
else
	wrapper_result=0
	eval "$cmdline" || wrapper_result="$?"
fi

. $cleanup

[ $wrapper_result -eq 0 ] || [ "$debug" != "yes" ] || {
	echo ""
	echo "[wrapper.sh] note: The real command line, after the pkgsrc wrapper, was:"
	echo "$cmdline"
} 1>&2

exit ${wrapper_result}
