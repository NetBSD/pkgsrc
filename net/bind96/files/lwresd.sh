#!/bin/sh
#
# $NetBSD: lwresd.sh,v 1.1.1.1 2009/01/04 00:21:36 adrianp Exp $
#
# PROVIDE: lwresd
# REQUIRE: SERVERS

. /etc/rc.subr

name="lwresd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

extra_commands="reload"

load_rc_config ${name}		# check /etc/rc.conf.d/named9
run_rc_command "$1"
