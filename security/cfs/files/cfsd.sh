#!/bin/sh
#
# $NetBSD: cfsd.sh,v 1.1.1.1 2001/06/05 22:19:11 jlam Exp $
#
# PROVIDE: cfsd
# REQUIRE: mountd
#
# To start cfsd at startup, copy this script to /etc/rc.d and set
# cfsd=YES in /etc/rc.conf.

name="cfsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="> /dev/null 2>&1"
required_vars="mountd"

# set defaults
if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

# $flags from environment overrides ${rcvar}_flags
if [ -n "${flags}" ]
then
	eval ${rcvar}_flags="${flags}"
fi

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

cmd=${1:-start}
case ${cmd} in
force*)
	cmd=${cmd#force}
	forcecmd=YES
	eval ${rcvar}=YES
	;;
esac

required_vars="${rcvar} ${required_vars}"
pid_cmd="ps ax | awk '{print \$1,\$5}' | grep ${name} | awk '{print \$1}'"

for _var in ${required_vars}
do
	if ! checkyesno ${_var}
	then
		if [ -z "${forcecmd}" ]
		then
			exit 1
		fi
	fi
done

if [ -x ${command} ]
then
	case ${cmd} in
	start)
		echo "Starting ${name}."
		eval ${command} ${cfs_flags} ${command_args}
		;;
	stop)
		pid=`eval ${pid_cmd}`
		if [ -z "${pid}" ]
		then
			echo "${name} not running?"
			exit 1
		fi
		echo "Stopping ${name}."
		kill ${pid}
		;;
	restart)
		( $0 forcestop )
		sleep 5
		$0 forcestart
		;;
	status)
		pid=`eval ${pid_cmd}`
		if [ -n "${pid}" ]; then
			echo "${name} is running as pid ${pid}."
		else
			echo "${name} is not running."
			exit 1
		fi
		;;
	*)
		echo 1>&2 "Usage: $0 [restart|start|stop|status]"
		exit 1
		;;
	esac
fi
