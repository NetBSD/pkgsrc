#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailsmtpd.sh,v 1.2 2004/04/24 05:29:36 schmonz Exp $
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
	command="@SETENV@ - @LOCALBASE_NORMAL@/bin/argv0 @LOCALBASE_NORMAL@/bin/tcpserver $name $qmailsmtpd_flags -u `@ID@ -u qmaild` -g `@ID@ -g qmaild` 0 25 @QMAILDIR@/bin/qmail-smtpd 2>&1 | @QMAILDIR@/bin/splogger smtpd 3"
	command_args="&"
	rc_flags=""
}

load_rc_config $name
run_rc_command "$1"
