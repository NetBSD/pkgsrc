#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: winbindd.sh,v 1.4.36.1 2010/04/15 18:07:23 tron Exp $
#
# PROVIDE: winbindd
# REQUIRE: DAEMON

. /etc/rc.subr

name="winbindd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
