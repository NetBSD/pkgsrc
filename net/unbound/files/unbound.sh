#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unbound.sh,v 1.1.1.1 2008/05/26 22:36:56 joerg Exp $
#
# PROVIDE: unbound
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="unbound"
rcvar=${name}

command=@PREFIX@/sbin/${name}
pidfile=/var/run/${name}.pid

load_rc_config ${name}
run_rc_command "$1"
