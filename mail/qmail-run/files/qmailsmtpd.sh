#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailsmtpd.sh,v 1.7 2005/07/19 21:06:39 schmonz Exp $
#
# @PKGNAME@ script to control qmail-smtpd (SMTP service).
#

# PROVIDE: qmailsmtpd mail
# REQUIRE: qmailsend

name="qmailsmtpd"

# User-settable rc.conf variables and their default values:
: ${qmailsmtpd_postenv:="QMAILQUEUE=@LOCALBASE@/bin/qmail-queue"}
: ${qmailsmtpd_tcpflags:="-vRl0"}
: ${qmailsmtpd_tcphost:="0"}
: ${qmailsmtpd_tcpport:="25"}
: ${qmailsmtpd_datalimit:="2000000"}
: ${qmailsmtpd_pretcpserver:=""}
: ${qmailsmtpd_presmtpd:=""}
: ${qmailsmtpd_postsmtpd:=""}
: ${qmailsmtpd_log:="YES"}
: ${qmailsmtpd_logcmd:="logger -t nb${name} -p mail.info"}
: ${qmailsmtpd_nologcmd:="@LOCALBASE@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/concurrencyincoming"
required_files="${required_files} @PKG_SYSCONFDIR@/tcp.smtp.cdb"
required_files="${required_files} @PKG_SYSCONFDIR@/control/rcpthosts"
command="@LOCALBASE@/bin/tcpserver"
procname=${name}
start_precmd="qmailsmtpd_precmd"
extra_commands="stat pause cont cdb"
stat_cmd="qmailsmtpd_stat"
pause_cmd="qmailsmtpd_pause"
cont_cmd="qmailsmtpd_cont"
cdb_cmd="qmailsmtpd_cdb"

qmailsmtpd_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for SMTP
	# service. Use argv0(1) to set procname to "qmailsmtpd".
	if [ -f /etc/rc.subr ]; then
		checkyesno qmailsmtpd_log || qmailsmtpd_logcmd=${qmailsmtpd_nologcmd}
	fi
	command="@SETENV@ - ${qmailsmtpd_postenv} @LOCALBASE@/bin/softlimit -m ${qmailsmtpd_datalimit} ${qmailsmtpd_pretcpserver} @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} ${qmailsmtpd_tcpflags} -x @PKG_SYSCONFDIR@/tcp.smtp.cdb -c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencyincoming` -u `@ID@ -u qmaild` -g `@ID@ -g qmaild` ${qmailsmtpd_tcphost} ${qmailsmtpd_tcpport} ${qmailsmtpd_presmtpd} @LOCALBASE@/bin/qmail-smtpd ${qmailsmtpd_postsmtpd} 2>&1 | @LOCALBASE@/bin/setuidgid qmaill ${qmailsmtpd_logcmd}"
	command_args="&"
	rc_flags=""
}

qmailsmtpd_stat()
{
	run_rc_command status
}

qmailsmtpd_pause()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailsmtpd_cont()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Continuing ${name}."
	kill -CONT $rc_pid
}

qmailsmtpd_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/tcp.smtp."
	@LOCALBASE@/bin/tcprules @PKG_SYSCONFDIR@/tcp.smtp.cdb @PKG_SYSCONFDIR@/tcp.smtp.tmp < @PKG_SYSCONFDIR@/tcp.smtp
	@CHMOD@ 644 @PKG_SYSCONFDIR@/tcp.smtp.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailsmtpd_precmd
	eval ${command} ${qmailsmtpd_flags} ${command_args}
fi
