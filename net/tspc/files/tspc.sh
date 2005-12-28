#!/bin/sh
#
# $NetBSD: tspc.sh,v 1.1 2005/12/28 12:10:44 ghen Exp $
#

# PROVIDE: tspc
# REQUIRE: NETWORKING

$_rc_subr_loaded . /etc/rc.subr

name="tspc"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command_args="-f @PKG_SYSCONFDIR@/${name}.conf"
start_precmd="chdir"

chdir()
{
	cd @VARBASE@/log
}

load_rc_config $name
run_rc_command "$1"
