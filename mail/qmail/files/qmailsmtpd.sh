#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailsmtpd.sh,v 1.3 2004/04/27 03:05:09 schmonz Exp $
#

# PROVIDE: mail
# REQUIRE: qmail

. /etc/rc.subr

name="qmailsmtpd"
rcvar=${name}
required_files="@QMAILDIR@/control/rcpthosts"
command="@LOCALBASE_NORMAL@/bin/tcpserver"
procname=${name}
start_precmd="qmailsmtpd_precmd"

if [ -z "$qmailsmtpd_flags" ]; then
	qmailsmtpd_flags="-v -H -R -l 0"
fi

qmailsmtpd_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for SMTP
	# service. Use argv0(1) to set procname to "qmailsmtpd".
	command="@SETENV@ - @LOCALBASE_NORMAL@/bin/argv0 @LOCALBASE_NORMAL@/bin/tcpserver $name $qmailsmtpd_flags -u `@ID@ -u qmaild` -g `@ID@ -g qmaild` 0 25 @QMAILDIR@/bin/qmail-smtpd 2>&1 | @QMAILDIR@/bin/splogger smtpd 3"
	command_args="&"
	rc_flags=""
}

load_rc_config $name
run_rc_command "$1"
