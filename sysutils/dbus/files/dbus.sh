#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.8.2.1 2008/10/12 11:46:30 rtr Exp $
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
	dir="@VARBASE@/run/dbus"
	if @TEST@ ! -d $dir; then
		@MKDIR@ $dir
		@CHMOD@ 0755 $dir
		@CHOWN@ @DBUS_USER@:@DBUS_GROUP@ $dir
	fi
	@PREFIX@/bin/dbus-uuidgen --ensure
}

load_rc_config $name
run_rc_command "$1"
