#!/bin/sh
#
#	$NetBSD: skkserv.sh,v 1.1.1.1 2002/05/31 12:59:58 seb Exp $
#
# PROVIDE: skkserv
# REQUIRE: DAEMON
 
name="skkserv"
command="@PREFIX@/libexec/skkserv"
pidfile=""

cmd=${1:-start}

case ${cmd} in
start)
	if [ -x ${command}  ]; then
		echo "Starting ${name}."
		${command} > /dev/null 2>&1
	fi
	;;
*)
	if [ -x ${command} ]; then
		${command} ${cmd} > /dev/null 2>&1
	fi
	;;
esac
