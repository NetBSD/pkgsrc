#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radmind.sh,v 1.1.1.1 2004/12/28 14:04:39 wiz Exp $

# PROVIDE: radmind
# REQUIRE: DAEMON

. /etc/rc.subr

name="radmind"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
