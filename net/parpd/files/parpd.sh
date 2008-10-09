#!/bin/sh
#
# $NetBSD: parpd.sh,v 1.1.1.1 2008/10/09 00:24:28 joerg Exp $
#

# PROVIDE: parpd
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="parpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
