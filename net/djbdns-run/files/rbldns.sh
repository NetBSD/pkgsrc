#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rbldns.sh,v 1.1 2005/01/26 07:01:10 schmonz Exp $
#
# @PKGNAME@ script to control rbldns (local RBL service)
#

# PROVIDE: rbldns named
# REQUIRE: SERVERS
# BEFORE:  DAEMON

name="rbldns"

# User-settable rc.conf variables and their default values:
rbldns_ip=${rbldns_ip-"127.0.0.3"}
rbldns_base=${rbldns_base-"rbl"}
rbldns_datalimit=${rbldns_datalimit-"250000"}
rbldns_logcmd=${rbldns_logcmd-"@LOCALBASE@/bin/setuidgid dnslog logger -t nb${name} -p daemon.info"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/rbldns/data.cdb"
command="@LOCALBASE@/bin/${name}"
start_precmd="rbldns_precmd"
extra_commands="cdb"
cdb_cmd="rbldns_cdb"

rbldns_precmd()
{
 	command="@SETENV@ - ROOT=@PKG_SYSCONFDIR@/rbldns IP=${rbldns_ip} BASE=${rbldns_base} @LOCALBASE@/bin/envuidgid rbldns @LOCALBASE@/bin/softlimit -d ${rbldns_datalimit} @LOCALBASE@/bin/rbldns 2>&1 | ${rbldns_logcmd}"
	command_args="&"
	rc_flags=""
}

rbldns_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/rbldns/data."
	cd @PKG_SYSCONFDIR@/rbldns
	@LOCALBASE@/bin/rbldns-data
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	rbldns_precmd
	eval ${command} ${rbldns_flags} ${command_args}
fi
