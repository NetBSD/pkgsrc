#!/bin/sh
#
# $NetBSD: strip_fopt.sh,v 1.2 2008/12/18 16:19:07 bjs Exp $
#
# libtool assumes that the compiler can handle the -fPIC flag and the
# -fno-common. This isn't always true, for example yasm can't handle it.
command="$1"
shift
while [ $# -gt 0 ]; do
	case "$1" in
	-fPIC|-fno-common)
		;;
	-DPIC)
		command="$command -D__PIC__"
		;;
	*)
		command="$command $1"
		;;
	esac
	shift
done
echo $command
exec $command
