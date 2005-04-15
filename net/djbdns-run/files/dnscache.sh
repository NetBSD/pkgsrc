#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnscache.sh,v 1.4 2005/04/15 05:15:55 schmonz Exp $
#
# @PKGNAME@ script to control dnscache (caching DNS resolver)
#

# PROVIDE: dnscache named
# REQUIRE: SERVERS
# BEFORE:  DAEMON

name="dnscache"

# User-settable rc.conf variables and their default values:
: ${dnscache_postenv:=""}
: ${dnscache_ip:="127.0.0.1"}
: ${dnscache_ipsend:="0.0.0.0"}
: ${dnscache_size:="1000000"}
: ${dnscache_datalimit:="3000000"}
: ${dnscache_log:="YES"}
: ${dnscache_logcmd:="logger -t nb${name} -p daemon.info"}
: ${dnscache_nologcmd:="@LOCALBASE@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_dirs="@PKG_SYSCONFDIR@/dnscache/ip @PKG_SYSCONFDIR@/dnscache/servers"
required_files="@PKG_SYSCONFDIR@/dnscache/servers/@"
command="@LOCALBASE@/bin/${name}"
start_precmd="dnscache_precmd"

dnscache_precmd()
{
	if [ -f /etc/rc.subr ]; then
		checkyesno dnscache_log || dnscache_logcmd=${dnscache_nologcmd}
	fi
 	command="@SETENV@ - ${dnscache_postenv} ROOT=@PKG_SYSCONFDIR@/dnscache IP=${dnscache_ip} IPSEND=${dnscache_ipsend} CACHESIZE=${dnscache_size} @LOCALBASE@/bin/envuidgid dnscache @LOCALBASE@/bin/softlimit -o250 -d ${dnscache_datalimit} @LOCALBASE@/bin/dnscache </dev/random 2>&1 | @LOCALBASE@/bin/setuidgid dnslog ${dnscache_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	dnscache_precmd
	eval ${command} ${dnscache_flags} ${command_args}
fi
