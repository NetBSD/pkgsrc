#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ddclient.sh,v 1.5 2004/01/16 12:55:21 jlam Exp $
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
command="@PERL5_PATH@"
daemon="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="${daemon} @PKG_SYSCONFDIR@/${name}.conf"
start_cmd="ddclient_start"
extra_commands="reload"

ddclient_start()
{
	@ECHO@ "Starting ${name}."
	${daemon} ${ddclient_flags} ${command_args}
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${daemon} ${ddclient_flags} ${command_args}
fi
