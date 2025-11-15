#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sndio.sh,v 1.1 2025/11/15 21:38:42 vins Exp $
#
# PROVIDE: sndio
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="sndio"
rcvar=${name}
command="@PREFIX@/bin/sndiod"
command_args="-dd"
pidfile="@VARBASE@/run/sndio/pid"
logfile="@VARBASE@/run/sndio/log"
start_precmd=sndio_prestart
start_cmd=sndio_start
stop_cmd=":"

sndio_prestart() {
	dir="@VARBASE@/run/sndio"
	if [ ! -d "$dir" ]; then
		@MKDIR@ -p $dir
		@CHMOD@ 0755 $dir
		@CHOWN@ _sndio:_sndio $dir
	fi
}

sndio_start()
{
	echo "Starting sndio server"
	daemonize="@PREFIX@/sbin/daemonize"
	if [ -x "$daemonize" ]; then
		$daemonize -p ${pidfile} -e ${logfile} \
			${command} ${command_args} ${sndio_flags}
	else
		${command} ${command_args} ${sndio_flags}
	fi
}

load_rc_config ${name}
run_rc_command "$1"
