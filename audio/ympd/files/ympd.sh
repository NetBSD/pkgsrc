#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ympd.sh,v 1.1 2021/07/20 06:37:18 nia Exp $
#
# PROVIDE: ympd
# REQUIRE: DAEMON

. /etc/rc.subr

name="ympd"
rcvar=${name}
pidfile="@VARBASE@/run/${name}.pid"
procname="@PREFIX@/bin/ympd"
command="@PREFIX@/sbin/daemonize"
command_args="${command_args} -p ${pidfile}"
command_args="${command_args} -o @VARBASE@/log/ympd/stdout.log"
command_args="${command_args} -e @VARBASE@/log/ympd/stderr.log"
command_args="${command_args} ${procname}"
command_args="${command_args} -u @YMPD_USER@"

load_rc_config $name
run_rc_command "$1"
