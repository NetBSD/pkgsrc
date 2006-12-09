#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pgsql.sh,v 1.1.1.1 2006/12/09 15:34:40 adam Exp $
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
# The following variables are optional:
#
#	pgsql_flags="-i"		# allows TCP/IP connections
#	pgsql_flags="-i -l"		# enables SSL connections
#	pgsql_home="/path/to/home"	# path to pgsql database directory
#
# "pgsql_flags" contains options for the PostgreSQL postmaster.  See
# postmaster(1) for possible options.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="pgsql"
rcvar=$name
pgsql_user="@PGUSER@"
pgsql_group="@PGGROUP@"
eval pgsql_home="~$pgsql_user"

command="@PG_PREFIX@/bin/postmaster"
ctl_command="@PG_PREFIX@/bin/pg_ctl"
extra_commands="initdb"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

pidfile="${pgsql_home}/data/postmaster.pid"
common_args="-D ${pgsql_home}/data -m fast"
start_command_args="-w -s -l ${pgsql_home}/errlog"
stop_command_args="-s"

initdb_cmd="pgsql_initdb"
start_precmd="pgsql_precmd"
start_cmd="pgsql_doit start"
restart_cmd="pgsql_doit restart"
stop_cmd="pgsql_doit stop"

ulimit -n 4096

pgsql_precmd()
{
	if [ ! -d ${pgsql_home}/data/base ]; then
		pgsql_initdb
	fi
}

pgsql_initdb()
{
	initdb="@PG_PREFIX@/bin/initdb"

	if [ ! -x ${initdb} ]; then
		return 1
	fi
	if [ -d ${pgsql_home}/data/base ]; then
		@ECHO@ "The PostgreSQL template databases have already been initialized."
		@ECHO@ "Skipping database initialization."
	else
		@ECHO@ "Initializing PostgreSQL databases."
		@MKDIR@ -p ${pgsql_home}
		@CHOWN@ ${pgsql_user} ${pgsql_home}
		@CHGRP@ ${pgsql_group} ${pgsql_home}
		@CHMOD@ 0750 ${pgsql_home}
		common_args_without_m=$(echo "${common_args}" |\
		    sed -e 's/-m [a-z]*//')
		eval doit_command=\"${initdb} ${common_args_without_m} ${flags}\"
		doit="@SU@ -m ${pgsql_user} -c '${doit_command}'"
		eval $doit
	fi
}

pgsql_doit()
{
	action=$1

	case ${action} in
	start|restart)
		if [ -n "${pgsql_flags}" ]; then
			start_command_args="${start_command_args} -o \\\"${pgsql_flags}\\\""
		fi
		command_args="${common_args} ${start_command_args} ${command_args}"
		;;
	stop)
		command_args="${common_args} ${stop_command_args} ${command_args}"
		;;
	*)
		command_args="${common_args} ${command_args}"
		;;
	esac

	if [ ! -x ${ctl_command} ]; then
		return
	fi

	case ${action} in
	start)		@ECHO@ "Starting ${name}." ;;
	stop)		@ECHO@ "Stopping ${name}." ;;
	restart)	@ECHO@ "Restarting ${name}." ;;
	esac

	eval doit_command=\"${ctl_command} ${action} ${command_args}\"
	doit="@SU@ -m ${pgsql_user} -c '${doit_command}'"
	eval $doit
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case "$1" in
	initdb)
		eval ${initdb_cmd}
		;;
	restart)
		eval ${restart_cmd}
		;;
	stop)
		eval ${stop_cmd}
		;;
	*)
		eval ${start_precmd}
		eval ${start_cmd}
		;;
	esac
fi
