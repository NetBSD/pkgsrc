#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tofmipd.sh,v 1.3 2007/02/27 00:18:46 schmonz Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN

name="tofmipd"

# User-settable rc.conf variables and their default values:
: ${tofmipd_tcphost:="localhost"}
: ${tofmipd_tcpport:="8025"}
: ${tofmipd_log:="YES"}
: ${tofmipd_logcmd:="logger -t nb${name} -p mail.info"}
: ${tofmipd_nologcmd:="@CAT@ >/dev/null"}

. /etc/rc.subr

rcvar=${name}
command="@PREFIX@/bin/tmda-ofmipd"
command_interpreter="@PYTHONBIN@"
start_precmd="tofmipd_precmd"

tofmipd_precmd()
{
	checkyesno tofmipd_log || tofmipd_logcmd=${tofmipd_nologcmd}
	command="@SETENV@ - ${command} ${tofmipd_flags} -p ${tofmipd_tcphost}:${tofmipd_tcpport} -f -L 2>&1 | @SU@ -m tofmipd -c '${tofmipd_logcmd}'"
	command_args="&"
	rc_flags=""
}

load_rc_config $name
run_rc_command "$1"
