#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailsmtpd.sh,v 1.4 2004/07/21 22:35:59 schmonz Exp $
#
# Script to control qmail-smtpd (SMTP service).
#

# PROVIDE: qmailsmtpd mail
# REQUIRE: qmailsend

. /etc/rc.subr

name="qmailsmtpd"
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

# User-settable rc.conf variables and their default values:
qmailsmtpd_postenv=${qmailsmtpd_postenv-"QMAILQUEUE=@PREFIX@/bin/qmail-queue"}
qmailsmtpd_tcpflags=${qmailsmtpd_tcpflags-"-v -R -l 0"}
qmailsmtpd_tcphost=${qmailsmtpd_tcphost-"0"}
qmailsmtpd_tcpport=${qmailsmtpd_tcpport-"25"}
qmailsmtpd_softlimit=${qmailsmtpd_softlimit-"2000000"}
qmailsmtpd_pretcpserver=${qmailsmtpd_pretcpserver-""}
qmailsmtpd_presmtpd=${qmailsmtpd_presmtpd-""}

qmailsmtpd_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for SMTP
	# service. Use argv0(1) to set procname to "qmailsmtpd".
	command="@SETENV@ - ${qmailsmtpd_postenv} @LOCALBASE@/bin/softlimit -m ${qmailsmtpd_softlimit} ${qmailsmtpd_pretcpserver} @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} ${qmailsmtpd_tcpflags} -x @PKG_SYSCONFDIR@/tcp.smtp.cdb -c `@CAT@ @PKG_SYSCONFDIR@/control/concurrencyincoming` -u `@ID@ -u qmaild` -g `@ID@ -g qmaild` ${qmailsmtpd_tcphost} ${qmailsmtpd_tcpport} ${qmailsmtpd_presmtpd} @PREFIX@/bin/qmail-smtpd 2>&1 | @PREFIX@/bin/splogger ${name}"
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
	echo "Reloading @PKG_SYSCONFDIR@/tcp.smtp."
	@LOCALBASE@/bin/tcprules @PKG_SYSCONFDIR@/tcp.smtp.cdb @PKG_SYSCONFDIR@/tcp.smtp.tmp < @PKG_SYSCONFDIR@/tcp.smtp
	@CHMOD@ 644 @PKG_SYSCONFDIR@/tcp.smtp.cdb
}

load_rc_config $name
run_rc_command "$1"
