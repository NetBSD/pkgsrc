#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zabbix_server.sh,v 1.1 2020/11/03 22:44:43 otis Exp $
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
start_precmd="ulimit -s 10240"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	[ "x$1" = "xstart" ] && ulimit -s 10240
	${command} ${command_args}
fi
