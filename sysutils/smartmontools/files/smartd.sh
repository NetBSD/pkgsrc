#!/bin/sh
#
# $NetBSD: smartd.sh,v 1.2 2004/10/20 07:22:09 xtraeme Exp $
#
# PROVIDE: smartd
# REQUIRE: DAEMON

. /etc/rc.subr

name="smartd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
smartd_flags="-p $pidfile"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
