#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinydns.sh,v 1.9 2017/08/05 15:16:05 schmonz Exp $
#
# @PKGNAME@ script to control tinydns (authoritative DNS service).
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
: ${tinydns_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/${name}/data.cdb"
command="@PREFIX@/bin/${name}"
procname=nb${name}
start_precmd="tinydns_precmd"
extra_commands="cdb reload"
cdb_cmd="tinydns_cdb"
reload_cmd=${cdb_cmd}

tinydns_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno tinydns_log; then
		tinydns_logcmd=${tinydns_nologcmd}
	fi
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${tinydns_postenv}
ROOT=@PKG_SYSCONFDIR@/${name} IP=${tinydns_ip}
@PREFIX@/bin/envuidgid @DJBDNS_TINY_USER@
@PREFIX@/bin/softlimit -d ${tinydns_datalimit}
@PREFIX@/bin/argv0 @PREFIX@/bin/${name} ${procname}
</dev/null 2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DJBDNS_LOG_USER@ ${tinydns_logcmd}"
	command_args="&"
	rc_flags=""
}

tinydns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/${name}/data."
	cd @PKG_SYSCONFDIR@/${name}
	@PREFIX@/bin/tinydns-data
	@CHMOD@ 644 data.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	tinydns_precmd
	eval ${command} ${tinydns_flags} ${command_args}
fi
