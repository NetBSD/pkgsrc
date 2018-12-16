#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailofmipd.sh,v 1.23 2018/12/16 05:32:07 schmonz Exp $
#
# @PKGNAME@ script to control ofmipd (SMTP submission service).
#

# PROVIDE: qmailofmipd mail
# REQUIRE: qmailsend

name="qmailofmipd"

# User-settable rc.conf variables and their default values:
: ${qmailofmipd_postenv:="SSL_UID=$(@ID@ -u @UCSPI_SSL_USER@) SSL_GID=$(@ID@ -g @UCSPI_SSL_GROUP@)"}
: ${qmailofmipd_datalimit:="360000000"}
: ${qmailofmipd_pretcpserver:=""}
: ${qmailofmipd_tcpserver:="@PREFIX@/bin/sslserver"}
: ${qmailofmipd_tcpflags:="-ne -vRl0"}
: ${qmailofmipd_tcphost:="0"}
: ${qmailofmipd_tcpport:="587"}
: ${qmailofmipd_tcprules:="@PKG_SYSCONFDIR@/control/tcprules/ofmip"}
: ${qmailofmipd_autocdb:="YES"}
: ${qmailofmipd_precheckpassword:="@PREFIX@/bin/reup -t 5 @PREFIX@/bin/authup smtp"}
: ${qmailofmipd_checkpassword:="@PREFIX@/bin/nbcheckpassword"}
: ${qmailofmipd_preofmipd:="@PREFIX@/bin/checknotroot @PREFIX@/bin/fixsmtpio"}
: ${qmailofmipd_ofmipdcmd:="@PREFIX@/bin/ofmipd-with-user-cdb"}
: ${qmailofmipd_postofmipd:=""}
: ${qmailofmipd_log:="YES"}
: ${qmailofmipd_logcmd:="logger -t nbqmail/ofmipd -p mail.info"}
: ${qmailofmipd_nologcmd:="@PREFIX@/bin/multilog -*"}
: ${qmailofmipd_tls:="auto"}
: ${qmailofmipd_tls_dhparams:="@PKG_SYSCONFDIR@/control/dh2048.pem"}
: ${qmailofmipd_tls_cert:="@PKG_SYSCONFDIR@/control/servercert.pem"}
: ${qmailofmipd_tls_key:=""}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/me"
required_files="${required_files} @PKG_SYSCONFDIR@/control/concurrencysubmission"
required_files="${required_files} @PKG_SYSCONFDIR@/control/rcpthosts"
required_files="${required_files} @PKG_SYSCONFDIR@/control/smtpcapabilities"
required_files="${required_files} @PKG_SYSCONFDIR@/control/fixsmtpio"
required_files="${required_files} ${qmailofmipd_tcprules}"
command="${qmailofmipd_tcpserver}"
procname=nb${name}
start_precmd="qmailofmipd_precmd"
extra_commands="stat pause cont cdb reload"
stat_cmd="qmailofmipd_stat"
pause_cmd="qmailofmipd_pause"
cont_cmd="qmailofmipd_cont"
cdb_cmd="qmailofmipd_cdb"
reload_cmd=${cdb_cmd}

qmailofmipd_configure_tls() {
	if [ "auto" = "${qmailofmipd_tls}" ]; then
		if [ -f "${qmailofmipd_tls_dhparams}" ] && [ -f "${qmailofmipd_tls_cert}" ]; then
			qmailofmipd_enable_tls
		else
			qmailofmipd_disable_tls
		fi
	elif [ -f /etc/rc.subr ] && checkyesno qmailofmipd_tls; then
		qmailofmipd_enable_tls
	else
		qmailofmipd_disable_tls
	fi
}

qmailofmipd_disable_tls() {
	qmailofmipd_postenv="${qmailofmipd_postenv} DISABLETLS=1"
}

qmailofmipd_enable_tls() {
	qmailofmipd_postenv="${qmailofmipd_postenv} DHFILE=${qmailofmipd_tls_dhparams}"
	qmailofmipd_postenv="${qmailofmipd_postenv} CERTFILE=${qmailofmipd_tls_cert}"
	if [ -f "${qmailofmipd_tls_key}" ]; then
		qmailofmipd_postenv="${qmailofmipd_postenv} KEYFILE=${qmailofmipd_tls_key}"
	fi
}

qmailofmipd_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno qmailofmipd_log; then
		qmailofmipd_logcmd=${qmailofmipd_nologcmd}
	fi
	qmailofmipd_configure_tls
	if [ -f /etc/rc.subr ] && checkyesno qmailofmipd_autocdb; then
		qmailofmipd_needcdb && qmailofmipd_cdb
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbqmailofmipd".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${qmailofmipd_postenv} \
@PREFIX@/bin/softlimit -m ${qmailofmipd_datalimit} ${qmailofmipd_pretcpserver} \
@PREFIX@/bin/argv0 ${qmailofmipd_tcpserver} ${procname} \
${qmailofmipd_tcpflags} -x ${qmailofmipd_tcprules}.cdb \
-c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencysubmission` \
${qmailofmipd_tcphost} ${qmailofmipd_tcpport} \
${qmailofmipd_precheckpassword} ${qmailofmipd_checkpassword} \
${qmailofmipd_preofmipd} ${qmailofmipd_ofmipdcmd} ${qmailofmipd_postofmipd} \
2>&1 | \
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @QMAIL_LOG_USER@ ${qmailofmipd_logcmd}"
	command_args="&"
	rc_flags=""
}

qmailofmipd_stat() {
	run_rc_command status
}

qmailofmipd_pause() {
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailofmipd_cont() {
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Continuing ${name}."
	kill -CONT $rc_pid
}

qmailofmipd_needcdb() {
	_src=${qmailofmipd_tcprules}
	_dst=${qmailofmipd_tcprules}.cdb
	[ -f "${_src}" -a "${_src}" -nt "${_dst}" ] || [ ! -f "${_dst}" ]
}

qmailofmipd_cdb() {
	@ECHO@ "Reloading ${qmailofmipd_tcprules}"
	@PREFIX@/bin/tcprules ${qmailofmipd_tcprules}.cdb ${qmailofmipd_tcprules}.tmp < ${qmailofmipd_tcprules}
	@CHMOD@ 644 ${qmailofmipd_tcprules}.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailofmipd_precmd
	eval ${command} ${qmailofmipd_flags} ${command_args}
fi
