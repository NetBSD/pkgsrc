#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sj3serv.sh,v 1.1 2010/02/15 13:35:22 obache Exp $
#
# PROVIDE: sj3serv
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown
#

. /etc/rc.subr

name="sj3serv"
rcvar=$name
command="@PREFIX@/sbin/sj3serv"

load_rc_config $name
run_rc_command "$1"
