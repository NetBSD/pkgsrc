#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: phd.sh,v 1.1 2016/03/04 10:56:17 youri Exp $
#
# Phabricator rc.d control script
#
# PROVIDE: phd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start Phabricator:
#
# phd=YES

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="phd"
rcvar=${name}
command="@PREFIX@/share/phabricator/bin/phd"
extra_commands="reload status list log"

start_cmd="phd_start"
restart_cmd="phd_restart"
stop_cmd="phd_stop"
reload_cmd="phd_reload"
status_cmd="phd_status"
list_cmd="phd_list"
log_cmd="phd_log"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

phd_start()
{
	@ECHO@ "Starting ${name}."
	${command} start
}

phd_restart()
{
	@ECHO@ "Restarting ${name}."
	${command} restart
}

phd_stop()
{
	@ECHO@ "Stopping ${name}."
	${command} stop
}

phd_reload()
{
	@ECHO@ "Reloading ${name}."
	${command} reload
}

phd_status()
{
	${command} status
}

phd_list()
{
	${command} list
}

phd_log()
{
	${command} log
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	run_rc_command "$1"
else
	case "$1" in
	restart)
		eval ${restart_cmd}
		;;
	stop)
		eval ${stop_cmd}
		;;
	reload)
		eval ${reload_cmd}
		;;
	status)
		eval ${status_cmd}
		;;
	list)
		eval ${list_cmd}
		;;
	log)
		eval ${log_cmd}
		;;
	*)
		eval ${start_cmd}
		;;
	esac
fi
