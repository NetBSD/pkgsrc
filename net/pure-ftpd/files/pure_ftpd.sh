#!@RCD_SCRIPTS_SHELL@
#
# 	$NetBSD: pure_ftpd.sh,v 1.2 2010/02/04 12:34:08 obache Exp $
#
# PROVIDE: pure_ftpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="pure_ftpd"
help_name="pure-ftpd"
rcvar=$name
command="@PREFIX@/sbin/${help_name}"
command_args="-B"
pidfile="@VARBASE@/run/${help_name}.pid"

load_rc_config $name
run_rc_command "$1"
