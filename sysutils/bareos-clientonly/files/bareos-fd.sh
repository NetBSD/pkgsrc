#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: bareos-fd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bareosfd"
rcvar=$name
command="@PREFIX@/sbin/bareos-fd"
required_dirs="@BAREOS_ETCDIR@/bareos-fd.d"
pidfile="@BAREOS_PIDDIR@/bareos-fd.9102.pid"
command_args="-g @BAREOS_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareosfd_flags} -c ${required_files}
fi
