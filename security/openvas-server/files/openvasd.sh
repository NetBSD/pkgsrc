#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openvasd.sh,v 1.1.1.1 2009/01/04 01:11:55 adrianp Exp $
#
# PROVIDE: openvasd
# REQUIRE: network
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="openvasd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-D -q"
pidfile="@VARBASE@/run/${name}.pid"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${openvasd_flags} ${command_args}
fi
