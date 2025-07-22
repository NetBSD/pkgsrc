#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ddclient.sh,v 1.9 2025/07/22 22:43:32 abs Exp $
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
command="@PREFIX@/bin/${name}"
procname="perl"
required_files="@PKG_SYSCONFDIR@/${name}/${name}.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	${command} ${ddclient_flags} ${command_args}
fi
