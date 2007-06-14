#!/bin/sh
#
# $NetBSD: xenbackendd.sh,v 1.1.1.1 2007/06/14 19:39:45 bouyer Exp $
#

# PROVIDE: xenbackendd
# REQUIRE: xend

$_rc_subr_loaded . /etc/rc.subr

name="xenbackendd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
