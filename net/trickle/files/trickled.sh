#!@RCS_SCRIPTS_SHELL@
#
# $NetBSD: trickled.sh,v 1.1.1.1 2003/09/25 14:19:42 xtraeme Exp $
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
