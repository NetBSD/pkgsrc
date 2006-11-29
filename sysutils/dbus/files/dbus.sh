#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.6 2006/11/29 10:11:53 ghen Exp $
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
		@CHOWN@ @DBUS_USER@:@DBUS_GROUP@ "@VARBASE@/run/dbus"
	fi
	@PREFIX@/bin/dbus-uuidgen --ensure
}

load_rc_config $name
run_rc_command "$1"
