#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sserver.sh,v 1.1.1.1 2006/04/07 15:58:36 mjl Exp $
#

# PROVIDE: sserver
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="sserver"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="</dev/null >/dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
