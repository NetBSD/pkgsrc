#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: clamsmtpd.sh,v 1.3 2004/08/04 06:50:16 jlam Exp $
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
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile=/var/run/clamsmtpd.pid
: ${clamsmtpd_addr="localhost:10026"}

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
	: ${clamsmtpd_flags="-c ${socket}"}
else
	: ${clamsmtpd_user="@CLAMAV_USER@"}
fi

clamsmtpd_prestart()
{
	@TOUCH@ ${pidfile}
	@CHOWN@ ${clamsmtpd_user} ${pidfile}
}

clamsmtpd_start()
{
	@ECHO@ "Starting ${name}."
	doit="${command} ${clamsmtpd_flags} -p ${pidfile} ${clamsmtpd_addr}"
	@SU@ -m ${clamsmtpd_user} -c "$doit"
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	eval ${start_cmd}
fi
