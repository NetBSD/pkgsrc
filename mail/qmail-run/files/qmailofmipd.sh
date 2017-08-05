#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailofmipd.sh,v 1.9 2017/08/05 15:21:03 schmonz Exp $
#
# @PKGNAME@ script to control ofmipd (SMTP submission service).
#

# PROVIDE: qmailofmipd mail
# REQUIRE: qmailsend

name="qmailofmipd"

# User-settable rc.conf variables and their default values:
: ${qmailofmipd_postenv:="QMAILQUEUE=@PREFIX@/bin/qmail-queue"}
: ${qmailofmipd_tcpflags:="-vRl0"}
: ${qmailofmipd_tcphost:="127.0.0.1"}
: ${qmailofmipd_tcpport:="26"}
: ${qmailofmipd_datalimit:="180000000"}
: ${qmailofmipd_pretcpserver:=""}
: ${qmailofmipd_tcpserver:="@PREFIX@/bin/tcpserver"}
: ${qmailofmipd_preofmipd:=""}
: ${qmailofmipd_ofmipdcmd:="@PREFIX@/bin/ofmipd"}
: ${qmailofmipd_postofmipd:=""}
: ${qmailofmipd_log:="YES"}
: ${qmailofmipd_logcmd:="logger -t nb${name} -p mail.info"}
: ${qmailofmipd_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/concurrencyofmip"
required_files="${required_files} @PKG_SYSCONFDIR@/tcp.ofmip.cdb"
required_files="${required_files} @PKG_SYSCONFDIR@/control/rcpthosts"
command="${qmailofmipd_tcpserver}"
procname=nb${name}
start_precmd="qmailofmipd_precmd"
extra_commands="stat pause cont cdb reload"
stat_cmd="qmailofmipd_stat"
pause_cmd="qmailofmipd_pause"
cont_cmd="qmailofmipd_cont"
cdb_cmd="qmailofmipd_cdb"
reload_cmd=${cdb_cmd}

qmailofmipd_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno qmailofmipd_log; then
		qmailofmipd_logcmd=${qmailofmipd_nologcmd}
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbqmailofmipd".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${qmailofmipd_postenv}
@PREFIX@/bin/softlimit -m ${qmailofmipd_datalimit} ${qmailofmipd_pretcpserver}
@PREFIX@/bin/argv0 ${qmailofmipd_tcpserver} ${procname}
${qmailofmipd_tcpflags} -x @PKG_SYSCONFDIR@/tcp.ofmip.cdb
-c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencyofmip`
-u `@ID@ -u @QMAIL_DAEMON_USER@` -g `@ID@ -g @QMAIL_DAEMON_USER@`
${qmailofmipd_tcphost} ${qmailofmipd_tcpport}
${qmailofmipd_preofmipd} ${qmailofmipd_ofmipdcmd} ${qmailofmipd_postofmipd}
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @QMAIL_LOG_USER@ ${qmailofmipd_logcmd}"
	command_args="&"
	rc_flags=""
}

qmailofmipd_stat()
{
	run_rc_command status
}

qmailofmipd_pause()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailofmipd_cont()
{
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Continuing ${name}."
	kill -CONT $rc_pid
}

qmailofmipd_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/tcp.ofmip."
	cd @PKG_SYSCONFDIR@
	@PREFIX@/bin/tcprules tcp.ofmip.cdb tcp.ofmip.tmp < tcp.ofmip
	@CHMOD@ 644 tcp.ofmip.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailofmipd_precmd
	eval ${command} ${qmailofmipd_flags} ${command_args}
fi
