#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailqread.sh,v 1.13 2017/08/05 03:03:17 schmonz Exp $
#
# @PKGNAME@ script to control a service providing local non-root
# users access to see the queue. Adapted from a script by Steinar Haug.
#

# PROVIDE: qmailqread mail
# REQUIRE: qmailsend

name="qmailqread"

# User-settable rc.conf variables and their default values:
: ${qmailqread_postenv:=""}
: ${qmailqread_tcpflags:="-R1"}
: ${qmailqread_tcphost:="127.0.0.1"}
: ${qmailqread_tcpport:="20025"}
: ${qmailqread_tcpserver:="@PREFIX@/bin/tcpserver"}
: ${qmailqread_log:="YES"}
: ${qmailqread_logcmd:="logger -t ${procname} -p mail.info"}
: ${qmailqread_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
command="${qmailqread_tcpserver}"
procname=nb${name}
start_precmd="qmailqread_precmd"
extra_commands="stat pause cont"
stat_cmd="qmailqread_stat"
pause_cmd="qmailqread_pause"
cont_cmd="qmailqread_cont"

qmailqread_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno qmailqread_log; then
		qmailqread_logcmd=${qmailqread_nologcmd}
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbqmailqread".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${qmailqread_postenv}
@PREFIX@/bin/argv0 ${qmailqread_tcpserver} ${procname}
${qmailqread_tcpflags}
-u `@ID@ -u @QMAIL_SEND_USER@` -g `@ID@ -g @QMAIL_SEND_USER@`
${qmailqread_tcphost} ${qmailqread_tcpport}
@PREFIX@/bin/qmail-qread
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @QMAIL_LOG_USER@ ${qmailqread_logcmd}"
	command_args="&"
	rc_flags=""
}

qmailqread_stat()
{
	run_rc_command status
}

qmailqread_pause()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailqread_cont()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Continuing ${name}."
	kill -CONT $rc_pid
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailqread_precmd
	eval ${command} ${qmailqread_flags} ${command_args}
fi
