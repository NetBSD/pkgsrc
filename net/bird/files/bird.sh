#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: bird.sh,v 1.2 2025/05/18 02:10:50 markd Exp $
#
# PROVIDE: bird
# REQUIRE: network
# BEFORE: NETWORKING

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="bird"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
