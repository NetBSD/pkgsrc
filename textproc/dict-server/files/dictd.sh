#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dictd.sh,v 1.1 2009/12/30 11:55:49 abs Exp $
#
# PROVIDE: dictd
# REQUIRE: LOGIN

. /etc/rc.subr

name="dictd"
unload_cmd="dictd_unload"
load_cmd="dictd_load"
dictd_flags=${dictd_flags-"--pp '@PATH_TO_M4@ -P'"}
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dictd.conf"
extra_commands="reload unload load"

dictd_load (){
    echo "Loading dictd databases."
    kill -HUP $(check_pidfile $pidfile $name)
}

dictd_unload (){
    echo "Unloading dictd databases."
    kill -USR1 $(check_pidfile $pidfile $name)
}

load_rc_config $name
run_rc_command "$1"
