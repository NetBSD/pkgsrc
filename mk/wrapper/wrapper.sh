#! @WRAPPER_SHELL@
#
# $NetBSD: wrapper.sh,v 1.2 2004/09/22 17:56:31 jlam Exp $
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
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
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

arg_source="@_WRAP_ARG_SOURCE@"
buildcmd="@_WRAP_BUILDCMD@"
cache="@_WRAP_CACHE@"
cache_header="@_WRAP_CACHE_HEADER@"
cache_body="@_WRAP_CACHE_BODY@"
cache_footer="@_WRAP_CACHE_FOOTER@"
cleanup="@_WRAP_CLEANUP@"
cmd_sink="@_WRAP_CMD_SINK@"
logic="@_WRAP_LOGIC@"
reorderlibs="@_WRAP_REORDERLIBS@"
shell_lib="@_WRAP_SHELL_LIB@"
scan="@_WRAP_SCAN@"
transform="@_WRAP_TRANSFORM@"
wrapperlog="${WRAPPER_LOG-@_WRAP_LOG@}"
skip_transform="${WRAPPER_SKIP_TRANSFORM-@_WRAP_SKIP_TRANSFORM@}"
debug="${WRAPPER_DEBUG-no}"
append_extra_args=yes

cat="@CAT@"  
echo="@ECHO@"
expr="@EXPR@"
sed="@SED@"
test="@TEST@"
Xsed="$sed -e 1s/^X//"

. $shell_lib

updatecache=${WRAPPER_UPDATE_CACHE-yes}
reorder=${WRAPPER_REORDER-no}

case $debug in
yes)	debug_log="msg_log" ;;
*)	debug_log=":" ;;
esac

original_cmd="$0 $@"
msg_log $wrapperlog "[*]" $original_cmd

cmd="@WRAPPEE@"
do_transform=yes
init_queue argbuf
init_queue cmdbuf

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

cmd="$cmd $libs"

@_WRAP_ENV@

msg_log $wrapperlog "<.>" $cmd
eval $cmd
wrapper_result=$?

. $cleanup

exit ${wrapper_result}
