#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: bird6.sh,v 1.1.1.1 2012/01/22 02:53:01 agc Exp $
#
# PROVIDE: bird6
# REQUIRE: DAEMON NETWORKING

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="bird6"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
