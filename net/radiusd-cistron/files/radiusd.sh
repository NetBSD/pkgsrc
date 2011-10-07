#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radiusd.sh,v 1.2 2011/10/07 22:37:04 shattered Exp $
#

# PROVIDE: radiusd
# REQUIRE: LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="radiusd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-y"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
