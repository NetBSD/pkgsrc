#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: honeydarpd.sh,v 1.1.1.1 2004/04/20 09:15:52 xtraeme Exp $
#

# PROVIDE: honeydarpd
# REQUIRE: DAEMON
# BEFORE:  honeyd

. /etc/rc.subr

name="honeydarpd"
rcvar=$name
command="@PREFIX@/sbin/honeyd-arpd"
pidfile="/var/run/honeyd-arpd.pid"

load_rc_config $name
run_rc_command "$1"
