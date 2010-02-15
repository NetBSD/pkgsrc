#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sj3proxy.sh,v 1.1 2010/02/15 13:35:22 obache Exp $
#
# PROVIDE: sj3proxy
# REQUIRE: sj3serv
# BEFORE: LOGIN
# KEYWORD: shutdown
#

. /etc/rc.subr

name="sj3proxy"
rcvar=$name
command="@PREFIX@/sbin/sj3proxy"

load_rc_config $name
run_rc_command "$1"
