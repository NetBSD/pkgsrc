#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: freshclamd.sh,v 1.1.1.1 2010/12/24 07:11:05 kefren Exp $
#
# PROVIDE: freshclamd
# REQUIRE: DAEMON LOGIN clamd

name="freshclamd"
rcvar=$name
command="@PREFIX@/bin/freshclam"
required_files="@PKG_SYSCONFDIR@/freshclam.conf"
pidfile="@CLAMAV_DBDIR@/${name}.pid"
freshclamd_user="@CLAMAV_USER@"
freshclamd_flags=${freshclamd_flags:=-c 2}
command_args="-d -p $pidfile"

. /etc/rc.subr

load_rc_config $name
run_rc_command "$1"
