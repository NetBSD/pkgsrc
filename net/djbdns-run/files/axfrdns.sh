#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: axfrdns.sh,v 1.9 2017/08/05 15:16:05 schmonz Exp $
#
# @PKGNAME@ script to control axfrdns (DNS zone-transfer and TCP service).
#

# PROVIDE: axfrdns named
# REQUIRE: NETWORKING mountcritremote syslogd tinydns
# BEFORE:  DAEMON

name="axfrdns"

# User-settable rc.conf variables and their default values:
: ${axfrdns_postenv:=""}
: ${axfrdns_tcpflags:="-vDRHl0"}
: ${axfrdns_tcpport:="53"}
: ${axfrdns_datalimit:="300000"}
: ${axfrdns_pretcpserver:=""}
: ${axfrdns_tcpserver:="@PREFIX@/bin/tcpserver"}
: ${axfrdns_log:="YES"}
: ${axfrdns_logcmd:="logger -t nb${name} -p daemon.info"}
: ${axfrdns_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/${name}/tcp.cdb"
command="${axfrdns_tcpserver}"
procname=nb${name}
start_precmd="axfrdns_precmd"
extra_commands="cdb reload"
cdb_cmd="axfrdns_cdb"
reload_cmd=${cdb_cmd}

axfrdns_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno axfrdns_log; then
		axfrdns_logcmd=${axfrdns_nologcmd}
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "axfrdns".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${axfrdns_postenv}
ROOT=@PKG_SYSCONFDIR@/tinydns IP=${tinydns_ip}
@PREFIX@/bin/envuidgid @DJBDNS_AXFR_USER@
@PREFIX@/bin/softlimit -d ${axfrdns_datalimit} ${axfrdns_pretcpserver}
@PREFIX@/bin/argv0 ${axfrdns_tcpserver} ${procname}
${axfrdns_tcpflags} -x @PKG_SYSCONFDIR@/${name}/tcp.cdb
-- ${tinydns_ip} ${axfrdns_tcpport}
@PREFIX@/bin/${name}
</dev/null 2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DJBDNS_LOG_USER@ ${axfrdns_logcmd}"
	command_args="&"
	rc_flags=""
}

axfrdns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/axfrdns/tcp."
	cd @PKG_SYSCONFDIR@/${name}
	@PREFIX@/bin/tcprules tcp.cdb tcp.tmp < tcp
	@CHMOD@ 644 tcp.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	axfrdns_precmd
	eval ${command} ${axfrdns_flags} ${command_args}
fi
