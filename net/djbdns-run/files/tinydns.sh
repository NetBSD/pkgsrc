#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinydns.sh,v 1.6 2014/12/07 04:33:31 schmonz Exp $
#
# @PKGNAME@ script to control tinydns (authoritative DNS service)
#

# PROVIDE: tinydns named
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="tinydns"

# User-settable rc.conf variables and their default values:
: ${tinydns_postenv:=""}
: ${tinydns_ip:="127.0.0.2"}
: ${tinydns_datalimit:="300000"}
: ${tinydns_log:="YES"}
: ${tinydns_logcmd:="logger -t nb${name} -p daemon.info"}
: ${tinydns_nologcmd:="@DAEMONTOOLS_PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/tinydns/data.cdb"
command="@DJBDNS_PREFIX@/bin/${name}"
start_precmd="tinydns_precmd"
extra_commands="reload cdb"
reload_cmd="tinydns_cdb"; cdb_cmd=${reload_cmd}

tinydns_precmd()
{
	if [ -f /etc/rc.subr ]; then
		checkyesno tinydns_log || tinydns_logcmd=${tinydns_nologcmd}
	fi
	command="@SETENV@ - ${tinydns_postenv} ROOT=@PKG_SYSCONFDIR@/tinydns IP=${tinydns_ip} @DAEMONTOOLS_PREFIX@/bin/envuidgid tinydns @DAEMONTOOLS_PREFIX@/bin/softlimit -d ${tinydns_datalimit} @DJBDNS_PREFIX@/bin/tinydns </dev/null 2>&1 | @DAEMONTOOLS_PREFIX@/bin/setuidgid dnslog ${tinydns_logcmd}"
	command_args="&"
	rc_flags=""
}

tinydns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/tinydns/data."
	cd @PKG_SYSCONFDIR@/tinydns
	@DJBDNS_PREFIX@/bin/tinydns-data
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	tinydns_precmd
	eval ${command} ${tinydns_flags} ${command_args}
fi
