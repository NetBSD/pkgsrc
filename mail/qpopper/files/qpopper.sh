#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qpopper.sh,v 1.2 2004/12/18 03:54:54 grant Exp $
#

# PROVIDE: qpopper
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name=qpopper
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
