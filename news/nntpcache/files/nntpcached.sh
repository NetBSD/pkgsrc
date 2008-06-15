#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nntpcached.sh,v 1.1 2008/06/15 13:08:52 obache Exp $
#
# PROVIDE: nntpcached
# REQUIRE: NETWORKING SERVERS
# KEYWORD: shutdown

. /etc/rc.subr

name="nntpcached"
rcvar=${name}
command="@PREFIX@/sbin/${name}"

load_rc_config ${name}
run_rc_command "$1"
