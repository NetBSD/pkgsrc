#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: haproxy.sh,v 1.2 2014/04/27 01:28:01 rodent Exp $
#

# PROVIDE: haproxy
# REQUIRE: network

$_rc_subr_loaded . /etc/rc.subr

name="haproxy"
rcvar=$name
command="@PREFIX@/sbin/${name}"
conf_file="@PKG_SYSCONFDIR@/${name}.cfg"
required_files="${conf_file}"
command_args="-f ${conf_file}"
extra_commands="configtest"
configtest_cmd="haproxy_configtest"

haproxy_configtest()
{
	if [ ! -f ${conf_file} ]; then
		warn "${conf_file} does not exist."
		return 1;
	fi
	${command} -c -f ${conf_file}
}

load_rc_config $name
run_rc_command "$1"
