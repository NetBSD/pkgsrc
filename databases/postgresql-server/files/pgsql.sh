#!/bin/sh
#
# $NetBSD: pgsql.sh,v 1.6 2001/11/26 20:38:31 jlam Exp $
#
# PostgreSQL database rc.d control script
#
# PROVIDE: pgsql
# REQUIRE: DAEMON
# KEYWORD: shutdown

PGHOME="@PGHOME@"

name="pgsql"
rcvar=$name
pgsql_user="@PGUSER@"
command="@PREFIX@/bin/pg_ctl"
command_args="-s -D ${PGHOME}/data -l ${PGHOME}/errlog"

# pgsql_flags contains options for the PostgreSQL postmaster.
# See postmaster(1) for possible options.
#
#pgsql_flags="-i"	# allows TCP/IP connections
#pgsql_flags="-i -l"	# enables SSL connections (TCP/IP required)

# set defaults
if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

# $flags from environment overrides $pgsql_flags
if [ -n "${flags}" ]
then
	eval ${rcvar}_flags="${flags}"
fi

pgsql_doit()
{
	action=$1
	if [ -n "${pgsql_flags}" ]
	then
		command_args="${command_args} -o \"${pgsql_flags}\""
	fi

	case ${action} in
	start)		pgsql_start_precmd; echo "Starting ${name}." ;;
	stop)		echo "Stopping ${name}." ;;
	restart)	echo "Restarting ${name}." ;;
	esac

	@SU@ -m ${pgsql_user} -c "${command} ${command_args} ${action}"
}

pgsql_start_precmd()
{
	if [ ! -f ${PGHOME}/data/base/1/PG_VERSION ]
	then
		$0 forceinitdb
	fi
}

pgsql_initdb()
{
	if [ -f ${PGHOME}/data/base/1/PG_VERSION ]
	then
		echo "The PostgreSQL template databases have already been initialized."
		echo "Skipping database initialization."
	else
		echo "Initializing PostgreSQL databases."
		@SU@ -m ${pgsql_user} -c "@PREFIX@/bin/initdb -D ${PGHOME}/data $flags"
	fi
}

checkyesno()
{
	eval _value=\$${1}
	case $_value in
	[Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)	return 0 ;;
	[Nn][Oo]|[Ff][Aa][Ll][Ss][Ee]|[Oo][Ff][Ff]|0)	return 1 ;;
	*)
		echo "\$${1} is not set properly."
		return 1
		;;
	esac
}

# force commands are always executed
cmd=${1:-start}
case ${cmd} in
force*)
	cmd=${cmd#force}
	eval ${rcvar}=YES
	;;
esac

if checkyesno ${rcvar}
then
	if [ -x ${command} ]
	then
		case ${cmd} in
		initdb)
			${rcvar}_${cmd}
			;;
		restart|start|stop|status)
			${rcvar}_doit ${cmd}
			;;
		*)
			echo 1>&2 "Usage: $0 [initdb|restart|start|stop|status]"
			exit 1
			;;
		esac
	fi
fi
