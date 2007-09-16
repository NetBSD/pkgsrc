#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gmetad.sh,v 1.1 2007/09/16 10:29:53 joerg Exp $
#
# PROVIDE: gmetad
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start gmetad:
#
# gmetad=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="gmetad"
rcvar=$name
command="@PREFIX@/sbin/gmetad"
required_files="@PKG_SYSCONFDIR@/gmetad.conf"
start_cmd="gmetad_start"
stop_cmd="gmetad_stop"
restart_cmd="gmetad_stop ; gmetad_start"

gmetad_start ()
{
	# gmetad/process_xml.c 1060 re-releases a lock, claiming it's 
	# ``required under certain errors''
	export PTHREAD_DIAGASSERT=A
	${command}
}

gmetad_stop()
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
