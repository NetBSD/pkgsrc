#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: clamsmtpd.sh,v 1.5.12.1 2007/05/31 14:22:21 salo Exp $
#
# PROVIDE: clamsmtpd
# REQUIRE: LOGIN clamd
# BEFORE: mail
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start clamsmtpd:
#
# clamsmtpd=YES
#
# The following variables are optional:
#
#       clamsmtpd_user="@CLAMAV_USER@"	    # user to run clamsmtpd as
#       clamsmtpd_addr="localhost:10026"    # address to forward mail to;
#					    # see clamsmtpd(8).
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="clamsmtpd"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/clamsmtpd.pid"

start_precmd="clamsmtpd_prestart"
start_cmd="clamsmtpd_start"

clamav_conffile="@PKG_SYSCONFDIR@/clamav.conf"
if [ -f "${clamav_conffile}" ]; then
	socket=`@AWK@ 'BEGIN {r = "/tmp/clamd"};
			/^#/ {next}; /^LocalSocket[ 	]/ {r = $2};
			END {print r}' ${clamav_conffile}`
	: ${clamsmtpd_user=`@AWK@ 'BEGIN {r = "@CLAMAV_USER@"};
			/^#/ {next}; /^User[ 	]/ {r = $2};
			END {print r}' ${clamav_conffile}`}
else
	: ${socket="/tmp/clamd"}
	: ${clamsmtpd_user="@CLAMAV_USER@"}
fi

clamsmtpd_prestart()
{
	if [ ! -S "${socket}" ]; then
		# Max wait time is 2 minutes
		retries=11

		@ECHO@ -n "Waiting for clamd to become ready"
		while [ ${retries} -gt 0 -a ! -S "${socket}" ]; do
			@ECHO@ -n "."
			sleep 10
			retries=$((retries - 1))
		done
		if [ ! -S "${socket}" ]; then
			@ECHO@ ""
			@ECHO@ "ERROR: Unable to start clamsmtpd as clamd is not running!"
			exit 1
		fi

		# Wait another 10 seconds so that clamd is really ready
		@ECHO@ -n "."
		sleep 10
		@ECHO@ ""
	fi
	@TOUCH@ ${pidfile}
	@CHOWN@ ${clamsmtpd_user} ${pidfile}
}

clamsmtpd_start()
{
	@ECHO@ "Starting ${name}."
	doit="${command} ${clamsmtpd_flags} -p ${pidfile}"
	@SU@ -m ${clamsmtpd_user} -c "${doit}"
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	eval ${start_cmd}
fi
