#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: canna.sh,v 1.1 2003/07/29 19:42:53 jmmv Exp $
#
# PROVIDE: canna
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="canna"
rcvar=$name
command="@PREFIX@/sbin/cannaserver"
stop_cmd="@PREFIX@/sbin/cannakill"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${canna_flags} ${command_args}
fi
