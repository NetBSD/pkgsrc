#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailpop3d.sh,v 1.7 2005/07/19 21:06:39 schmonz Exp $
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
: ${qmailpop3d_datalimit:="2000000"}
: ${qmailpop3d_pretcpserver:=""}
: ${qmailpop3d_prepop3d:=""}
: ${qmailpop3d_checkpassword:="@LOCALBASE@/bin/checkpassword"}
: ${qmailpop3d_maildirname:="Maildir"}
: ${qmailpop3d_log:="YES"}
: ${qmailpop3d_logcmd:="logger -t nb${name} -p mail.info"}
: ${qmailpop3d_nologcmd:="@LOCALBASE@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/me"
required_files="${required_files} @PKG_SYSCONFDIR@/control/concurrencypop3"
required_files="${required_files} @PKG_SYSCONFDIR@/tcp.pop3.cdb"
command="@LOCALBASE@/bin/tcpserver"
procname=${name}
start_precmd="qmailpop3d_precmd"
extra_commands="stat pause cont cdb"
stat_cmd="qmailpop3d_stat"
pause_cmd="qmailpop3d_pause"
cont_cmd="qmailpop3d_cont"
cdb_cmd="qmailpop3d_cdb"

qmailpop3d_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for POP
	# service. Use argv0(1) to set procname to "qmailpop3d".
	if [ -f /etc/rc.subr ]; then
		checkyesno qmailpop3d_log || qmailpop3d_logcmd=${qmailpop3d_nologcmd}
	fi
	command="@SETENV@ - ${qmailpop3d_postenv} @LOCALBASE@/bin/softlimit -m ${qmailpop3d_datalimit} ${qmailpop3d_pretcpserver} @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} ${qmailpop3d_tcpflags} -x @PKG_SYSCONFDIR@/tcp.pop3.cdb -c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencypop3` ${qmailpop3d_tcphost} ${qmailpop3d_tcpport} @LOCALBASE@/bin/qmail-popup `@HEAD@ -1 @PKG_SYSCONFDIR@/control/me` ${qmailpop3d_checkpassword} ${qmailpop3d_prepop3d} @LOCALBASE@/bin/qmail-pop3d ${qmailpop3d_maildirname} 2>&1 | @LOCALBASE@/bin/setuidgid qmaill ${qmailpop3d_logcmd}"
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
	@LOCALBASE@/bin/tcprules @PKG_SYSCONFDIR@/tcp.pop3.cdb @PKG_SYSCONFDIR@/tcp.pop3.tmp < @PKG_SYSCONFDIR@/tcp.pop3
	@CHMOD@ 644 @PKG_SYSCONFDIR@/tcp.pop3.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailpop3d_precmd
	eval ${command} ${qmailpop3d_flags} ${command_args}
fi
