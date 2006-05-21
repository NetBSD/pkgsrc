#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nrpe.sh,v 1.1.1.1 2006/05/21 10:28:40 grant Exp $
#
# PROVIDE: nrpe
# REQUIRE: DAEMON

. /etc/rc.subr

name="nrpe"
rcvar=$name
command="@PREFIX@/sbin/${name}"
config="@PKG_SYSCONFDIR@/${name}.cfg"
pidfile="/var/run/${name}.pid"

command_args="-c $config -d"

load_rc_config $name
run_rc_command "$1"
