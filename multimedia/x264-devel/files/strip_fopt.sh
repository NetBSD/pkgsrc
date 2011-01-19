#!/bin/sh
#
# $NetBSD: strip_fopt.sh,v 1.3 2011/01/19 12:45:12 drochner Exp $
#
# libtool assumes that the compiler can handle the -fPIC flag and the
# -fno-common. This isn't always true, for example yasm can't handle it.
command="$1"
shift
while [ $# -gt 0 ]; do
	case "$1" in
	-fPIC|-fno-common)
		;;
	*)
		command="$command $1"
		;;
	esac
	shift
done
echo $command
exec $command
