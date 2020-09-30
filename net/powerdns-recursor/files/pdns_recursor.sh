#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns_recursor.sh,v 1.2 2020/09/30 11:53:07 otis Exp $
#

# PROVIDE: pdns_recursor
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns_recursor"
rcvar=$name
command="@PREFIX@/sbin/pdns_recursor"
command_args="--daemon=yes 2>/dev/null"
pidfile=/var/run/pdns-recursor/${name}.pid
required_files="@PKG_SYSCONFDIR@/recursor.conf"

load_rc_config $name
run_rc_command "$1"
