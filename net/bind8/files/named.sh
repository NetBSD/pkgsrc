#!/bin/sh
#
# $NetBSD: named.sh,v 1.1 2001/12/24 14:10:54 abs Exp $
#
# PROVIDE: named
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# To start named at startup, copy this script to /etc/rc.d and set
# named=YES in /etc/rc.conf.

name="named"
rcvar=$name
command="@PREFIX@/sbin/ndc"

named_start=start

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

named_doit()
{
	action=$1

	case ${action} in
	start)		echo -n "Starting ${name}: "; action=${named_start} ;;
	stop)		echo "Stopping ${name}" ;;
	restart)	echo -n "Restarting ${name}: " ;;
	esac

	${command} ${named_flags} ${command_args} ${action}
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
		restart|start|stop|reload)
			${rcvar}_doit ${cmd}
			;;
		*)
			echo 1>&2 "Usage: $0 [restart|start|stop|reload]"
			exit 1
			;;
		esac
	fi
fi
