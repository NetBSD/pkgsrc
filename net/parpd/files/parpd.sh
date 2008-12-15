#!/bin/sh
#
# $NetBSD: parpd.sh,v 1.1.1.2 2008/12/15 15:55:42 roy Exp $
#

# PROVIDE: parpd
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="parpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PREFIX@/etc/${name}.conf"

load_rc_config $name
run_rc_command "$1"
