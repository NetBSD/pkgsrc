#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qpopper.sh,v 1.3 2004/12/19 01:33:36 grant Exp $
#

# PROVIDE: qpopper
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name=qpopper
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
