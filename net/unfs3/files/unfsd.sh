#!@RCD_SCRIPTS_SHELL@
#
# 	$NetBSD: unfsd.sh,v 1.1 2008/01/30 09:39:13 tnn Exp $
#
# PROVIDE: unfsd
# REQUIRE: DAEMON rpcbind

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="unfsd"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
command_args="-i ${pidfile}"

load_rc_config $name
load_rc_config_var rpcbind rpcbind
run_rc_command "$1"
