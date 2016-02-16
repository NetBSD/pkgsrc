#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: haproxy.sh,v 1.3 2016/02/16 21:59:45 morr Exp $
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
haproxy_fdlimit=${haproxy_fdlimit-"1024"}

haproxy_configtest()
{
	if [ ! -f ${conf_file} ]; then
		warn "${conf_file} does not exist."
		return 1;
	fi
	${command} -c -f ${conf_file}
}

# A default limit of 64 (at least on NetBSD) may be too low for many people
SOFT_FDLIMIT=`ulimit -S -n`
HARD_FDLIMIT=`ulimit -H -n`

if [ ${haproxy_fdlimit} -gt ${SOFT_FDLIMIT} ]; then
  if [ ${haproxy_fdlimit} -le ${HARD_FDLIMIT} ]; then
    ulimit -S -n ${haproxy_fdlimit}
  else
    ulimit -S -n ${HARD_FDLIMIT}
  fi
fi

load_rc_config $name
run_rc_command "$1"
