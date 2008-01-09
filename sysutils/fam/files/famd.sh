#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: famd.sh,v 1.2 2008/01/09 21:17:32 wiz Exp $
#
# PROVIDE: famd
# REQUIRE: DAEMON rpcbind
# KEYWORD: shutdown

. /etc/rc.subr

name="famd"
rcvar=$name
command="@PREFIX@/sbin/famd"
command_args="-T 0 -L &"

load_rc_config $name
run_rc_command "$1"
