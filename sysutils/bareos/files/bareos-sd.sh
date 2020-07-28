#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: bareos-sd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bareossd"
rcvar=$name
command="@PREFIX@/sbin/bareos-sd"
required_dirs="@BAREOS_ETCDIR@/bareos-sd.d"
pidfile="@BAREOS_PIDDIR@/bareos-sd.9103.pid"
command_args="-u @BAREOS_SD_USER@ -g @BAREOS_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareossd_flags} -c ${required_files}
fi
