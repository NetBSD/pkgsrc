#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: iplog.sh,v 1.1 2003/07/30 15:41:54 jmmv Exp $
#
# PROVIDE: iplog
# REQUIRE: SERVERS

. /etc/rc.subr

name="iplog"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config ${name}	
run_rc_command "$1"
