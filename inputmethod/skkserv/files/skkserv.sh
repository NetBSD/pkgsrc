#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: skkserv.sh,v 1.2 2003/07/29 22:08:29 jmmv Exp $
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
