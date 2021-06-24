#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fastd.sh,v 1.1 2021/06/24 14:01:31 nia Exp $
#
# PROVIDE: fastd 
# REQUIRE: DAEMON

. /etc/rc.subr

name="fastd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/fastd.conf"
pidfile="@VARBASE@/run/fastd/${name}.pid"
command="@PREFIX@/bin/fastd"
command_args="--daemon"
command_args="${command_args} --pid-file ${pidfile}"
command_args="${command_args} --config @PKG_SYSCONFDIR@/fastd.conf"

load_rc_config $name
run_rc_command "$1"
