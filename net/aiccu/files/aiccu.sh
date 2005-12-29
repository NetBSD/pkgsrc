#!/bin/sh
#
# $NetBSD: aiccu.sh,v 1.1.1.1 2005/12/29 14:53:52 ghen Exp $
#

# PROVIDE: aiccu
# REQUIRE: NETWORKING

$_rc_subr_loaded . /etc/rc.subr

name="aiccu"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command_args="start"
stop_command="${command} stop"

load_rc_config $name
run_rc_command "$1"
