#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gmediaserver.sh,v 1.1.1.1 2010/05/20 04:27:33 obache Exp $
#
# PROVIDE: gmediaserver
# REQUIRE: DAEMON

. /etc/rc.subr

name="gmediaserver"
rcvar=${name}
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
command_args="-b --pid-file=${pidfile}"
exra_commands="reload"
sig_reload=-USER1

load_rc_config ${name}
run_rc_command "$1"
