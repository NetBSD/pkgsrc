#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: winbindd.sh,v 1.1.1.1 2011/12/15 22:23:24 asau Exp $
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
