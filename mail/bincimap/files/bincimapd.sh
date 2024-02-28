#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bincimapd.sh,v 1.2 2024/02/28 04:14:16 schmonz Exp $
#

# PROVIDE: bincimapd mail

name="bincimapd"

# User-settable rc.conf variables and their default values:
: ${bincimapd_postenv:="VERBOSE_GREETING=yes"}
: ${bincimapd_datalimit:="180000000"}
: ${bincimapd_pretcpserver:=""}
: ${bincimapd_tcpserver:="@PREFIX@/bin/sslserver"}
: ${bincimapd_tcpflags:="-ne -vRl0"}
: ${bincimapd_tcphost:=":0"}
: ${bincimapd_tcpport:="993"}
: ${bincimapd_precheckpassword:="@PREFIX@/bin/bincimap-up --"}
: ${bincimapd_checkpassword:="@PREFIX@/bin/nbcheckpassword"}
: ${bincimapd_preimapd:="@PREFIX@/bin/checknotroot"}
: ${bincimapd_imapdcmd:="@PREFIX@/bin/bincimapd"}
: ${bincimapd_postimapd:="Maildir"}
: ${bincimapd_log:="YES"}
: ${bincimapd_logcmd:="logger -t bincimap -p mail.info"}
: ${bincimapd_nologcmd:="@PREFIX@/bin/multilog -*"}
: ${bincimapd_tls:="YES"}
: ${bincimapd_tls_dhparams:="@PKG_SYSCONFDIR@/certs/dh2048.pem"}
: ${bincimapd_tls_cert:="@PKG_SYSCONFDIR@/certs/servercert.pem"}
: ${bincimapd_tls_key:="@PKG_SYSCONFDIR@/certs/serverkey.pem"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
command="${bincimapd_tcpserver}"
procname=nb${name}
start_precmd="bincimapd_precmd"

bincimapd_configure_tls() {
	if [ "auto" = "${bincimapd_tls}" ]; then
		if [ -f "${bincimapd_tls_cert}" ]; then
			bincimapd_enable_tls
		else
			bincimapd_disable_tls
		fi
	elif [ -f /etc/rc.subr ] && checkyesno bincimapd_tls; then
		bincimapd_enable_tls
	else
		bincimapd_disable_tls
	fi
}

bincimapd_disable_tls() {
	bincimapd_postenv="ALLOW_NONSSL_PLAINTEXT_LOGINS=yes ${bincimapd_postenv}"
}

bincimapd_enable_tls() {
	bincimapd_postenv="CADIR=@SSLDIR@/certs ${bincimapd_postenv}"
	bincimapd_postenv="SSL_UID=$(@ID@ -u @UCSPI_SSL_USER@) ${bincimapd_postenv}"
	bincimapd_postenv="SSL_GID=$(@ID@ -g @UCSPI_SSL_GROUP@) ${bincimapd_postenv}"
	bincimapd_postenv="DHFILE=${bincimapd_tls_dhparams} ${bincimapd_postenv}"
	bincimapd_postenv="CERTFILE=${bincimapd_tls_cert} ${bincimapd_postenv}"
	if [ -n "${bincimapd_tls_key}" -a ! -f "${bincimapd_tls_key}" ]; then
		@OPENSSL@ rsa -in ${bincimapd_tls_cert} -out ${bincimapd_tls_key}
		@CHMOD@ 640 ${bincimapd_tls_key}
	fi
	bincimapd_postenv="KEYFILE=${bincimapd_tls_key} ${bincimapd_postenv}"
}


bincimapd_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno bincimapd_log; then
		bincimapd_logcmd=${bincimapd_nologcmd}
	fi
	bincimapd_configure_tls
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbbincimapd".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${bincimapd_postenv} \
@PREFIX@/bin/softlimit -m ${bincimapd_datalimit} ${bincimapd_pretcpserver} \
@PREFIX@/bin/argv0 ${bincimapd_tcpserver} ${procname} \
${bincimapd_tcpflags} \
-u @BINCIMAP_USER@ -g @BINCIMAP_GROUP@ \
${bincimapd_tcphost} ${bincimapd_tcpport} \
${bincimapd_precheckpassword} ${bincimapd_checkpassword} \
${bincimapd_preimapd} ${bincimapd_imapdcmd} ${bincimapd_postimapd} \
2>&1 | \
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @BINCIMAP_LOG_USER@ ${bincimapd_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	bincimapd_precmd
	eval ${command} ${bincimapd_flags} ${command_args}
fi
