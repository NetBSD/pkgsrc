#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: asterisk.sh,v 1.8 2023/01/07 19:31:18 ryoon Exp $
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
pidfile=@ASTVARRUNDIR@/${name}.pid
required_files="@PKG_SYSCONFDIR@/asterisk.conf"
extra_commands="reload"
start_precmd=asterisk_prestart

auser="@ASTERISK_USER@"
agroup="@ASTERISK_GROUP@"
command_args="-U $auser -G $agroup"

asterisk_prestart() {
	if test ! -d @ASTVARRUNDIR@; then
		mkdir @ASTVARRUNDIR@
	fi
	chown $auser:$agroup @ASTVARRUNDIR@
	chmod 0755 @ASTVARRUNDIR@
}

stop_cmd="$command -r -x 'core stop gracefully' >/dev/null"
reload_cmd="$command -r -x 'core reload' >/dev/null"
asterisk_nice="-20"

load_rc_config $name
run_rc_command "$1"
