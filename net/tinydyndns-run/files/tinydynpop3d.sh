#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinydynpop3d.sh,v 1.2 2020/10/19 07:15:55 schmonz Exp $
#
# @PKGNAME@ script to authenticate tinydyndns updates.
#

# PROVIDE: tinydynpop3d named

name="tinydynpop3d"

# User-settable rc.conf variables and their default values:
: ${tinydynpop3d_postenv:="CVM_PWFILE_PWCMP=crypt"}
: ${tinydynpop3d_datalimit:="180000000"}
: ${tinydynpop3d_pretcpserver:=""}
: ${tinydynpop3d_tcpserver:="@PREFIX@/bin/tcpserver"}
: ${tinydynpop3d_tcpflags:="-vRH"}
: ${tinydynpop3d_tcphost:="0.0.0.0"}
: ${tinydynpop3d_tcpport:="110"}
: ${tinydynpop3d_precheckpassword:="@PREFIX@/bin/qmail-popup $(@HEAD@ -1 @PKG_SYSCONFDIR@/domain)"}
: ${tinydynpop3d_checkpassword:="@PREFIX@/bin/cvm-checkpassword @PREFIX@/bin/cvm-pwfile"}
: ${tinydynpop3d_prepop3d:="@PREFIX@/bin/tinydyndns-call-update"}
: ${tinydynpop3d_pop3dcmd:="@PREFIX@/bin/tinydyndns-pop3d"}
: ${tinydynpop3d_postpop3d:=""}
: ${tinydynpop3d_log:="YES"}
: ${tinydynpop3d_logcmd:="logger -t nbtinydyn/pop3d -p mail.info"}
: ${tinydynpop3d_nologcmd:="@PREFIX@/bin/multilog -*"}

tinydyn_cdb="@PKG_SYSCONFDIR@/data.cdb"
tinydyn_domain="@PKG_SYSCONFDIR@/domain"
tinydyn_passwd="@PKG_SYSCONFDIR@/passwd"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="${tinydyn_cdb} ${tinydyn_domain}"
rcvar=${name}
command="${tinydynpop3d_tcpserver}"
procname=nb${name}
start_precmd="tinydynpop3d_precmd"

tinydynpop3d_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno tinydynpop3d_log; then
		tinydynpop3d_logcmd=${tinydynpop3d_nologcmd}
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbtinydynpop3d".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${tinydynpop3d_postenv} \
CVM_PWFILE_PATH=${tinydyn_passwd} \
@PREFIX@/bin/softlimit -m ${tinydynpop3d_datalimit} ${tinydynpop3d_pretcpserver} \
@PREFIX@/bin/argv0 ${tinydynpop3d_tcpserver} ${procname} \
${tinydynpop3d_tcpflags} \
${tinydynpop3d_tcphost} ${tinydynpop3d_tcpport} \
${tinydynpop3d_precheckpassword} ${tinydynpop3d_checkpassword} \
${tinydynpop3d_prepop3d} ${tinydynpop3d_pop3dcmd} ${tinydynpop3d_postpop3d} \
2>&1 7>&1 | \
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DJBDNS_LOG_USER@ ${tinydynpop3d_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	tinydynpop3d_precmd
	eval ${command} ${tinydynpop3d_flags} ${command_args}
fi
