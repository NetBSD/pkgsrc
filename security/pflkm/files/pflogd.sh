#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pflogd.sh,v 1.1.1.1 2004/11/05 15:05:30 peter Exp $
#
# PROVIDE: pflogd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pflogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
start_precmd="/sbin/ifconfig pflog0 up"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
