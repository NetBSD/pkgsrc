#!/bin/sh
#
# $NetBSD: xenbackendd.sh,v 1.1.1.1 2006/07/02 16:49:31 bouyer Exp $
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
