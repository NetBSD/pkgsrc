#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: freshclamd.sh,v 1.2 2004/11/02 00:55:20 xtraeme Exp $
#
# PROVIDE: freshclamd
# REQUIRE: DAEMON LOGIN clamd


name="freshclamd"
command="@PREFIX@/bin/freshclam"
required_files="@PKG_SYSCONFDIR@/freshclam.conf"
pidfile="@VARBASE@/run/${name}.pid"
sig_stop="KILL"
freshclamd_user="@CLAMAV_USER@"
freshclamd_flags=${freshclamd_flags:=-c 2}
command_args="-d"

. /etc/rc.subr

load_rc_config $name
run_rc_command "$1"

if [ "$1" != "stop" ]; then
	echo $(check_process $command) > $pidfile
fi
