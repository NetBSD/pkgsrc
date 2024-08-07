#!/bin/sh
#
# $NetBSD: glusterd.sh,v 1.12.78.1 2024/08/07 18:47:39 bsiegert Exp $
#

# PROVIDE: glusterd
# REQUIRE: rpcbind

$_rc_subr_loaded . /etc/rc.subr

glusterd_precmd()
{
	fatal=0

	for d in @VARBASE@/lib/glusterd @PKG_SYSCONFDIR@/glusterd ; do
		if test -d "$d" ; then
			echo "Please migrate $d to @VARBASE@/db/glusterd" >&2
			fatal=1
		fi
	done

	if [ $fatal -eq 1 ] ; then
		exit 1;
	fi
}

name="glusterd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
#start_precmd="glusterd_precmd"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile}"
required_files="@PKG_SYSCONFDIR@/glusterfs/${name}.vol"

load_rc_config $name
run_rc_command "$1"

