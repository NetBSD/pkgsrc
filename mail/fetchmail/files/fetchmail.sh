#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fetchmail.sh,v 1.1 2003/09/11 22:58:06 jlam Exp $
#
# PROVIDE: fetchmail
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="fetchmail"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"
command_args="-f - < @PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${fetchmail_flags} ${command_args}
fi
