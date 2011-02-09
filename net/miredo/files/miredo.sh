#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: miredo.sh,v 1.1 2011/02/09 22:59:50 pettai Exp $

# PROVIDE: miredo
# REQUIRE: NETWORKING

. /etc/rc.subr

name="miredo"
rcvar=$name
command="/usr/pkg/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"

