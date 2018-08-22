#! @WRAPPER_SHELL@
#
# $NetBSD: gen-reorder.sh,v 1.2 2018/08/22 20:48:37 maya Exp $
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

shell_lib="@_WRAP_SHELL_LIB@"
wrapperlog="${WRAPPER_LOG-@_WRAP_LOG@}"
debug="${WRAPPER_DEBUG-no}"

cat="@CAT@"

. $shell_lib

case $debug in
yes)	debug_log="msg_log" ;;
*)	debug_log=":" ;;
esac

######################################################################
# gen reorder:l:foo:bar
#	Outputs a branch of a shell case statement that reorders
#	libs to ensure that "-lfoo" occurs before "-lbar".
######################################################################
gen() {
	save_IFS="${IFS}"; IFS=":"
	set -- $1
	IFS="${save_IFS}"
	_cmd="$1"; shift
	case $_cmd in
	reorder)
		$debug_log $wrapperlog "    (gen-reorder) $_cmd: $@"
		case $1 in
		l)
			$cat << EOF
		# -l$2 comes before -l$3
		-l$2)
			case "\${_libs}" in
			-l$3|-l$3" "*)
				_libs="\$l \${_libs}"
				;;
			*" "-l$3)
				_libs="\${_libs%%-l$3}\$l -l$3"
				;;
			*" "-l$3" "*)
				_libs="\${_libs%% -l$3 *} \$l -l$3 \${_libs#* -l$3 }"
				;;
			*)
				_libs="\${_libs} \$l"
				;;
			esac
			;;
EOF
			;;
		esac
		;;
	*)
		$debug_log $wrapperlog "    (gen-reorder) $_cmd: $@ [unknown]"
		;;
	esac
}

######################################################################
# Header for reorder script
######################################################################
$cat << 'EOF'
msg_log $wrapperlog "==> Reordering libraries: $libs"
prevlibs=
while $test "$libs" != "$prevlibs"; do
	_libs=
	for l in $libs; do
		case $l in
EOF

######################################################################
# Generate body for reorder script.
######################################################################
for arg do
	gen "$arg"
done

######################################################################
# Footer for reorder script
######################################################################
$cat << 'EOF'
		*)
			_libs="${_libs} $l"
			;;
		esac
		_libs="${_libs# }"
		_libs="${_libs% }"
	done
	prevlibs="$libs"
	libs="${_libs}"
done

# This section suppresses duplicate libraries in sequence.
_libs=
for l in $libs; do
	case "${_libs}" in
	$l|*" "$l) ;;
	*) _libs="${_libs} $l" ;;
	esac
done
_libs="${_libs# }"
_libs="${_libs% }"
libs="${_libs}"
EOF

exit 0
