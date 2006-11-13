#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.5 2006/11/13 15:16:20 drochner Exp $
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="dbus"
rcvar=$name
command="@PREFIX@/bin/dbus-daemon"
command_args="--system"
pidfile="@VARBASE@/run/dbus/pid"
start_precmd=dbus_prestart

dbus_prestart() {
	if @TEST@ ! -d "@VARBASE@/run/dbus"; then
		@MKDIR@ "@VARBASE@/run/dbus"
		@CHMOD@ 0755 "@VARBASE@/run/dbus"
		@CHOWN@ messagebus:messagebus "@VARBASE@/run/dbus"
	fi
	@PREFIX@/bin/dbus-uuidgen --ensure
}

load_rc_config $name
run_rc_command "$1"
