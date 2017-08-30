#!/bin/sh
#
# $NetBSD: strip_fopt.sh,v 1.4 2017/08/30 19:47:08 wiz Exp $
#
# libtool assumes that the compiler can handle the -fPIC flag and the
# -fno-common. This isn't always true, for example yasm can't handle it.
command="$1"
shift
while [ $# -gt 0 ]; do
	case "$1" in
	-fPIC|-fno-common|-pie)
		;;
	*)
		command="$command $1"
		;;
	esac
	shift
done
echo $command
exec $command
