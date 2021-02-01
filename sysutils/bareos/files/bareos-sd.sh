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
start_precmd=make_dirs

make_dirs() {
	@MKDIR@ -m 0775 -p @BAREOS_PIDDIR@
	@CHOWN@ @BAREOS_DIR_USER@:@BAREOS_GROUP@ @BAREOS_PIDDIR@
	@MKDIR@ -m 0775 -p @BAREOS_LOGDIR@
	@CHOWN@ @BAREOS_DIR_USER@:@BAREOS_GROUP@ @BAREOS_LOGDIR@
}


if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareossd_flags} -c ${required_files}
fi
