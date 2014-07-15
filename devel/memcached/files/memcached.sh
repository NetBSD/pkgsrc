#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: memcached.sh,v 1.3 2014/07/15 17:30:26 fhajny Exp $
#

# PROVIDE: memcached
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="memcached"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-d"
start_cmd="memcached_start"
stop_cmd="memcached_stop"
status_cmd="memcached_status"
pidfile_base="@MEMCACHED_HOME@/memcached-"

memcached_pid()
{
	pidfile="${pidfile_base}$1.pid"
	rc_pid=`check_pidfile "$pidfile" $command`
}

memcached_start()
{
	rv=0
	for job in "" $memcached_jobs; do
		[ -z $job ] && continue
		memcached_pid $job
		if [ -n "${rc_pid}" ]; then
			echo "${name}/$job already running (pid=${rc_pid})."
			rv=1
			continue
		fi
		job_args=$(eval echo \$${name}_${job}_args)

		echo "Starting ${name}/$job."
		$command \
			-u @MEMCACHED_USER@ \
			$command_args \
			${job_args} \
			-P "${pidfile_base}${job}.pid"
	done
	return $rv
}

memcached_stop()
{
	rv=0
	for job in "" $memcached_jobs; do
		[ -z $job ] && continue
		memcached_pid $job
		if [ -n "${rc_pid}" ]; then
			echo "Stopping ${name}/$job."
			kill -TERM ${rc_pid}
			wait_for_pids ${rc_pid}
		else
			echo "${name}/$job is not running."
			rv=1
		fi
	done
	return $rv
}

memcached_status()
{
	rv=0
	for job in "" $memcached_jobs; do
		[ -z $job ] && continue
		memcached_pid $job
		if [ -n "${rc_pid}" ]; then
			echo "${name}/${job} is running as pid ${rc_pid}."
		else
			echo "${name}/${job} is not running."
			rv=1
		fi
	done
	return $rv
}

load_rc_config $name
run_rc_command "$1"
