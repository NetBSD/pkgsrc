#! @WRAPPER_SHELL@
#
# $NetBSD: gen-transform.sh,v 1.11 2016/03/14 20:11:56 markd Exp $
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

shell_lib="@_WRAP_SHELL_LIB@"
wrapperlog="${WRAPPER_LOG-@_WRAP_LOG@}"
debug="${WRAPPER_DEBUG-no}"

echo="@ECHO@"
test="@TEST@"

. $shell_lib

case $debug in
yes)	debug_log="msg_log" ;;
*)	debug_log=":" ;;
esac

rpath_options="-Wl,--rpath, -Wl,-rpath-link, -Wl,-rpath, -Wl,-R -R"

######################################################################
# gen action arg
#	Outputs sed commands that correspond to $action for $arg.  The
#	"transform" action pertains to transforming command-line options,
#	while the "untransform" action pertains to unwrapping *-config
#	files, *.pc files, and *.lai (to-be-installed libtool archive)
#	files.
######################################################################
gen()
{
	_sep=" 	\`\"':;,"

	_action=$1; shift
	save_IFS="${IFS}"; IFS=":"
	set -- $1
	IFS="${save_IFS}"
	_cmd="$1"; shift

	case $_cmd in
        ###############################################################
        # I:src:dst
        #       Change "src" into "dst" and "src/*" into "dst/*" in -I
	#	options for transform, and back for untransform.
        ###############################################################
	I)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			gen $_action "opt:-I$1:-I$2"
			gen $_action "opt:-isystem,$1:-isystem,$2"
			gen $_action "opt-sub:-I$1:-I$2"
			gen $_action "opt-sub:-isystem,$1:-isystem,$2"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			gen $_action "opt:-I$2:-I$1"
			gen $_action "opt:-isystem,$2:-isystem,$1"
			gen $_action "opt-sub:-I$2:-I$1"
			gen $_action "opt-sub:-isystem,$2:-isystem,$1"
			;;
		esac
		;;
        ###############################################################
        # L:src:dst
        #       Change "src" into "dst" and "src/*" into "dst/*" in -L
	#	options for transform, and back for untransform.
        ###############################################################
	L)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			gen $_action "opt:-L$1:-L$2"
			gen $_action "opt-sub:-L$1:-L$2"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			gen $_action "opt:-L$2:-L$1"
			gen $_action "opt-sub:-L$2:-L$1"
			;;
		esac
		;;
	###############################################################
	# l:foo:bar[:baz1...]
	#	Change "-lfoo" into "-lbar [-lbaz...]"
	###############################################################
	l)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		tolibs=
		fromlib="-l$1"; shift
		while $test $# -gt 0; do
			case $1 in
			"")	;;
			*)	case $tolibs in
				"")	tolibs="-l$1" ;;
				*)	tolibs="$tolibs -l$1" ;;
				esac
				;;
			esac
			shift
		done
		gen $_action "opt:$fromlib:$tolibs"
		;;
	##############################################################
	# libpath:src:dst
	#	Change "src/*/libfoo.{a,la}" into "dst/*/libfoo.{a,la}".
	##############################################################
	libpath)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|^$1\(/[^$_sep]*\.la[$_sep]\)|$2\1|g"
			$echo "s|^$1\(/[^$_sep]*\.la\)$|$2\1|g"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|\([$_sep]\)$1\(/[^$_sep]*\.la[$_sep]\)|\1$2\2|g"
			$echo "s|\([$_sep]\)$1\(/[^$_sep]*\.la[$_sep]\)|\1$2\2|g"
			$echo "s|\([$_sep]\)$1\(/[^$_sep]*\.la\)$|\1$2\2|g"
			$echo "s|^$1\(/[^$_sep]*\.la[$_sep]\)|$2\1|g"
			$echo "s|^$1\(/[^$_sep]*\.la\)$|$2\1|g"
			;;
		esac
		;;
	##############################################################
	# mangle:src:dst
	#	Change "src" into "dst" and "src/*" into "dst/*" in -I,
	#	-L, and rpath options, and also in full paths to
	#	libraries.
	##############################################################
	mangle)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		#gen $_action "opt:$1:$2"
		gen $_action "opt:-I$1:-I$2"
		gen $_action "opt:-isystem,$1:-isystem,$2"
		gen $_action "opt:-L$1:-L$2"
		gen $_action "rpath-exact:$1:$2"
		gen $_action "sub-mangle:$1:$2"
		;;
	##############################################################
	# no-abspath
	#	Remove all "dash" options that contain an absolute path.
	##############################################################
	no-abspath)
		$debug_log $wrapperlog "   (gen-transform) $_cmd"
		gen $_action "rm-optarg:-I/"
		gen $_action "rm-optarg:-isystem,/"
		gen $_action "rm-optarg:-L/"
		for _R in $rpath_options; do
			gen $_action "rm-optarg:$_R/"
		done
		;;
	##############################################################
	# no-rpath
	#	Removes rpath options.
	##############################################################
	no-rpath)
		$debug_log $wrapperlog "   (gen-transform) $_cmd"
		gen $_action rm-optarg:-Wl,--rpath,
		gen $_action rm-optarg:-Wl,-rpath-link,
		gen $_action rm-optarg:-Wl,-rpath,
		gen $_action rm-optarg:-Wl,-R
		gen $_action rm-optarg:-R
		;;
	##############################################################
	# opt:src:dst
	#	Change "src" into "dst", where "src" matches the whole
	#	option or a leading part up to a separator character.
	##############################################################
	opt)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|^$1\([$_sep]\)|$2\1|g"
			$echo "s|^$1$|$2|g"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|\([$_sep]\)$1\([$_sep]\)|\1$2\2|g"
			$echo "s|\([$_sep]\)$1\([$_sep]\)|\1$2\2|g"
			$echo "s|\([$_sep]\)$1$|\1$2|g"
			$echo "s|^$1\([$_sep]\)|$2\1|g"
			$echo "s|^$1$|$2|g"
			;;
		esac
		;;
	##############################################################
	# opt-sub:src:dst
	#	Change "src/*" into "dst/*".
	##############################################################
	opt-sub)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		gen $_action "opt-sub-trailer:$1::$2:"
		;;
	##############################################################
	# opt-sub-trailer:src:src_trailer:dst:dst_trailer
	#	Change "src/*src_trailer" into "dst/*dst_trailer",
	#	where "src/*" matches "src" plus subdirectories.
	##############################################################
	opt-sub-trailer)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|^$1\(/[^$_sep]*\)$2\([$_sep]\)|$3\1$4|g"
			$echo "s|^$1\(/[^$_sep]*\)$2$|$3\1$4|g"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|\([$_sep]\)$1\(/[^$_sep]*\)$2\([$_sep]\)|\1$3\2$4\3|g"
			$echo "s|\([$_sep]\)$1\(/[^$_sep]*\)$2\([$_sep]\)|\1$3\2$4\3|g"
			$echo "s|\([$_sep]\)$1\(/[^$_sep]*\)$2$|\1$3\2$4|g"
			$echo "s|^$1\(/[^$_sep]*\)$2\([$_sep]\)|$3\1$4|g"
			$echo "s|^$1\(/[^$_sep]*\)$2$|$3\1$4|g"
			;;
		esac
		;;
	##############################################################
	# P:src:dst
	#	Change "src/*/libfoo.{a,la}" into "dst/*/libfoo.{a,la}"
	#	for transform, and back for untransform.
	##############################################################
	P)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			gen $_action "libpath:$1:$2"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			gen $_action "libpath:$2:$1"
			;;
		esac
		;;
	##############################################################
	# rename:src:dst
	#	Synonym for "opt:src:dst".
	##############################################################
	rename)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		gen $_action "opt:$1:$2"
		;;
	##############################################################
	# rm:opt
	#	Remove "opt", where "opt" matches the entire option.
	##############################################################
	rm)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		gen $_action "opt:$1:"
		;;
	##############################################################
	# rm-optarg:opt
	#	Remove "opt" and any argument of that option where the
	#	two are combined in one word.
	##############################################################
	rm-optarg)
		case $_action in
		transform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|^$1[^$_sep]*\([$_sep]\)|\1|g"
			$echo "s|^$1[^$_sep]*$||g"
			;;
		untransform)
			$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
			$echo "s|\([$_sep]\)$1[^$_sep]*\([$_sep]\)|\1\2|g"
			$echo "s|\([$_sep]\)$1[^$_sep]*\([$_sep]\)|\1\2|g"
			$echo "s|\([$_sep]\)$1[^$_sep]*$|\1|g"
			$echo "s|^$1[^$_sep]*\([$_sep]\)|\1|g"
			$echo "s|^$1[^$_sep]*$||g"
			;;
		esac
		;;
	##############################################################
	# rmdir:dir
	#	Remove all "dash" options that contain "dir" or "dir/*".
	##############################################################
	rmdir)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		gen $_action "opt:-I$1:"
		gen $_action "opt:-isystem,$1:"
		gen $_action "rm-optarg:-I$1/"
		gen $_action "rm-optarg:-isystem,$1/"
		gen $_action "opt:-L$1:"
		gen $_action "rm-optarg:-L$1/"
		for _R in $rpath_options; do
			gen $_action "opt:$_R$1:"
			gen $_action "rm-optarg:$_R$1/"
		done
		;;
	##############################################################
	# rpath:src:dst
        #       Change "src" into "dst" and "src/*" into "dst/*" in rpath
	#	options.
	##############################################################
	rpath)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		gen $_action "rpath-exact:$1:$2"
		gen $_action "sub-rpath:$1:$2"
		;;
	##############################################################
	# rpath-exact:src:dst
        #       Change "src" into "dst" in rpath options.
	##############################################################
	rpath-exact)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		for _R in $rpath_options; do
			gen $_action "opt:$_R$1:$_R$2"
		done
		;;
	##############################################################
	# strip-slashdot:dir
	#	Change "dir/." into "dir" and the same in -I, -L, and
	#	rpath options.
	##############################################################
	strip-slashdot)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		gen $_action "opt-sub-trailer:$1:/\.:$1:"
		gen $_action "opt-sub-trailer:-I$1:/\.:-I$1:"
		gen $_action "opt-sub-trailer:-isystem,$1:/\.:-isystem,$1:"
		gen $_action "opt-sub-trailer:-L$1:/\.:-L$1:"
		for _R in $rpath_options; do
			gen $_action "opt-sub-trailer:$_R$1:/\.:$_R$1:"
		done
		;;
	##############################################################
	# sub-mangle:src:dst
	#	Change "src/*" into "dst/*" in -I, -L, and rpath
	#	options, and also in full paths to libraries.
	##############################################################
	sub-mangle)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		#gen $_action "opt-sub:$1:$2"
		gen $_action "libpath:$1:$2"
		gen $_action "opt-sub:-I$1:-I$2"
		gen $_action "opt-sub:-isystem,$1:-isystem,$2"
		gen $_action "opt-sub:-L$1:-L$2"
		gen $_action "sub-rpath:$1:$2"
		;;
	##############################################################
	# sub-rpath:src:dst
	#	Change "src/*" into "dst/*" in rpath options.
	##############################################################
	sub-rpath)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@"
		for _R in $rpath_options; do
			gen $_action "opt-sub:$_R$1:$_R$2"
		done
		;;
	##############################################################
	# Everything else is ignored.
	##############################################################
	*)
		$debug_log $wrapperlog "   (gen-transform) $_cmd: $@ [unknown]"
		;;
	esac
}

######################################################################
# Generate sed script.
######################################################################
action="$1"; shift
for arg do
	case $arg in
	transform:*)
		case $action in
		transform) gen $action "${arg#transform:}" ;;
		esac
		;;
	untransform:*)
		case $action in
		untransform) gen $action "${arg#untransform:}" ;;
		esac
		;;
	*)
		gen $action "$arg"
		;;
	esac
done
