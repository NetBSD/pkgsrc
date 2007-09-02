#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tetrinetx.sh,v 1.1 2007/09/02 12:33:14 joerg Exp $
#
# PROVIDE: tetrinetx
# REQUIRE: DAEMON LOGIN network

. /etc/rc.subr

name="tetrinetx"
rcvar=$name
command="@PREFIX@/bin/tetrix"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PREFIX@/share/tetrinetx/game.conf"

load_rc_config $name
run_rc_command "$1"
