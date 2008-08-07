#!/bin/sh
#
# $NetBSD: xenbackendd.sh,v 1.1.1.1 2008/08/07 20:26:58 cegger Exp $
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
