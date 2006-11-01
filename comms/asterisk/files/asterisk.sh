#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: asterisk.sh,v 1.2 2006/11/01 18:59:16 mjl Exp $
#
# PROVIDE: asterisk
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start Asterisk:
#
# asterisk=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="asterisk"
rcvar=$name
command="@PREFIX@/sbin/asterisk"
required_files="@PKG_SYSCONFDIR@/asterisk.conf"

#start_cmd="asterisk_doit start"
#restart_cmd="asterisk_doit restart"
stop_cmd="sudo asterisk -r -x 'stop gracefully' >/dev/null"
asterisk_nice="-20"

load_rc_config $name
run_rc_command "$1"
