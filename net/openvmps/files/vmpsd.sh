#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vmpsd.sh,v 1.1.1.1 2005/06/06 16:07:43 bouyer Exp $
#

# PROVIDE: vmpsd
# REQUIRE: DAEMON

. /etc/rc.subr

name="vmpsd"
rcvar="vmpsd"
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/vlan.db"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
