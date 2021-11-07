#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.11 2021/11/07 19:14:16 khorben Exp $
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start dbus:
#
# dbus=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="dbus"
rcvar=$name
command="@PREFIX@/bin/dbus-daemon"
command_args="--system --fork"
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
