#!/bin/sh
#
# $NetBSD: glusterd.sh,v 1.2 2011/05/19 14:54:22 manu Exp $
#

# PROVIDE: glusterd
# REQUIRE: rpcbind
# BEFORE: glusterfsd

$_rc_subr_loaded . /etc/rc.subr

name="glusterd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/glusterfs/${name}.vol"

load_rc_config $name
run_rc_command "$1"
