#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gld.sh,v 1.3 2004/11/29 16:17:22 xtraeme Exp $
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

if [ "$1" != "stop" -o "$1" != "status" ]; then
	echo $(check_process $command) > $pidfile
fi

load_rc_config $name
run_rc_command "$1"
