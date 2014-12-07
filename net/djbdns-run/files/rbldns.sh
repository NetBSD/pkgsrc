#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rbldns.sh,v 1.4 2014/12/07 04:33:31 schmonz Exp $
#
# @PKGNAME@ script to control rbldns (local RBL service)
#

# PROVIDE: rbldns named
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="rbldns"

# User-settable rc.conf variables and their default values:
: ${rbldns_postenv:=""}
: ${rbldns_ip:="127.0.0.3"}
: ${rbldns_base:="rbl"}
: ${rbldns_datalimit:="250000"}
: ${rbldns_log:="YES"}
: ${rbldns_logcmd:="logger -t nb${name} -p daemon.info"}
: ${rbldns_nologcmd:="@DAEMONTOOLS_PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/rbldns/data.cdb"
command="@DJBDNS_PREFIX@/bin/${name}"
start_precmd="rbldns_precmd"
extra_commands="reload cdb"
reload_cmd="rbldns_cdb"; cdb_cmd=${reload_cmd}

rbldns_precmd()
{
	if [ -f /etc/rc.subr ]; then
		checkyesno rbldns_log || rbldns_logcmd=${rbldns_nologcmd}
	fi
	command="@SETENV@ - ${rbldns_postenv} ROOT=@PKG_SYSCONFDIR@/rbldns IP=${rbldns_ip} BASE=${rbldns_base} @DAEMONTOOLS_PREFIX@/bin/envuidgid rbldns @DAEMONTOOLS_PREFIX@/bin/softlimit -d ${rbldns_datalimit} @DJBDNS_PREFIX@/bin/rbldns 2>&1 | @DAEMONTOOLS_PREFIX@/bin/setuidgid dnslog ${rbldns_logcmd}"
	command_args="&"
	rc_flags=""
}

rbldns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/rbldns/data."
	cd @PKG_SYSCONFDIR@/rbldns
	@DJBDNS_PREFIX@/bin/rbldns-data
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	rbldns_precmd
	eval ${command} ${rbldns_flags} ${command_args}
fi
