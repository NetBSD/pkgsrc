#! /bin/sh
#
# $NetBSD: unwrap-config.sh,v 1.1.1.1 2004/08/28 06:17:21 jlam Exp $
#
# This is a dummy *-config script that is used to test whether these
# files are correctly "unwrapped" at post-build time.

prefix="@PREFIX@"
exec_prefix="${prefix}"

includedir="${prefix}/include"
libdir="${exec_prefix}/lib"

output=""
for option do
	case $option in
	--cflags)
		output="$output -O2 -I${includedir}"
		;;
	--ldflags)
		output="$output -L${libdir} @COMPILER_RPATH_FLAG@${libdir}"
		;;
	--libs)
		output="$output -lreadline"
		;;
	esac
done

echo $output
