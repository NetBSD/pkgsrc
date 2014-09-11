#!@RCD_SCRIPTS_SHELL@
# $NetBSD: munge.sh,v 1.1 2014/09/11 16:11:46 asau Exp $
#
# PROVIDE: munge
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="munge"
rcvar=${name}
command="@PREFIX@/sbin/munged"

load_rc_config $name
run_rc_command "$1"
