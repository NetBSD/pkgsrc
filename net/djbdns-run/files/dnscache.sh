#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnscache.sh,v 1.1.1.1 2004/09/01 20:13:04 schmonz Exp $
#
# @PKGNAME@ script to control dnscache (caching DNS resolver)
#

# PROVIDE: dnscache named
# REQUIRE: SERVERS
# BEFORE:  DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dnscache"
rcvar=${name}
required_dirs="@PKG_SYSCONFDIR@/dnscache/ip @PKG_SYSCONFDIR@/dnscache/servers"
required_files="@PKG_SYSCONFDIR@/dnscache/servers/@"
command="@LOCALBASE@/bin/${name}"
start_precmd="dnscache_precmd"

# User-settable rc.conf variables and their default values:
dnscache_ip=${dnscache_ip-"127.0.0.1"}
dnscache_ipsend=${dnscache_ipsend-"0.0.0.0"}
dnscache_size=${dnscache_size-"1000000"}
dnscache_datalimit=${dnscache_datalimit-"3000000"}
dnscache_logcmd=${dnscache_logcmd-"@LOCALBASE@/bin/setuidgid Gdnslog logger -t nb${name} -p daemon.info"}

dnscache_precmd()
{
 	command="@SETENV@ - ROOT=@PKG_SYSCONFDIR@/dnscache IP=${dnscache_ip} IPSEND=${dnscache_ipsend} CACHESIZE=${dnscache_size} @LOCALBASE@/bin/envuidgid Gdnscache @LOCALBASE@/bin/softlimit -o250 -d ${dnscache_datalimit} @LOCALBASE@/bin/dnscache </dev/random 2>&1 | ${dnscache_logcmd}"
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
