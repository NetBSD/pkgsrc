#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sslh.sh,v 1.1 2013/11/08 13:33:55 obache Exp $
#
# PROVIDE: sslh
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="sslh"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
command_args="-P ${pidfile}"

if [ -f @PKG_SYSCONFDIR@/sslh.cfg ]; then
	command_args="${command_args} -F @PKG_SYSCONFDIR@/sslh.cfg"
fi

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${command_args}
fi
