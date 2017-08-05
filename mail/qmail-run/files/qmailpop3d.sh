#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailpop3d.sh,v 1.16 2017/08/05 03:03:17 schmonz Exp $
#
# @PKGNAME@ script to control qmail-pop3d (POP3 server for Maildirs).
#

# PROVIDE: qmailpop3d mail

name="qmailpop3d"

# User-settable rc.conf variables and their default values:
: ${qmailpop3d_postenv:=""}
: ${qmailpop3d_tcpflags:="-vRHl0"}
: ${qmailpop3d_tcphost:="0"}
: ${qmailpop3d_tcpport:="110"}
: ${qmailpop3d_datalimit:="180000000"}
: ${qmailpop3d_pretcpserver:=""}
: ${qmailpop3d_tcpserver:="@PREFIX@/bin/tcpserver"}
: ${qmailpop3d_prepop3d:=""}
: ${qmailpop3d_pop3dcmd:="@PREFIX@/bin/qmail-pop3d"}
: ${qmailpop3d_checkpassword:="@PREFIX@/bin/checkpassword"}
: ${qmailpop3d_maildirname:="Maildir"}
: ${qmailpop3d_log:="YES"}
: ${qmailpop3d_logcmd:="logger -t ${procname} -p mail.info"}
: ${qmailpop3d_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/me"
required_files="${required_files} @PKG_SYSCONFDIR@/control/concurrencypop3"
required_files="${required_files} @PKG_SYSCONFDIR@/tcp.pop3.cdb"
command="${qmailpop3d_tcpserver}"
procname=nb${name}
start_precmd="qmailpop3d_precmd"
extra_commands="stat pause cont cdb reload"
stat_cmd="qmailpop3d_stat"
pause_cmd="qmailpop3d_pause"
cont_cmd="qmailpop3d_cont"
cdb_cmd="qmailpop3d_cdb"
reload_cmd=${cdb_cmd}

qmailpop3d_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno qmailpop3d_log; then
		qmailpop3d_logcmd=${qmailpop3d_nologcmd}
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbqmailpop3d".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${qmailpop3d_postenv}
@PREFIX@/bin/softlimit -m ${qmailpop3d_datalimit} ${qmailpop3d_pretcpserver}
@PREFIX@/bin/argv0 ${qmailpop3d_tcpserver} ${procname}
${qmailpop3d_tcpflags} -x @PKG_SYSCONFDIR@/tcp.pop3.cdb
-c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencypop3`
${qmailpop3d_tcphost} ${qmailpop3d_tcpport} @PREFIX@/bin/qmail-popup
`@HEAD@ -1 @PKG_SYSCONFDIR@/control/me` ${qmailpop3d_checkpassword}
${qmailpop3d_prepop3d} ${qmailpop3d_pop3dcmd} ${qmailpop3d_maildirname}
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @QMAIL_LOG_USER@ ${qmailpop3d_logcmd}"
	command_args="&"
	rc_flags=""
}

qmailpop3d_stat()
{
	run_rc_command status
}

qmailpop3d_pause()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailpop3d_cont()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Continuing ${name}."
	kill -CONT $rc_pid
}

qmailpop3d_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/tcp.pop3."
	cd @PKG_SYSCONFDIR@
	@PREFIX@/bin/tcprules tcp.pop3.cdb tcp.pop3.tmp < tcp.pop3
	@CHMOD@ 644 tcp.pop3.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailpop3d_precmd
	eval ${command} ${qmailpop3d_flags} ${command_args}
fi
