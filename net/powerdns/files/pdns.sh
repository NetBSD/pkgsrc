#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns.sh,v 1.2 2020/09/24 19:09:53 otis Exp $
#

# PROVIDE: pdns
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns"
rcvar=$name
command="@PREFIX@/sbin/pdns_server"
command_args="--daemon=yes"
pidfile=/var/run/${name}/${name}.pid
required_files="@PKG_SYSCONFDIR@/pdns.conf"

load_rc_config $name
run_rc_command "$1"
