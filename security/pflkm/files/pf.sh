#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pf.sh,v 1.1.1.1 2004/11/05 15:05:30 peter Exp $
#
# PROVIDE: pf
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pf"
rcvar=$name
pfctl="@PREFIX@/sbin/pfctl"
config="@PKG_SYSCONFDIR@/pf.conf"
start_cmd="pf_start"
stop_cmd="pf_stop"
reload_cmd="pf_reload"
status_cmd="pf_status"
extra_commands="reload status"

pf_start()
{
	echo "Enabling pf firewall."
	${pfctl} -q -e 
	if [ -f ${config} ]; then
		${pfctl} -q -f ${config}
	else
		warn "pf.conf not found; no pf rules loaded."
	fi
}

pf_stop()
{
	echo "Disabling pf firewall."
	${pfctl} -q -d
}

pf_reload()
{
	echo "Reloading pf rules."
	if [ -f ${config} ]; then
		${pfctl} -q -f ${config}
	else
		warn "pf.conf not found; no pf rules loaded."
	fi
}

pf_status()
{
	${pfctl} -s info
}

load_rc_config $name
run_rc_command "$1"
