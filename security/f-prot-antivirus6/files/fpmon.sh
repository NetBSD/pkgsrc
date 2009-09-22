#!@RCD_SCRIPTS_SHELL@
# $NetBSD: fpmon.sh,v 1.1.1.1 2009/09/22 17:38:33 taca Exp $

# PROVIDE: fpmon
# REQUIRE: DAEMON fpscand

. /etc/rc.subr

name="fpmon"
rcvar=$name
conf="@PKG_SYSCONFDIR@/f-prot.conf"
command="@PREFIX@/@FPROTDIR@/fpmon"
required_files="${conf} ${command}"
start_cmd="fpmon_start"

fpmon_start()
{
	if [ -x ${command} ]; then
		${command} ${rc_flags}
	fi
}

load_rc_config $name
run_rc_command "$1"
