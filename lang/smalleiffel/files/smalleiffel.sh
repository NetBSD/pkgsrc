#!/bin/sh
#
# $NetBSD: smalleiffel.sh,v 1.8 2004/11/28 15:15:30 wiz Exp $
#
# This script is invoked as:
#
# 	smalleiffel <cmd> [<arg> ...]
#
# where <cmd> is one of the programs in @@SE_LIBEXEC@@.
#
SmallEiffel=@@SE_LIB@@/sys/system.se; export SmallEiffel

if [ -z $1 ]
then
	cat << EOF
Usage:
	smalleiffel <cmd> [<arg> ...]

where <cmd> can be:

	clean
	compile
	compile_to_c
	compile_to_jvm
	finder
	pretty
	print_jvm_class
	short

For more documentation on these commands, point a Web browser at:

	@@SE_DOC@@/index.html

EOF
exit 0
fi

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
