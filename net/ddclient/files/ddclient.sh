#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ddclient.sh,v 1.7 2019/01/06 16:52:17 schmonz Exp $
#
# Dynamic DNS update client
#
# PROVIDE: ddclient
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="ddclient"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	${command} ${ddclient_flags} ${command_args}
fi
