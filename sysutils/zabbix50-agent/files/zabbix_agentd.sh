#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zabbix_agentd.sh,v 1.1 2020/11/03 22:46:23 otis Exp $
#
# Zabbix agent daemon
#
# REQUIRE: DAEMON
# PROVIDE: zabbix_agentd

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="zabbix_agentd"
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
