#!@RCD_SCRIPTS_SHELL@
#
#       $NetBSD: pure_ftpd.sh,v 1.1 2003/01/16 09:14:55 grant Exp $
#
# PROVIDE: pure-ftpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="pure_ftpd"
help_name="pure-ftpd"
rcvar=$name
command="@PREFIX@/sbin/${help_name}"
command_args="-B"
pidfile="/var/run/${help_name}.pid"

load_rc_config $name
run_rc_command "$1"
