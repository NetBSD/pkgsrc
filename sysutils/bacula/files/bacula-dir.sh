#!/bin/sh
#
# PROVIDE: bacula-dir
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="baculadir"
rcvar=$name
command="@PREFIX@/sbin/bacula-dir"
required_files="@BACULA_ETCDIR@/bacula-dir.conf"
pidfile="@BACULA_PIDDIR@/bacula-dir.9101.pid"
command_args="-c ${required_files} -u @BACULA_DIR_USER@ -g @BACULA_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${baculadir_flags} -c ${required_files}
fi
