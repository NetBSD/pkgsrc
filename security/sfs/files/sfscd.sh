#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sfscd.sh,v 1.1 2003/03/25 15:51:51 grant Exp $
#
# start script for SFS client daemon 

# PROVIDE: sfscd
# REQUIRE: NETWORK

. /etc/rc.subr

name="sfscd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
