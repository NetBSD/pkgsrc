#!@RCD_SCRIPTS_SHELL@

# PROVIDE: bitlbee
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bitlbee"
rcvar=$name
command="@PREFIX@/sbin/bitlbee"
pidfile="@VARBASE@/run/${name}/pid"
command_args="-D"	# run as a daemon
start_precmd="bitlbee_precmd"

bitlbee_precmd()
{
	if [ ! -d "@VARBASE@/run/${name}" ]; then
		@MKDIR@ "@VARBASE@/run/${name}"
		@CHMOD@ 0700 "@VARBASE@/run/${name}"
		@CHOWN@ @BITLBEE_USER@:@BITLBEE_GROUP@ "@VARBASE@/run/${name}"
	fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${bitlbee_flags} ${command_args}
fi
