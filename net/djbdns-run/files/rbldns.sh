#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rbldns.sh,v 1.7 2017/08/05 15:16:05 schmonz Exp $
#
# @PKGNAME@ script to control rbldns (local RBL service).
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
: ${rbldns_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/${name}/data.cdb"
command="@PREFIX@/bin/${name}"
procname=nb${name}
start_precmd="rbldns_precmd"
extra_commands="cdb reload"
cdb_cmd="rbldns_cdb"
reload_cmd=${cdb_cmd}

rbldns_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno rbldns_log; then
		rbldns_logcmd=${rbldns_nologcmd}
	fi
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${rbldns_postenv}
ROOT=@PKG_SYSCONFDIR@/${name} IP=${rbldns_ip} BASE=${rbldns_base}
@PREFIX@/bin/envuidgid @DJBDNS_RBL_USER@
@PREFIX@/bin/softlimit -d ${rbldns_datalimit}
@PREFIX@/bin/argv0 @PREFIX@/bin/${name} ${procname}
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DJBDNS_LOG_USER@ ${rbldns_logcmd}"
	command_args="&"
	rc_flags=""
}

rbldns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/${name}/data."
	cd @PKG_SYSCONFDIR@/${name}
	@PREFIX@/bin/rbldns-data
	@CHMOD@ 644 data.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	rbldns_precmd
	eval ${command} ${rbldns_flags} ${command_args}
fi
