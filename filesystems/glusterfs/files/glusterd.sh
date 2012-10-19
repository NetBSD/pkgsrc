#!/bin/sh
#
# $NetBSD: glusterd.sh,v 1.10 2012/10/19 04:15:21 manu Exp $
#

# PROVIDE: glusterd
# REQUIRE: rpcbind
# BEFORE: glusterfsd

$_rc_subr_loaded . /etc/rc.subr

glusterd_precmd()
{
	test -d @VARBASE@/lib/glusterd && return
	test -d @PREFIX@/etc/glusterd || return
	mv @PREFIX@/etc/glusterd @VARBASE@/lib/glusterd && \
	    ln -s @VARBASE@/lib/glusterd @PREFIX@/etc/glusterd
}

name="glusterd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
start_precmd="glusterd_precmd"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile}"
required_files="@PREFIX@/etc/glusterfs/${name}.vol"

load_rc_config $name
run_rc_command "$1"

