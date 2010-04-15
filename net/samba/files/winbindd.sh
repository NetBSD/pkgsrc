#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: winbindd.sh,v 1.5 2010/04/15 09:36:50 sborrill Exp $
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
