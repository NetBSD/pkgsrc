#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: xencommons
# REQUIRE: DAEMON

. /etc/rc.subr

name="xencommons"
rcvar=$name
start_precmd="xen_precmd"
start_cmd="xen_startcmd"
stop_cmd="xen_stop"
status_cmd="xen_status"
extra_commands="status"
required_files="/kern/xen/privcmd"

XENSTORED_PIDFILE="/var/run/xenstored.pid"
XENCONSOLED_PIDFILE="/var/run/xenconsoled.pid"

BINDIR=@PREFIX@/bin
SBINDIR=@PREFIX@/sbin

xen_precmd()
{
	mkdir -p /var/run/xen || exit 1
	mkdir -p /var/run/xenstored || exit 1
}

xen_startcmd()
{
	printf "Starting xenservices: xenstored, xenconsoled.\n"
	if test ! -r ${required_files}; then
		warn "${required_files} is not readable."
	fi
	XENSTORED_ARGS=" --pid-file ${XENSTORED_PIDFILE}"
	if [ -n "${XENSTORED_TRACE}" ]; then
		XENSTORED_ARGS="${XENSTORED_ARGS} -T /var/log/xen/xenstored-trace.log"
	fi

	${SBINDIR}/xenstored ${XENSTORED_ARGS}
	sleep 5

	printf "Setting domain 0 name and domid...\n"
	${BINDIR}/xenstore-write "/local/domain/0/name" "Domain-0" \
				"domid" 0

	XENCONSOLED_ARGS=""
	if [ -n "${XENCONSOLED_TRACE}" ]; then
		XENCONSOLED_ARGS="${XENCONSOLED_ARGS} --log=${XENCONSOLED_TRACE}"
	fi

	${SBINDIR}/xenconsoled ${XENCONSOLED_ARGS}
}

xen_stop()
{
	pids=""
	printf "Stopping xencommons"

	rc_pid=$(check_pidfile ${XENCONSOLED_PIDFILE} ${SBINDIR}/xenconsoled)
	pids="$pids $rc_pid"
	rc_pid=$(check_pidfile ${XENSTORED_PIDFILE} ${SBINDIR}/xenstored)
	pids="$pids $rc_pid"

	kill -${sig_stop:-TERM} $pids
	wait_for_pids $pids

	printf ".\n"
}

xen_status()
{
	xenstored_pid=$(check_pidfile ${XENSTORED_PIDFILE} ${SBINDIR}/xenstored)
	if test -n ${xenstored_pid}; then
		pids="$pids $xenstored_pid"
	fi

	xenconsoled_pid=$(check_pidfile ${XENCONSOLED_PIDFILE} ${SBINDIR}/xenconsoled)
	if test -n ${xenconsoled_pid}; then
		pids="$pids $xenconsoled_pid"
	fi

	if test -n "$xenconsoled_pid" -a -n "$xenstored_pid";
	then
		echo "xencommons are running as pids $pids."
		return 0
	fi
	if test -a -z "$xenconsoled_pid" -a -z "$xenstored_pid";
	then
		echo "xencommons are not running."
		return 0
	fi

	if test -n "$xenstored_pid"; then
		echo "xenstored is running as pid $xenstored_pid."
	else
		echo "xenstored is not running."
	fi
	if test -n "$xenconsoled_pid"; then
		echo "xenconsoled is running as pid $xenconsoled_pid."
	else
		echo "xenconsoled is not running."
	fi
}

load_rc_config $name
run_rc_command "$1"
