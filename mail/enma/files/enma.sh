#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: enma.sh,v 1.2 2009/04/09 02:25:37 obache Exp $
#
# PROVIDE: enma
# REQUIRE: NETWORK
#

. /etc/rc.subr

name="enma"
rcvar=${name}
command="@PREFIX@/libexec/enma"
pidfile="@VARBASE@/run/enma/${name}.pid"
required_files="@PKG_SYSCONFDIR@/enma.conf"
command_args="-c @PKG_SYSCONFDIR@/enma.conf"

load_rc_config ${name}
run_rc_command "$1"
