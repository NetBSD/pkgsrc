#!/bin/sh
#
#	$NetBSD: skkserv.sh,v 1.1.1.1.2.2 2002/06/23 18:48:22 jlam Exp $
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
