#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: trickled.sh,v 1.2 2003/09/27 02:31:48 xtraeme Exp $
#
# PROVIDE: trickled
# REQUIRE: DAEMON

. /etc/rc.subr

name="trickled"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/trickled.conf"

load_rc_config $name
run_rc_command "$1"
