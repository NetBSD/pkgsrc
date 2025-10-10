#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: innd.sh,v 1.19 2025/10/10 16:02:16 hauke Exp $
#
# PROVIDE: inn
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f @SYSCONFBASE@/rc.subr ]
then
  . @SYSCONFBASE@/rc.subr
fi

name="inn"
rcvar=${name}
command="@INN_PATHBIN@/rc.news"
procname="@INN_PATHBIN@/innwatch"
command_interpreter="@RCD_SCRIPTS_SHELL@"
inn_user="news"
required_files="@INN_PATHBIN@/rc.news @INN_DATA_DIR@/db/active"
pidfile="@INN_DATA_DIR@/run/innwatch.pid"

start_precmd="inn_precmd"
start_cmd="inn_start"
stop_cmd="inn_stop"


if [ -f @SYSCONFBASE@/rc.subr -a -d @SYSCONFBASE@/rc.d -a -f @SYSCONFBASE@/rc.d/DAEMON ]
then
        load_rc_config ${name}
elif [ -f @SYSCONFBASE@/rc.conf ]
then
        . @SYSCONFBASE@/rc.conf
fi

inn_precmd()
{
	if [ -f @INN_DATA_DIR@/db/history -a \
		! -s @INN_DATA_DIR@/db/history ]
	then
		@INN_PATHBIN@/makedbz -i -o -s 10000
	fi
}

inn_start()
{
        @ECHO@ "Starting ${name}."
        doit="@SU@ -m ${inn_user} -c '${command} start ${command_args} >/dev/null'"
        eval $doit
}

inn_stop()
{
        @ECHO@ "Stopping ${name}."
        doit="@SU@ -m ${inn_user} -c '${command} stop ${command_args} >/dev/null'"
        eval $doit
}

run_rc_command "$1"
