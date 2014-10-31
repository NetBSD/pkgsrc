#!/bin/sh
#
# $NetBSD: opendnssec.sh,v 1.2 2014/10/31 16:32:39 he Exp $
#

# PROVIDE: opendnssec
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="opendnssec"
rcvar=$name

start_cmd=ods_start
stop_cmd=ods_stop
restart_cmd=ods_restart
status_cmd=ods_status
poll_cmd=ods_poll

enforcer_pidfile=/var/run/opendnssec/enforcerd.pid
signerd_pidfile=/var/run/opendnssec/signerd.pid

enforcer=/usr/pkg/sbin/ods-enforcerd
signer=/usr/pkg/sbin/ods-signerd

ods_control=/usr/pkg/sbin/ods-control

# Gain PID related commands
pidfile=$enforcer_pidfile
procname=$enforcer

ods_start () {

	rv=0
	if [ -f $enforcer_pidfile ]; then
		ep=$(check_pidfile $enforcer_pidfile $enforcer)

		if [ "$ep" != "" ]; then
			echo 1>&2 "$enforcer already running (pid=$ep)"
			rv=$(($rv + 1))
		fi
	fi

	if [ -f $signerd_pidfile ]; then
		sp=$(check_pidfile $signerd_pidfile $signer)
		if [ "$sp" != "" ]; then
			echo 1>&2 "$signer already running (pid=$sp)"
			rv=$(($rv + 1))
		fi
	fi
	if [ $rv != 0 ]; then
		exit $rv
	fi

	$ods_control start
}

ods_stop () {

	rv=0
	pids=""
	if [ -f $enforcer_pidfile ]; then
		ep=$(check_pidfile $enforcer_pidfile $enforcer)
		if [ "$ep" != "" ]; then
			pids="$pids $ep"
		else
			echo 1>&2 \
			    "$enforcer not running (check $enforcer_pidfile)"
			rv=$(($rv + 1))
		fi
	else
		echo 1>&2 "$enforcer not running (no $enforcer_pidfile file)"
		rv=$(($rv + 1))
	fi
	if [ -f $signerd_pidfile ]; then
		sp=$(check_pidfile $signerd_pidfile $signer)
		if [ "$sp" != "" ]; then
			pids="$pids $sp"
		else
			echo 1>&2 "$signer not running (check $signerd_pidfile)"
			rv=$(($rv + 1))
		fi
	else
		echo 1>&2 "$signer not running (no $signerd_pidfile file)"
		rv=$(($rv + 1))
	fi

# Ignore warnings, so that we can stop or restart if one component has crashed

	$ods_control stop

	wait_for_pids $pids
}

ods_restart () {

	ods_stop
	ods_start
}

ods_status () {

	ep=$(check_pidfile $enforcer_pidfile $enforcer)
	sp=$(check_pidfile $signerd_pidfile $signer)

	rv=0
	if [ "$ep" != "" ]; then
		echo "$enforcer running as PID $ep"
	else
		echo "$enforcer not running"
		rv=$(($rv + 1))
	fi
	if [ "$sp" != "" ]; then
		echo "$signer running as PID $sp"
	else
		echo "$signer not running"
		rv=$(($rv + 1))
	fi
	return $rv
}

ods_poll () {

	ep=$(check_pidfile $enforcer_pidfile $enforcer)
	sp=$(check_pidfile $signerd_pidfile $signer)

	if [ "$ep" != "" -o "$sp" != "" ]; then
		wait_for_pids $ep $sp
	fi
}

load_rc_config $name
run_rc_command "$1"
