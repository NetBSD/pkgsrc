#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: clamd.sh,v 1.1.1.1 2010/12/24 07:11:05 kefren Exp $
#
# clamd does anti-virus checking.
#
# PROVIDE: clamd
# REQUIRE: DAEMON
# BEFORE: mail local
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="clamd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
scan_command="@PREFIX@/bin/clamdscan"
required_files="@PKG_SYSCONFDIR@/clamd.conf"
start_precmd="clamd_precmd"
stop_cmd="clamd_stopcmd"

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
	clamd_user=`@AWK@ 'BEGIN {r = "@CLAMAV_USER@"};
			/^#/ {next}; /^User[ 	]/ {r = $2};
			END {print r}' ${required_files}`
fi

clamd_precmd()
{
	@RM@ -f ${socket}
	if [ -n "${logfile}" ]; then
    		@TOUCH@ ${logfile}
    		@CHOWN@ ${clamd_user} ${logfile}
	fi
	if [ -n "${pidfile}" ]; then
    		@TOUCH@ ${pidfile}
    		@CHOWN@ ${clamd_user} ${pidfile}
	fi
}

clamd_stopcmd()
{
	# Workaround bug when clamd is built against pth by send TERM to
	# clamd, then forcing it to start a worker thread that exits.
	# This forces the main thread to awaken and realize that it's
	# supposed to shutdown.
	#
        @ECHO@ "Stopping ${name}."
        doit="@SU@ -m ${clamd_user} -c \"kill -TERM $rc_pid\""
        if ! eval $doit && [ -z "$rc_force" ]; then
                return 1
        fi
        ${scan_command} --quiet ${scan_command} 2>/dev/null
        wait_for_pids $rc_pid
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	${command} ${clamd_flags} ${command_args}
fi
