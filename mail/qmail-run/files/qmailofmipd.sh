#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailofmipd.sh,v 1.1.2.1 2017/04/17 16:12:20 bsiegert Exp $
#
# @PKGNAME@ script to control ofmipd (SMTP submission service).
#

# PROVIDE: qmailofmipd mail
# REQUIRE: qmailsend

name="qmailofmipd"

# User-settable rc.conf variables and their default values:
: ${qmailofmipd_postenv:=""}
: ${qmailofmipd_tcpflags:="-vRl0"}
: ${qmailofmipd_tcphost:="127.0.0.1"}
: ${qmailofmipd_tcpport:="26"}
: ${qmailofmipd_datalimit:="146800640"}
: ${qmailofmipd_pretcpserver:=""}
: ${qmailofmipd_preofmipd:=""}
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
command="@PREFIX@/bin/tcpserver"
procname=${name}
start_precmd="qmailofmipd_precmd"
extra_commands="stat pause cont cdb"
stat_cmd="qmailofmipd_stat"
pause_cmd="qmailofmipd_pause"
cont_cmd="qmailofmipd_cont"
cdb_cmd="qmailofmipd_cdb"

qmailofmipd_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for SMTP
	# service. Use argv0(1) to set procname to "qmailofmipd".
	if [ -f /etc/rc.subr ]; then
		checkyesno qmailofmipd_log || qmailofmipd_logcmd=${qmailofmipd_nologcmd}
	fi
	command="@SETENV@ - ${qmailofmipd_postenv} @PREFIX@/bin/softlimit -m ${qmailofmipd_datalimit} ${qmailofmipd_pretcpserver} @PREFIX@/bin/argv0 @PREFIX@/bin/tcpserver ${name} ${qmailofmipd_tcpflags} -x @PKG_SYSCONFDIR@/tcp.ofmip.cdb -c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencyofmip` -u `@ID@ -u @QMAIL_DAEMON_USER@` -g `@ID@ -g @QMAIL_DAEMON_USER@` ${qmailofmipd_tcphost} ${qmailofmipd_tcpport} ${qmailofmipd_preofmipd} @PREFIX@/bin/ofmipd ${qmailofmipd_postofmipd} 2>&1 | @PREFIX@/bin/setuidgid @QMAIL_LOG_USER@ ${qmailofmipd_logcmd}"
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
		echo $statusmsg
		return 1
	fi
	echo "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailofmipd_cont()
{
	if ! statusmsg=`run_rc_command status`; then
		echo $statusmsg
		return 1
	fi
	echo "Continuing ${name}."
	kill -CONT $rc_pid
}

qmailofmipd_cdb()
{
	echo "Reloading @PKG_SYSCONFDIR@/tcp.ofmip."
	@PREFIX@/bin/tcprules @PKG_SYSCONFDIR@/tcp.ofmip.cdb @PKG_SYSCONFDIR@/tcp.ofmip.tmp < @PKG_SYSCONFDIR@/tcp.ofmip
	/bin/chmod 644 @PKG_SYSCONFDIR@/tcp.ofmip.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	qmailofmipd_precmd
	eval ${command} ${qmailofmipd_flags} ${command_args}
fi
