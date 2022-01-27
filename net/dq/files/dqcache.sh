#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dqcache.sh,v 1.1 2022/01/27 15:31:09 schmonz Exp $
#
# @PKGNAME@ script to control dqcache (caching DNS+DNSCurve resolver).
#

# PROVIDE: dqcache named
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="dqcache"

# User-settable rc.conf variables and their default values:
: ${dqcache_postenv:=""}
: ${dqcache_ip:="127.0.0.1"}
: ${dqcache_size:="10000000"}
: ${dqcache_log:="YES"}
: ${dqcache_logcmd:="logger -t nbdq/cache -p daemon.info"}
: ${dqcache_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_dirs="@PKG_SYSCONFDIR@/${name}/servers"
required_files="@PKG_SYSCONFDIR@/${name}/servers/@"
command="@PREFIX@/sbin/${name}"
procname=nb${name}
start_precmd="dqcache_precmd"

dqcache_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno dqcache_log; then
		dqcache_logcmd=${dqcache_nologcmd}
	fi
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${dqcache_postenv} \
ROOT=@PKG_SYSCONFDIR@/${name} \
IP=${dqcache_ip} \
CACHESIZE=${dqcache_size} \
@PREFIX@/bin/envuidgid @DQCACHE_USER@ \
@PREFIX@/bin/argv0 @PREFIX@/sbin/${name} ${procname} \
2>&1 | \
${dqcache_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	dqcache_precmd
	eval ${command} ${dqcache_flags} ${command_args}
fi
