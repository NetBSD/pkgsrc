#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: swapd.sh,v 1.1.1.1 2004/10/30 05:06:15 xtraeme Exp $
#
# PROVIDE: swapd
# REQUIRE: DAEMON LOGIN swap


name="swapd"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"
sig_stop="KILL"

. /etc/rc.subr

load_rc_config $name
run_rc_command "$1"

if [ "$1" != "stop" ]; then
	echo $(check_process $command) > $pidfile
fi
