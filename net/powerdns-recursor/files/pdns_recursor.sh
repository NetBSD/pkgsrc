#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns_recursor.sh,v 1.1.1.1 2009/04/21 14:16:47 roy Exp $
#

# PROVIDE: pdns_recursor
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns_recursor"
rcvar=$name
command="@PREFIX@/sbin/pdns_recursor"
command_args="--daemon=yes 2>/dev/null"
pidfile=/var/run/${name}.pid
required_files="@PKG_SYSCONFDIR@/recursor.conf"

load_rc_config $name
run_rc_command "$1"
