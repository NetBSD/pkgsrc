#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: enma.sh,v 1.1.1.1 2008/09/05 07:23:44 obache Exp $
#
# PROVIDE: enma
# REQUIRE: NETWORK
#

. /etc/rc.subr

name="enma"
rcvar=${name}
command="@PREFIX@/bin/enma"
pidfile="@VARBASE@/run/enma/${name}.pid"
required_files="@PKG_SYSCONFDIR@/enma.conf"
command_args="-c @PKG_SYSCONFDIR@/enma.conf"

load_rc_config ${name}
run_rc_command "$1"
