#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fetchmail.sh,v 1.2 2004/08/01 04:54:56 jlam Exp $
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
extra_commands="reload"
command_args="-f - < @PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${fetchmail_flags} ${command_args}
fi
