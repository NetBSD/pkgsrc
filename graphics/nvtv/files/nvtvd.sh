#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nvtvd.sh,v 1.1.1.1 2003/10/05 09:16:17 cube Exp $
#

# PROVIDE: nvtvd
# REQUIRE: DAEMON

. /etc/rc.subr

name="nvtvd"
rcvar=$name
command="@PREFIX@/bin/nvtvd"

load_rc_config $name
run_rc_command "$1"
