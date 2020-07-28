#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: bareos-dir
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bareosdir"
rcvar=$name
command="@PREFIX@/sbin/bareos-dir"
required_dirs="@BAREOS_ETCDIR@/bareos-dir.d"
pidfile="@BAREOS_PIDDIR@/bareos-dir.9101.pid"
command_args="-u @BAREOS_DIR_USER@ -g @BAREOS_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareosdir_flags} -c ${required_files}
fi
