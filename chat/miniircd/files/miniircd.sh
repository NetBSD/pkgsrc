#!@RCD_SCRIPTS_SHELL@

# PROVIDE: miniircd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="miniircd"
rcvar=$name
command="@PREFIX@/sbin/miniircd"
command_interpreter="@PYTHONBIN@"
command_args="-d"

miniircd_flags=${miniircd_flags-"--setuid @MINIIRCD_USER@:@MINIIRCD_GROUP@"}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${miniircd_flags} ${command_args} 
fi
