#!/bin/sh
#
#	$NetBSD: skkserv.sh,v 1.3 2001/01/16 23:28:11 pooka Exp $
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
