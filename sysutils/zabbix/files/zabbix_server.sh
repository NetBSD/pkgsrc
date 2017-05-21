#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zabbix_server.sh,v 1.1 2017/05/21 17:30:03 adam Exp $
#
# Zabbix server daemon
#
# REQUIRE: DAEMON
# PROVIDE: zabbix_server

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="zabbix_server"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
