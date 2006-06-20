#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: freshclamd.sh,v 1.3 2006/06/20 20:24:45 jnemeth Exp $
#
# PROVIDE: freshclamd
# REQUIRE: DAEMON LOGIN clamd


name="freshclamd"
rcvar=$name
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
