#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rplayd.sh,v 1.6 2002/09/20 02:01:54 grant Exp $
#
# PROVIDE: rplayd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="rplayd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/rplay.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${rplayd_flags} ${command_args}
fi
