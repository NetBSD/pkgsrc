#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.1.1.1 2004/10/11 17:45:27 jmmv Exp $
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="dbus"
rcvar=$name
command="@PREFIX@/bin/dbus-daemon-1"
command_args="--system"
required_dirs="@VARBASE@/run/dbus"
pidfile="@VARBASE@/run/dbus/pid"
dbus_user=messagebus
dbus_group=messagebus

load_rc_config $name
run_rc_command "$1"
