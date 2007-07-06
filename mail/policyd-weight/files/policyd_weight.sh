#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: policyd_weight.sh,v 1.1.1.1 2007/07/06 13:49:46 xtraeme Exp $
#

# PROVIDE: policyd_weight
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="policyd_weight"
rcvar=$name
pidfile="@VARBASE@/run/policyd-weight.pid"
command_interpreter="@PREFIX@/bin/perl"
command="@PREFIX@/sbin/policyd-weight"
extra_commands="reload"
required_files="@PKG_SYSCONFDIR@/policyd-weight.conf"

reload_cmd="policyd_weight_op"
restart_cmd="policyd_weight_op"
start_cmd="policyd_weight_op"
stop_cmd="policyd_weight_stop"

policyd_weight_op()
{
	${command} ${rc_arg}
}

policyd_weight_stop()
{
	${command} -k stop
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} start
fi
