#!/bin/sh
#
# $NetBSD: smalleiffel.sh,v 1.4 1999/10/13 19:03:39 jlam Exp $
#
# This script is invoked as:
#
# 	smalleiffel <cmd> [<arg> ...]
#
# where <cmd> is one of the programs in @@SE_LIBEXEC@@.
#
SmallEiffel=@@SE_LIB@@/sys/system.se; export SmallEiffel
se_cmd=@@SE_LIBEXEC@@/$1
shift

# Load the local SmallEiffel environment from:
#	./.smalleiffelrc, or else
#	${HOME}/.smalleiffelrc.
# This file is the right place to define new environment variables used
# by 3rd-party libraries, e.g. GOBO=/usr/pkg/share/gobo-eiffel.
#
if [ -f ./.smalleiffelrc ]
then
	. ./.smalleiffelrc
elif [ -f ${HOME}/.smalleiffelrc ]
then
	. ${HOME}/.smalleiffelrc
fi

if [ -x ${se_cmd} ]
then
	exec ${se_cmd} ${1+$@}
else
	echo "smalleiffel: command ${se_cmd} not found."
fi
