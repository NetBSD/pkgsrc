#!/bin/sh
#
# $Id: fscd.sh,v 1.2 2012/11/12 12:11:11 jdf Exp $
#
# Startup script for service monitoring daemon.
#

# PROVIDE: fscd
# REQUIRE: DAEMON syslogd
# BEFORE:  LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="fscd"
rcvar=${name}
pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
