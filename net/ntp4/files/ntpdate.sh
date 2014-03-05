#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ntpdate.sh,v 1.2 2014/03/05 12:24:43 obache Exp $
#

# PROVIDE: ntpdate
# REQUIRE: NETWORKING syslogd

. /etc/rc.subr

name="ntpdate"
rcvar=$name
start_cmd="ntpdate_start"
stop_cmd=":"

ntpdate_start()
{
	if [ -z "$ntpdate_hosts" ]; then
		ntpdate_hosts=`awk '
		    /^server[ \t]*127.127/	{next}
		    /^(server|peer)/		{print $2}
		' <@PKG_SYSCONFDIR@/ntp.conf`
	fi
	if [ -n "$ntpdate_hosts"  ]; then
		echo "Setting date via ntp."
		@PREFIX@/sbin/ntpdate $rc_flags $ntpdate_hosts
	fi
}

load_rc_config $name
run_rc_command "$1"
