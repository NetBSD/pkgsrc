#!/bin/sh
#
# PROVIDE: bacula-sd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="baculasd"
rcvar=$name
command="@PREFIX@/sbin/bacula-sd"
required_files="@BACULA_ETCDIR@/bacula-sd.conf"
pidfile="@BACULA_PIDDIR@/bacula-sd.9103.pid"
command_args="-c ${required_files} -u @BACULA_SD_USER@ -g @BACULA_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${baculasd_flags} -c ${required_files}
fi
