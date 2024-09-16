#!/bin/sh
#
# $NetBSD: soju.sh,v 1.1 2024/09/16 12:55:51 wiz Exp $
#
# PROVIDE: soju
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="soju"
rcvar=${name}
pidfile="@VARBASE@/run/${name}.pid"
procname="@PREFIX@/bin/soju"
command="@PREFIX@/sbin/daemonize"
command_args="${command_args} -a"
command_args="${command_args} -o @VARBASE@/log/soju/stdout.log"
command_args="${command_args} -e @VARBASE@/log/soju/stderr.log"
command_args="${command_args} -p ${pidfile}"
command_args="${command_args} -u @SOJU_USER@"
command_args="${command_args} ${procname}"
required_files="@PKG_SYSCONFBASE@/soju/config"
extra_commands="reload"
start_precmd=soju_prestart

soju_prestart() {
	dir="@VARBASE@/run/soju"
	if test ! -d $dir; then
		/bin/mkdir -p $dir
		/bin/chmod 0700 $dir
		/usr/sbin/chown soju:soju $dir
	fi
}

load_rc_config $name
run_rc_command "$1"
