#!/bin/sh
#
# $NetBSD: smalleiffel.sh,v 1.3 1999/10/12 08:01:33 jlam Exp $
#
# This script is invoked as:
#
# 	smalleiffel <cmd> [<arg> ...]
#
# where <cmd> is one of the programs in @@SE_LIBEXEC@@.
#
SMALLEIFFEL=@@SE_LIB@@; export SMALLEIFFEL
SmallEiffel=${SMALLEIFFEL}/sys/system.se; export SmallEiffel
se_cmd=@@SE_LIBEXEC@@/$1
shift

# Load the personal SmallEiffel environment from ${HOME}/.smalleiffelrc.
# This file is the right place to define new environment variables used
# by 3rd-party libraries, e.g. GOBO=/usr/pkg/share/gobo-eiffel.
#
if [ -f ${HOME}/.smalleiffelrc ]
then
	. ${HOME}/.smalleiffelrc
fi

if [ -x ${se_cmd} ]
then
	exec ${se_cmd} ${1+$@}
else
	echo "smalleiffel: command ${se_cmd} not found."
fi
