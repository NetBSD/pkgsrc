#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: svscan.sh,v 1.5 2017/08/05 15:20:03 schmonz Exp $
#
# @PKGNAME@ script to control svscan (service supervisor).
#

# PROVIDE: svscan
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="svscan"

# User-settable rc.conf variables and their default values:
: ${svscan_postenv:="PATH=@PREFIX@/sbin:@PREFIX@/bin:$PATH"}
: ${svscan_datalimit:="3000000"}
: ${svscan_servicedir:="@VARBASE@/service"}
: ${svscan_log:="YES"}
: ${svscan_logcmd:="logger -t nb${name} -p daemon.info"}
: ${svscan_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_dirs="${svscan_servicedir}"
command="@PREFIX@/bin/${name}"
procname=nb${name}
start_precmd="svscan_precmd"

svscan_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno svscan_log; then
		svscan_logcmd=${svscan_nologcmd}
	fi
	# There might be more than one svscan(8) on a system: for instance,
	# non-root users might run their own svscans. We want to signal only
	# the svscan process responsible for this service. Use argv0(1) to
	# set procname to "nbsvscan".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${svscan_postenv}
@PREFIX@/bin/argv0 @PREFIX@/bin/${name} ${procname}
${svscan_servicedir}
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @DAEMONTOOLS_LOG_USER@ ${svscan_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	svscan_precmd
	eval ${command} ${svscan_flags} ${command_args}
fi
