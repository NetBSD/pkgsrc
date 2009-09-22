#!@RCD_SCRIPTS_SHELL@
# $NetBSD: fpscand.sh,v 1.1.1.1 2009/09/22 17:38:33 taca Exp $

# PROVIDE: fpscand
# REQUIRE: DAEMON

. /etc/rc.subr

name="fpscand"
rcvar=$name
conf="@PKG_SYSCONFDIR@/f-prot.conf"
command="@PREFIX@/@FPROTDIR@/fpscand"
required_files="${conf} ${command}"
start_cmd="fpscand_start"

fpscand_start()
{
	if [ -x ${command} ]; then
		${command} ${rc_flags}
	fi
}

load_rc_config $name
run_rc_command "$1"
