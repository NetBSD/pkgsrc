#!/bin/sh
#
# $NetBSD: pgsql.sh,v 1.1.1.1 2001/05/14 14:50:26 jlam Exp $
#
# PostgreSQL database rc.d control script
#
# PROVIDE: pgsql
# REQUIRE: DAEMON
# KEYWORD: shutdown

name="pgsql"
rcvar=$name
pgsql_user="@PGUSER@"
command="@PREFIX@/bin/pg_ctl"
command_args="-s -D @PGHOME@/data -l @PGHOME@/errlog"

# pgsql_flags contains options for the PostgreSQL postmaster.
# See postmaster(1) for possible options.
#
#pgsql_flags="-i"	# allows TCP/IP connections
#pgsql_flags="-i -l"	# enables SSL connections (TCP/IP required)

pgsql_doit()
{
	action=$1
	if [ -n "${pgsql_flags}" ]
	then
		command_args="${command_args} -o \"${pgsql_flags}\""
	fi

	case ${action} in
	start)		echo "Starting ${name}." ;;
	stop)		echo "Stopping ${name}." ;;
	restart)	echo "Restarting ${name}." ;;
	esac

	@SU@ -m ${pgsql_user} -c "${command} ${command_args} ${action}"
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

if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

if checkyesno ${rcvar}
then
	cmd=${1:-start}

	if [ -x ${command} ]
	then
		case ${cmd} in
		restart|start|stop|status)
			${rcvar}_doit ${cmd}
			;;
		*)
			echo 1>&2 "Usage: $0 [restart|start|stop|status]"
			exit 1
			;;
		esac
	fi
fi
