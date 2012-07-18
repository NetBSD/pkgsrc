#!@RCD_SCRIPTS_SHELL@
#
# 	$NetBSD: unfsd.sh,v 1.2 2012/07/18 20:00:45 cheusov Exp $
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
extra_commands="reload"

load_rc_config $name
load_rc_config_var rpcbind rpcbind
run_rc_command "$1"
