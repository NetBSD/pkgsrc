#!/bin/sh
#
# PROVIDE: bacula-fd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="baculafd"
rcvar=$name
command="@PREFIX@/sbin/bacula-fd"
required_files="@BACULA_ETCDIR@/bacula-fd.conf"
pidfile="@BACULA_PIDDIR@/bacula-fd.9102.pid"
command_args="-c ${required_files}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${baculafd_flags} -c ${required_files}
fi
