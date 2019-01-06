#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: miredo.sh,v 1.2 2019/01/06 00:12:39 schmonz Exp $

# PROVIDE: miredo
# REQUIRE: NETWORKING

. /etc/rc.subr

name="miredo"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-u @MIREDO_USER@"
required_files="@PKG_SYSCONFDIR@/miredo.conf"
pidfile="@VARBASE@/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
