#!/bin/sh
#
# $NetBSD: smalleiffel.sh,v 1.2 1999/06/21 21:23:16 jlam Exp $
#
# This script is invoked as:
#
# 	smalleiffel <cmd> [<arg> ...]
#
# where <cmd> is one of the programs in @@SE@@/bin.
#
SMALLEIFFEL=@@SE@@; export SMALLEIFFEL
SmallEiffel=${SMALLEIFFEL}/sys/system.se ; export SmallEiffel
se_cmd=${SMALLEIFFEL}/bin/$1
if [ -x ${se_cmd} ]
then
	shift
	exec ${se_cmd} ${1+$@}
else
	echo "smalleiffel: command ${se_cmd} not found."
fi
