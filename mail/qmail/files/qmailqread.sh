#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailqread.sh,v 1.1 2004/07/21 22:35:59 schmonz Exp $
#
# Script to control a service providing local non-root users access
# to see the queue. Adapted from a script by Steinar Haug.
#

# PROVIDE: qmailqread mail
# REQUIRE: qmailsend

. /etc/rc.subr

name="qmailqread"
rcvar=${name}
command="@LOCALBASE@/bin/tcpserver"
procname=${name}
start_precmd="qmailqread_precmd"

qmailqread_precmd()
{
	command="@SETENV@ - @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} -R -1 -u `@ID@ -u qmails` -g `@ID@ -g qmails` 127.0.0.1 20025 @PREFIX@/bin/qmail-qread 2>&1 | @PREFIX@/bin/splogger ${name}"
	command_args="&"
	rc_flags=""
}

load_rc_config $name
run_rc_command "$1"
