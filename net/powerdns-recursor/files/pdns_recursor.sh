#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns_recursor.sh,v 1.3 2025/10/30 08:29:57 wiz Exp $
#

# PROVIDE: pdns_recursor
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns_recursor"
rcvar=$name
command="@PREFIX@/sbin/pdns_recursor"
command_args="--daemon=yes 2>/dev/null"
pidfile=/var/run/pdns-recursor/${name}.pid
required_files="@PKG_SYSCONFDIR@/recursor.yml"

load_rc_config $name
run_rc_command "$1"
