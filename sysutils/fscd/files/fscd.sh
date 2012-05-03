#!/bin/sh
#
# $Id: fscd.sh,v 1.1 2012/05/03 21:21:58 jdf Exp $
#
# Startup script for service monitoring daemon.
#

# PROVIDE: fscd
# REQUIRE: DAEMON syslogd
# BEFORE:  NETWORKING LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="fscd"
rcvar=${name}
pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
