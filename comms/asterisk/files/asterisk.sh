#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: asterisk.sh,v 1.4 2008/11/24 09:27:29 jnemeth Exp $
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
extra_commands="reload"

stop_cmd="$command -r -x 'stop gracefully' >/dev/null"
reload_cmd="$command -r -x 'reload' >/dev/null"
asterisk_nice="-20"

load_rc_config $name
run_rc_command "$1"
