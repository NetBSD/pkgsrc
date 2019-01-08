#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnscache.sh,v 1.12 2019/01/08 18:19:27 schmonz Exp $
#
# @PKGNAME@ script to control dnscache (caching DNS resolver).
#

# PROVIDE: dnscache named
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="dnscache"

# User-settable rc.conf variables and their default values:
: ${dnscache_postenv:=""}
: ${dnscache_ip:="@DNSCACHE_LISTENIP@"}
: ${dnscache_ipsend:="@DNSCACHE_SENDIP@"}
: ${dnscache_size:="1000000"}
: ${dnscache_datalimit:="30000000"}
: ${dnscache_log:="YES"}
: ${dnscache_logcmd:="logger -t nbdjbdns/cache -p daemon.info"}
: ${dnscache_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_dirs="@PKG_SYSCONFDIR@/${name}/ip @PKG_SYSCONFDIR@/${name}/servers"
required_files="@PKG_SYSCONFDIR@/${name}/servers/@"
command="@PREFIX@/bin/${name}"
procname=nb${name}
start_precmd="dnscache_precmd"

dnscache_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno dnscache_log; then
		dnscache_logcmd=${dnscache_nologcmd}
	fi
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${dnscache_postenv} \
ROOT=@PKG_SYSCONFDIR@/${name} \
IP=${dnscache_ip} \
IPSEND=${dnscache_ipsend} \
CACHESIZE=${dnscache_size} \
@PREFIX@/bin/envuidgid @DJBDNS_CACHE_USER@ \
@PREFIX@/bin/softlimit -o250 -d ${dnscache_datalimit} \
@PREFIX@/bin/argv0 @PREFIX@/bin/${name} ${procname} \
</dev/urandom 2>&1 | \
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DJBDNS_LOG_USER@ ${dnscache_logcmd}"
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
