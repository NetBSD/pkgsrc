#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pgsql.sh,v 1.1 2016/02/25 21:37:37 tnn Exp $
#
# PostgreSQL database rc.d control script
#
# PROVIDE: pgsql
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start PostgreSQL:
#
# pgsql=YES
#
# Optionally, "pgsql_flags" contains options for the PostgreSQL postmaster, e.g.
#	pgsql_flags="-i"		# allows TCP/IP connections
#	pgsql_flags="-i -l"		# enables SSL connections
#	pgsql_home="/path/to/home"	# path to pgsql database directory
# See postmaster(1) for possible options.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="pgsql"
rcvar=${name}
command="@PREFIX@/bin/pg_ctl"
procname="@PREFIX@/bin/postgres"
: ${pgsql_user:=@PGUSER@}
: ${pgsql_group:=@PGGROUP@}
: ${pgsql_home:=@PGHOME@}

extra_commands="initdb reload"
initdb_cmd="pgsql_initdb"
start_precmd="pgsql_precmd"
start_cmd="pgsql_start"
restart_precmd="pgsql_precmd"
restart_cmd="pgsql_restart"
stop_cmd="pgsql_stop"
reload_cmd="pgsql_reload"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

command_args="-w -s -D ${pgsql_home}/data -m fast -l ${pgsql_home}/errlog"
if [ -n "${pgsql_flags}" ]; then
	command_args="${command_args} -o \\\"${pgsql_flags}\\\""
fi

pgsql_precmd()
{
	ulimit -n 4096
	if [ ! -d ${pgsql_home}/data/base ]; then
		pgsql_initdb
	fi
}

pgsql_initdb()
{
	if [ -d ${pgsql_home}/data/base ]; then
		@ECHO@ "The PostgreSQL template databases have already been initialized."
		@ECHO@ "Skipping database initialization."
	else
		@ECHO@ "Initializing PostgreSQL databases."
		@MKDIR@ -p ${pgsql_home}
		@CHOWN@ ${pgsql_user} ${pgsql_home}
		@CHGRP@ ${pgsql_group} ${pgsql_home}
		@CHMOD@ 0700 ${pgsql_home}
		doit="@SU@ -m ${pgsql_user} -c '${command} init ${command_args}'"
		eval $doit
	fi
}

pgsql_start()
{
	@ECHO@ "Starting ${name}."
	doit="@SU@ -m ${pgsql_user} -c '${command} start ${command_args}'"
	eval $doit
}

pgsql_restart()
{
	@ECHO@ "Restarting ${name}."
	doit="@SU@ -m ${pgsql_user} -c '${command} restart ${command_args}'"
	eval $doit
}

pgsql_stop()
{
	@ECHO@ "Stopping ${name}."
	doit="@SU@ -m ${pgsql_user} -c '${command} stop ${command_args}'"
	eval $doit
}

pgsql_reload()
{
	@ECHO@ "Reloading ${name}."
	doit="@SU@ -m ${pgsql_user} -c '${command} reload ${command_args}'"
	eval $doit
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	run_rc_command "$1"
else
	pidfile="${pgsql_home}/data/postmaster.pid"
	case "$1" in
	initdb)
		eval ${initdb_cmd}
		;;
	restart)
		eval ${restart_precmd}
		eval ${restart_cmd}
		;;
	stop)
		if [ -r "${pidfile}" ]; then
			eval ${stop_cmd}
		fi
		;;
	reload)
		eval ${reload_cmd}
		;;
	*)
		eval ${start_precmd}
		eval ${start_cmd}
		;;
	esac
fi
