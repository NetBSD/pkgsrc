#!/bin/sh
#
# $NetBSD: radiusd.sh,v 1.1 2003/05/01 18:35:47 jmmv Exp $
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
