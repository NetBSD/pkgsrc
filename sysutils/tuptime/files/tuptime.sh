#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tuptime.sh,v 1.1 2026/06/06 18:39:55 wiz Exp $
#
# PROVIDE: tuptime
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Record the uptime at boot (tuptime -q) and at shutdown (tuptime -qg),
# as the _tuptime user.  Enable by adding  tuptime=YES  to /etc/rc.conf.

. /etc/rc.subr

name="tuptime"
rcvar=${name}
command="@PREFIX@/bin/tuptime"
tuptime_user="_tuptime"
start_cmd="tuptime_start"
stop_cmd="tuptime_stop"

tuptime_start()
{
	echo "Starting ${name}."
	su -m ${tuptime_user} -c "${command} -q"
}

tuptime_stop()
{
	echo "Stopping ${name}."
	su -m ${tuptime_user} -c "${command} -qg"
}

load_rc_config "${name}"
run_rc_command "$1"
