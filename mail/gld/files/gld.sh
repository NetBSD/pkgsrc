#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gld.sh,v 1.2 2004/11/29 15:46:25 xtraeme Exp $
#

# PROVIDE: gld
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="gld"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
pidfile="@VARBASE@/run/${name}.pid"

if [ "$1" != "stop" ]; then
	echo $(check_process $command) > $pidfile
fi

load_rc_config $name
run_rc_command "$1"
