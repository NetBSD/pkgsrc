#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: xend
# REQUIRE: xencommons

. /etc/rc.subr

name="xend"
rcvar=$name
command_interpreter="@RCD_INTERPRETER@"
start_precmd="xen_precmd"
start_cmd="xen_startcmd"
stop_cmd="xen_stop"
status_cmd="xen_status"
extra_commands="status"
required_files="/kern/xen/privcmd"

XENBACKENDD_PIDFILE="/var/run/xenbackendd.pid"
XEND_PIDFILE="/var/run/xend.pid"

SBINDIR=@PREFIX@/sbin

xen_precmd()
{
	mkdir -p /var/run/xend/boot || exit 1
}

xen_startcmd()
{
	printf "Starting xendservices: xenbackendd, xend.\n"
	XENBACKENDD_ARGS=""
	if [ -n "${XENBACKENDD_DEBUG}" ]; then
		XENBACKENDD_ARGS="${XENBACKENDD_ARGS} -d"
	fi

	${SBINDIR}/xenbackendd ${XENBACKENDD_ARGS}

	XEND_ARGS=""
	if [ -n "${XEND_DEBUG}" ]; then
		XEND_ARGS="${XEND_ARGS} trace_start"
	else
		XEND_ARGS="${XEND_ARGS} start"
	fi

	${SBINDIR}/xend ${XEND_ARGS}
}

xen_stop()
{
	pids=""
	printf "Stopping xendservices"

	${SBINDIR}/xend stop

	rc_pid=$(check_pidfile ${XENBACKENDD_PIDFILE} ${SBINDIR}/xenbackendd)
	pids="$pids $rc_pid"

	kill -${sig_stop:-TERM} $pids
	wait_for_pids $pids

	printf ".\n"
}

xen_status()
{
	xenbackendd_pid=$(check_pidfile ${XENBACKENDD_PIDFILE} ${SBINDIR}/xenbackendd)
	if test -n ${xenbackend_pid}; then
		pids="$pids $xenbackend_pid"
	fi

	xend_pid=$(check_pidfile ${XEND_PIDFILE} ${SBINDIR}/xend)
	if test -n ${xend_pid}; then
		pids="$pids $xenbackend_pid"
	fi

	if test -n "$xend_pid" -a -n "$xenbackendd_pid";
	then
		echo "xends are running as pids $pids."
		return 0
	fi
	if test -z "$xend_pid" -a -z "$xenbackendd_pid";
	then
		echo "xends are not running."
		return 0
	fi

	if test -n "$xenbackend_pid"; then
		echo "xenbackendd is running as pid $xenbackend_pid."
	else
		echo "xenbackendd is not running."
	fi

	if test -n "$xend_pid"; then
		echo "xend is running as pid $xend_pid."
	else
		echo "xend is not running."
	fi
}

load_rc_config $name
run_rc_command "$1"
