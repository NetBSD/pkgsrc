#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fetchmail.sh,v 1.3 2011/03/20 01:38:36 shattered Exp $
#
# PROVIDE: fetchmail
# REQUIRE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="fetchmail"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="awaken reload"
command_args="-f - < @PKG_SYSCONFDIR@/${name}.conf"
awaken_cmd="start_poll"

start_poll () 
{
	DAEMON_PID=`sed 1q ${pidfile}`
	: ${DAEMON_PID:=0}
	@ECHO@ -n "Awakening ${name} daemon"
	if [ ${DAEMON_PID} -ne 0 ]; then
		kill -SIGUSR1 ${DAEMON_PID} >/dev/null 2>&1; 
	fi
	@ECHO@ '.'
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${fetchmail_flags} ${command_args}
fi
