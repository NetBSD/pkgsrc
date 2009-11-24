#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unbound.sh,v 1.2 2009/11/24 01:08:06 roy Exp $
#
# PROVIDE: unbound
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="unbound"
rcvar=${name}

command=@PREFIX@/sbin/${name}
pidfile=/var/run/${name}.pid
extra_commands="reload"

load_rc_config ${name}
run_rc_command "$1"
