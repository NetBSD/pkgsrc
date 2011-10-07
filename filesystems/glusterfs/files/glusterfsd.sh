#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: glusterfsd.sh,v 1.8 2011/10/07 22:37:03 shattered Exp $
#

# PROVIDE: glusterfsd
# REQUIRE: rpcbind

$_rc_subr_loaded . /etc/rc.subr

name="glusterfsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile}"
required_files="@PREFIX@/etc/glusterfs/${name}.vol"

load_rc_config $name
run_rc_command "$1" 
