#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: icecast.sh,v 1.1.1.1 2004/01/08 20:48:46 xtraeme Exp $
#
# PROVIDE: icecast
# REQUIRE: DAEMON LOGIN network


name="icecast"
command="@PREFIX@/bin/${name}"
mainconfigfile="@PKG_SYSCONFDIR@/${name}.conf"
icecast_flags="-c ${mainconfigfile} -d @PKG_SYSCONFDIR@ -b"
sig_stop="KILL"


. /etc/rc.subr


pidfile="/var/run/${name}.pid"
required_files="${mainconfigfile}"


load_rc_config $name
run_rc_command "$1"


if [ "$1" != "stop" ]; then
	echo $(check_process $command) > $pidfile
fi
