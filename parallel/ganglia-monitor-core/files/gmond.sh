#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gmond.sh,v 1.1 2007/09/16 10:29:53 joerg Exp $
#
# PROVIDE: gmond
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start gmond:
#
# gmond=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="gmond"
rcvar=$name
command="@PREFIX@/sbin/gmond"
required_files="@PKG_SYSCONFDIR@/gmond.conf"
start_cmd="gmond_start"
stop_cmd="gmond_stop"
restart_cmd="gmond_stop ; gmond_start"

gmond_start ()
{
	${command}
}

gmond_stop()
{
	pkill ${name} 2>/dev/null
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	eval ${start_cmd}
fi
