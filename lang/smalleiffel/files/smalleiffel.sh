#!/bin/sh
#
# $NetBSD: smalleiffel.sh,v 1.1.1.1 1999/04/12 18:19:27 jlam Exp $
#
# This script is invoked as:
#
# 	smalleiffel <cmd> [<arg> ...]
#
# where <cmd> is one of the programs in @@SE@@/bin.
#
SmallEiffel=@@SE@@/sys/system.se ; export SmallEiffel
se_cmd=@@SE@@/bin/$1
if [ -x ${se_cmd} ]
then
	shift
	exec ${se_cmd} ${1+$@}
else
	echo "smalleiffel: command ${se_cmd} not found."
fi
