#!@RCD_SCRIPTS_SHELL@

# PROVIDE: bitlbee
# REQUIRE: DAEMON

. /etc/rc.subr

name="bitlbee"
rcvar=$name
command="@PREFIX@/sbin/bitlbee"
pidfile="@VARBASE@/run/${name}/pid"
command_args="-D"	# run as a daemon

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${bitlbee_flags} ${command_args}
fi
