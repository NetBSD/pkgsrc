#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nsd.sh,v 1.3 2008/04/24 09:38:30 joerg Exp $
#
# PROVIDE: nsd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="nsd"
rcvar=${name}

command=@PREFIX@/sbin/${name}
pidfile=/var/run/${name}.pid

nsd_flags=${nsd_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
