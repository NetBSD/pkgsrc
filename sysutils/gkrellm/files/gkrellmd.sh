#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gkrellmd.sh,v 1.2 2025/08/30 08:24:18 pho Exp $
#

# PROVIDE: gkrellmd
# REQUIRE: DAEMON

. /etc/rc.subr

name="gkrellmd"
rcvar=$name
command="@PREFIX@/sbin/gkrellmd"
gkrellmd_flags="-d"

load_rc_config $name
run_rc_command "$1"
