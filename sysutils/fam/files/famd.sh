#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: famd.sh,v 1.1 2004/10/17 19:20:53 jmmv Exp $
#
# PROVIDE: famd
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="famd"
rcvar=$name
command="@PREFIX@/sbin/famd"
command_args="-T 0 -L &"

load_rc_config $name
run_rc_command "$1"
