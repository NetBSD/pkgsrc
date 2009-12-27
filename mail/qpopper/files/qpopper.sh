#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qpopper.sh,v 1.4 2009/12/27 14:17:38 obache Exp $
#

# PROVIDE: qpopper
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name=qpopper
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
