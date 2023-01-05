#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: transmission
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="transmission"
rcvar=${name}
pidfile="@VARBASE@/run/transmission/pid"
transmission_file_path="@VARBASE@/db/transmission"
command="@PREFIX@/bin/transmission-daemon"
command_args="--pid-file ${pidfile}"
command_args="${command_args} --logfile @VARBASE@/log/transmission/log"
command_args="${command_args} --config-dir @PKG_SYSCONFDIR@/transmission"
command_args="${command_args} --download-dir ${transmission_file_path}/complete"
command_args="${command_args} --incomplete-dir ${transmission_file_path}/incomplete"
command_args="${command_args} --watch-dir ${transmission_file_path}/torrents"
start_precmd="transmission_precmd"
transmission_user="@TRANSMISSION_USER@"
transmission_group="@TRANSMISSION_GROUP@"

transmission_precmd()
{
	if [ ! -d "@VARBASE@/run/transmission" ]; then
		mkdir -p -m 755 "@VARBASE@/run/transmission"
		chown @TRANSMISSION_USER@:@TRANSMISSION_GROUP@ \
			"@VARBASE@/run/transmission"
	fi
	if [ ! -d "${transmission_file_path}/complete" ]; then
		mkdir -p -m 755 "${transmission_file_path}/complete"
		chown @TRANSMISSION_USER@:@TRANSMISSION_GROUP@ \
			"${transmission_file_path}/complete"
	fi
	if [ ! -d "${transmission_file_path}/incomplete" ]; then
		mkdir -p -m 755 "${transmission_file_path}/incomplete"
		chown @TRANSMISSION_USER@:@TRANSMISSION_GROUP@ \
			"${transmission_file_path}/incomplete"
	fi
	if [ ! -d "${transmission_file_path}/torrents" ]; then
		mkdir -p -m 755 "${transmission_file_path}/torrents"
		chown @TRANSMISSION_USER@:@TRANSMISSION_GROUP@ \
			"${transmission_file_path}/torrents"
	fi
}

load_rc_config $name
run_rc_command "$1"
