#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: clamsmtpd.sh,v 1.2 2004/08/03 08:24:56 jlam Exp $
#
# PROVIDE: clamsmtpd
# REQUIRE: LOGIN clamd
# BEFORE: mail
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="clamsmtpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
clamsmtpd_user="@CLAMAV_USER@"

clamav_conffile="@PKG_SYSCONFDIR@/clamav.conf"
if [ -f "${clamav_conffile}" ]; then
	socket=`@AWK@ 'BEGIN {r = "/tmp/clamd"};
			/^#/ {next}; /^LocalSocket[ 	]/ {r = $2};
			END {print r}' ${clamav_conffile}`
	clamsmtpd_user=`@AWK@ 'BEGIN {r = "@CLAMAV_USER@"};
			/^#/ {next}; /^User[ 	]/ {r = $2};
			END {print r}' ${clamav_conffile}`
	: ${clamsmtpd_flags="-c ${socket} localhost:10026"}
else
	: ${clamsmtpd_flags="localhost:10026"}
fi

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${clamsmtpd_flags} ${command_args}
fi
