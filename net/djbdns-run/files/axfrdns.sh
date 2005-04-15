#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: axfrdns.sh,v 1.4 2005/04/15 05:15:55 schmonz Exp $
#
# @PKGNAME@ script to control axfrdns (DNS zone-transfer and TCP service)
#

# PROVIDE: axfrdns named
# REQUIRE: SERVERS tinydns
# BEFORE:  DAEMON

name="axfrdns"

# User-settable rc.conf variables and their default values:
: ${axfrdns_postenv:=""}
: ${axfrdns_tcpflags:="-vDRHl0"}
: ${axfrdns_tcpport:="53"}
: ${axfrdns_datalimit:="300000"}
: ${axfrdns_pretcpserver:=""}
: ${axfrdns_log:="YES"}
: ${axfrdns_logcmd:="logger -t nb${name} -p daemon.info"}
: ${axfrdns_nologcmd:="@LOCALBASE@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/axfrdns/tcp.cdb"
command="@LOCALBASE@/bin/tcpserver"
procname=${name}
start_precmd="axfrdns_precmd"
extra_commands="reload cdb"
reload_cmd="axfrdns_cdb"; cdb_cmd=${reload_cmd}

axfrdns_precmd()
{
	if [ -f /etc/rc.subr ]; then
		checkyesno axfrdns_log || axfrdns_logcmd=${axfrdns_nologcmd}
	fi
 	command="@SETENV@ - ${axfrdns_postenv} ROOT=@PKG_SYSCONFDIR@/tinydns IP=${tinydns_ip} @LOCALBASE@/bin/envuidgid axfrdns @LOCALBASE@/bin/softlimit -d ${axfrdns_datalimit} ${axfrdns_pretcpserver} @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} ${axfrdns_tcpflags} -x @PKG_SYSCONFDIR@/axfrdns/tcp.cdb -- ${tinydns_ip} ${axfrdns_tcpport} @LOCALBASE@/bin/axfrdns </dev/null 2>&1 | @LOCALBASE@/bin/setuidgid dnslog ${axfrdns_logcmd}"
	command_args="&"
	rc_flags=""
}

axfrdns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/axfrdns/tcp."
	cd @PKG_SYSCONFDIR@/axfrdns
	@LOCALBASE@/bin/tcprules tcp.cdb tcp.tmp < tcp
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	axfrdns_precmd
	eval ${command} ${axfrdns_flags} ${command_args}
fi
