#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.2 2004/10/12 08:15:35 jmmv Exp $
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="dbus"
rcvar=$name
command="@PREFIX@/bin/dbus-daemon-1"
command_args="--system"
pidfile="@VARBASE@/run/dbus/pid"
start_precmd=dbus_prestart
dbus_user=messagebus
dbus_group=messagebus

dbus_prestart() {
	if @TEST@ ! -d "@VARBASE@/run/dbus"; then
		@MKDIR@ "@VARBASE@/run/dbus"
		@CHMOD@ 0755 "@VARBASE@/run/dbus"
		@CHOWN@ ${dbus_user}:${dbus_group} "@VARBASE@/run/dbus"
	fi
}

load_rc_config $name
run_rc_command "$1"
