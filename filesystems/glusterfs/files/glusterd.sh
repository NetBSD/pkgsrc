#!/bin/sh
#
# $NetBSD: glusterd.sh,v 1.12 2014/11/18 14:38:15 manu Exp $
#

# PROVIDE: glusterd
# REQUIRE: rpcbind

$_rc_subr_loaded . /etc/rc.subr

glusterd_precmd()
{
	fatal=0

	for d in /var/lib/glusterd /usr/pkg/etc/glusterd ; do
        	if test -d /var/lib/glusterd ; then
			echo "Please migrate $d to /var/db/glusterd" >&2
			fatal=1
		fi
	done

	if [ $fatal -eq 1 ] ; then
		exit 1;
	fi
}

name="glusterd"
rcvar=$name
command="/usr/pkg/sbin/${name}"
#start_precmd="glusterd_precmd"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile}"
required_files="/usr/pkg/etc/glusterfs/${name}.vol"

load_rc_config $name
run_rc_command "$1"

