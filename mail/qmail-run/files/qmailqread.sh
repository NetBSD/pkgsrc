#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailqread.sh,v 1.4 2004/12/29 16:18:41 schmonz Exp $
#
# @PKGNAME@ script to control a service providing local non-root
# users access to see the queue. Adapted from a script by Steinar Haug.
#

# PROVIDE: qmailqread mail
# REQUIRE: qmailsend

name="qmailqread"

# User-settable rc.conf variables and their default values:
: ${qmailqread_logcmd:="@LOCALBASE@/bin/setuidgid qmaill @LOCALBASE@/bin/splogger nb${name}"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
command="@LOCALBASE@/bin/tcpserver"
procname=${name}
start_precmd="qmailqread_precmd"

qmailqread_precmd()
{
	command="@SETENV@ - @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} -R -1 -u `@ID@ -u qmails` -g `@ID@ -g qmails` 127.0.0.1 20025 @LOCALBASE@/bin/qmail-qread 2>&1 | ${qmailqread_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailqread_precmd
	eval ${command} ${qmailqread_flags} ${command_args}
fi
