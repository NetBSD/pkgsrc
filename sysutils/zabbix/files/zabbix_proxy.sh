#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zabbix_proxy.sh,v 1.1 2017/05/21 17:30:03 adam Exp $
#
# Zabbix proxy daemon
#
# REQUIRE: DAEMON
# PROVIDE: zabbix_proxy

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="zabbix_proxy"
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
