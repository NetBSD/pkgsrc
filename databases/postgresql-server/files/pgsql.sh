#!/bin/sh
#
# $NetBSD: pgsql.sh,v 1.10 2002/07/18 01:40:07 cjs Exp $
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
#	pgsql_flags="-i"	# allows TCP/IP connections
#	pgsql_flags="-i -l"	# enables SSL connections (TCP/IP required)
#
# "pgsql_flags" contains options for the PostgreSQL postmaster.  See
# postmaster(1) for possible options.

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="pgsql"
rcvar=$name
pgsql_user="@PGUSER@"
eval PGHOME="~$pgsql_user"

command="@PREFIX@/bin/postmaster"
ctl_command="@PREFIX@/bin/pg_ctl"
pidfile="${PGHOME}/data/postmaster.pid"
extra_commands="initdb"

command_args="-D ${PGHOME}/data"
start_command_args="-w -s -l ${PGHOME}/errlog"
stop_command_args="-s -m fast"

initdb_cmd="pgsql_initdb"
start_precmd="pgsql_precmd"
start_cmd="pgsql_doit start"
restart_cmd="pgsql_doit restart"
stop_cmd="pgsql_doit stop"

pgsql_precmd()
{
	if [ ! -f ${PGHOME}/data/base/1/PG_VERSION ]
	then
		$rcd_dir/pgsql initdb
	fi
}

pgsql_initdb()
{
	initdb="@PREFIX@/bin/initdb"

	if [ ! -x ${initdb} ]
	then
		return
	fi
	if [ -f ${PGHOME}/data/base/1/PG_VERSION ]
	then
		@ECHO@ "The PostgreSQL template databases have already been initialized."
		@ECHO@ "Skipping database initialization."
	else
		@ECHO@ "Initializing PostgreSQL databases."
		@SU@ -m ${pgsql_user} -c "${initdb} ${command_args} ${flags}"
	fi
}

pgsql_doit()
{
	action=$1

	case ${action} in
	start|restart)
		command_args="${command_args} ${start_command_args}"
		if [ -n "${pgsql_flags}" ]
		then
			command_args="${command_args} -o \"${pgsql_flags}\""
		fi
		;;
	stop)
		command_args="${command_args} ${stop_command_args}"
		;;
	esac

	if [ ! -x ${ctl_command} ]
	then
		return
	fi

	case ${action} in
	start)		@ECHO@ "Starting ${name}." ;;
	stop)		@ECHO@ "Stopping ${name}." ;;
	restart)	@ECHO@ "Restarting ${name}." ;;
	esac

	@SU@ -m ${pgsql_user} -c "${ctl_command} ${action} ${command_args}"
}

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]
	then
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
