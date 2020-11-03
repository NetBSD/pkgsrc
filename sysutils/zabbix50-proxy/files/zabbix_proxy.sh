#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zabbix_proxy.sh,v 1.1 2020/11/03 22:45:38 otis Exp $
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
start_precmd="ulimit -s 10240"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	[ "x$1" = "xstart" ] && ulimit -s 10240
	${command} ${command_args}
fi
