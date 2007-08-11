#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nsd.sh,v 1.2 2007/08/11 23:48:40 joerg Exp $
#
# PROVIDE: nsd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="nsd"
rcvar=${name}

command=/usr/pkg/sbin/${name}
pidfile=/var/run/${name}.pid

nsd_flags=${nsd_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
