#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gkrellmd.sh,v 1.1.1.1 2004/02/24 22:11:28 cube Exp $
#

# PROVIDE: gkrellmd
# REQUIRE: DAEMON

. /etc/rc.subr

name="gkrellmd"
rcvar=$name
command="@PREFIX@/bin/gkrellmd"
gkrellmd_flags="-d"

load_rc_config $name
run_rc_command "$1"
