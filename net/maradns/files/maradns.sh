#!@RCS_SCRIPTS_SHELL@
#
# $NetBSD: maradns.sh,v 1.1.1.1 2003/09/25 14:12:51 xtraeme Exp $
#

# PROVIDE: maradns
# REQUIRE: DAEMON

. /etc/rc.subr

name="maradns"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/mararc"

load_rc_config $name
run_rc_command "$1"
