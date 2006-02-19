#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: honeyd.sh,v 1.2 2006/02/19 17:23:18 adrianp Exp $
#

# PROVIDE: honeyd
# REQUIRE: DAEMON
# AFTER:  honeydarpd

. /etc/rc.subr

name="honeyd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
