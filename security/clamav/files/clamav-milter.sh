#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: clamav-milter.sh,v 1.1 2020/09/14 16:54:35 taca Exp $
#
# clamav-milter provides milter socket for mail daemon
#
# PROVIDE: clamav_milter
# REQUIRE: clamd
# BEFORE: mail local
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="clamav_milter"
rcvar=$name
command="@PREFIX@/sbin/clamav-milter"
required_files="@PKG_SYSCONFDIR@/clamav-milter.conf"
start_precmd="clamd_precmd"
stop_cmd="clamav_milter_stopcmd"

if [ -f "${required_files}" ]; then
	pidfile_=`@AWK@ '/^#/ {next}; /^PidFile[ 	]/ {r = $2};
			END {print r}' ${required_files}`
	if [ -n "${pidfile_}" ]; then
		pidfile=${pidfile_}
	fi
	logfile=`@AWK@ 'BEGIN {r = "/tmp/clamd.log"};
			/^#/ {next}; /^LogFile[ 	]/ {r = $2};
			END {print r}' ${required_files}`
	socket=`@AWK@ 'BEGIN {r = "/tmp/clamd"};
			/^#/ {next}; /^LocalSocket[ 	]/ {r = $2};
			END {print r}' ${required_files}`
	clamav_milter_user=`@AWK@ 'BEGIN {r = "@CLAMAV_USER@"};
			/^#/ {next}; /^User[ 	]/ {r = $2};
			END {print r}' ${required_files}`
fi

clamav_milter_precmd()
{
	@RM@ -f ${socket}
	if [ -n "${logfile}" ]; then
		@TOUCH@ ${logfile}
		@CHOWN@ ${clamav_milter_user} ${logfile}
	fi
	if [ -n "${pidfile}" ]; then
		@TOUCH@ ${pidfile}
		@CHOWN@ ${clamav_milter_user} ${pidfile}
	fi
}

clamav_milter_stopcmd()
{
	# Workaround bug when clamd is built against pth by send TERM to
	# clamd, then forcing it to start a worker thread that exits.
	# This forces the main thread to awaken and realize that it's
	# supposed to shutdown.
	#
	@ECHO@ "Stopping ${name}."
	doit="@SU@ -m ${clamav_milter_user} -c \"kill -TERM $rc_pid\""
	if ! eval $doit && [ -z "$rc_force" ]; then
		return 1
	fi
	wait_for_pids $rc_pid
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	${command} ${clamav_milter_flags} ${command_args}
fi
