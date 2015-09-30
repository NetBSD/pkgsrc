#!/bin/sh
#

# PROVIDE: syncffsd
# REQUIRE: LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="syncffsd"
rcvar=$name
pidfile="@VARBASE@/run/syncffsd/${name}.pid"
command="@PREFIX@/sbin/syncffsd"

start_precmd=syncffsd_precmd
start_cmd=syncffsd_start

syncffsd_precmd() {
	local userflag

	if [ "x${syncffsd_user}" != "x" ] ; then
		userflag="-o ${syncffsd_user}"
	fi

	install -d -m 755 ${userflag} `dirname ${pidfile}`
}
syncffsd_start() {
	local userflag

	if [ -n "$rc_pid" ]; then
		echo 1>&2 "${name} already running? (pid=$rc_pid)."
		exit 1
	fi

	if [ "x${syncffsd_src}" = "x" ] ; then
		echo 1>&2 "syncffsd_src is not defined in rc.conf"
		exit 1
	fi

	if [ "x${syncffsd_dst}" = "x" ] ; then
		echo 1>&2 "syncffsd_dst is not defined in rc.conf"
		exit 1
	fi

	if [ "x${syncffsd_user}" != "x" ] ; then
		userflag="-u ${syncffsd_user}"
	fi

	echo "Starting ${name}."
	${command} -p ${pidfile} ${userflag} ${syncffsd_src} ${syncffsd_dst}
}

load_rc_config $name
run_rc_command "$1"
