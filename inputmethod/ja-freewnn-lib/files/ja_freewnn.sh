#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ja_freewnn.sh,v 1.1 2003/07/29 21:13:21 jmmv Exp $
#
# PROVIDE: freewnn
# REQUIRE: DAEMON

. /etc/rc.subr

name="freewnn"
command_start="@PREFIX@/sbin/jserver"
command_stop="@PREFIX@/sbin/wnnkill"
pidfile=""

cmd=${1:-start}

case ${cmd} in
start)
    if [ -x ${command_start} ]; then
	echo "Starting ${name}."
        ${command_start} >/dev/null 2>&1
    fi
    ;;
stop)
    if [ -x ${command_stop} ]; then
        echo "Stopping ${name}."
        ${command_stop} >/dev/null 2>&1
    fi
    ;;
*)
    :
    ;;
esac
exit 0
