#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.7 2006/12/15 19:06:00 drochner Exp $
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
	for f in "@VARBASE@/lib/dbus" "@VARBASE@/run/dbus"; do
		if @TEST@ ! -d $f; then
			@MKDIR@ $f
			@CHMOD@ 0755 $f
			@CHOWN@ @DBUS_USER@:@DBUS_GROUP@ $f
		fi
	done
	@PREFIX@/bin/dbus-uuidgen --ensure
}

load_rc_config $name
run_rc_command "$1"
