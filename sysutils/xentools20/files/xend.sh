#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xend.sh,v 1.1 2005/03/17 23:53:56 bouyer Exp $
#
# PROVIDE: xend
# REQUIRE: disks network

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="xend"
rcvar=$name
command="@PREFIX@/sbin/xend"
ctl_command="@PREFIX@/sbin/xend"
start_cmd="echo starting ${command} && ${command} start"
stop_cmd="echo stopping ${command} && ${command} stop"
restart_cmd="echo restarting ${command} && ${command} restart"

load_rc_config $name
run_rc_command "$1"
