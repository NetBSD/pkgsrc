#!/bin/sh
#
# $NetBSD: courier-imap.sh,v 1.1.1.1 2001/07/31 22:48:51 jlam Exp $
#
# PROVIDE: courier
# REQUIRE: DAEMON
#
# To start courier-imap at startup, copy this script to /etc/rc.d and set
# courier=YES in /etc/rc.conf.

name="courier"
rcvar=$name
command="@PREFIX@/sbin/apachectl"

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
	eval ${rcvar}=YES
	;;
esac

if checkyesno ${rcvar}
then
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

prefix=/usr/pkg
exec_prefix=${prefix}

case "$1" in
start)
        cd /
	. ${prefix}/etc/imapd

	echo -n "Starting Courier-IMAP server:"

	case x$IMAPDSTART in
	x[yY]*)
		# Start daemons.
		${exec_prefix}/libexec/imapd.rc start
		echo -n " imap"
		;;
	esac

	. ${prefix}/etc/imapd-ssl
	case x$IMAPDSSLSTART in
	x[yY]*)
		if test -x $COURIERTLS
		then

		# First time we start this, generate a dummy SSL certificate.

			if test ! -f ${prefix}/share/imapd.pem
			then
				echo -n " generating-SSL-certificate..."
				${prefix}/share/mkimapdcert >/dev/null 2>&1
			fi
			${exec_prefix}/libexec/imapd-ssl.rc start
			echo -n " imap-ssl"
		fi
		;;
	esac

	POP3DSTART=""
	POP3DSSLSTART=""

	if test -f ${prefix}/etc/pop3d
	then
		. ${prefix}/etc/pop3d
	fi

	case x$POP3DSTART in
	x[yY]*)
		# Start daemons.
		${exec_prefix}/libexec/pop3d.rc start
		echo -n " pop3"
		;;
	esac

	if test -f ${prefix}/etc/pop3d-ssl
	then
		. ${prefix}/etc/pop3d-ssl
	fi

	case x$POP3DSSLSTART in
	x[yY]*)
		if test -x $COURIERTLS
		then

		# First time we start this, generate a dummy SSL certificate.

			if test ! -f ${prefix}/share/pop3d.pem
			then
				echo -n " generating-SSL-certificate..."
				${prefix}/share/mkpop3dcert >/dev/null 2>&1
			fi
			${exec_prefix}/libexec/pop3d-ssl.rc start
			echo -n " pop3-ssl"
		fi
		;;
	esac

	echo ""
	;;
stop)
        echo -n "Stopping Courier-IMAP server:"
	. ${prefix}/etc/imapd
	. ${prefix}/etc/imapd-ssl
	${exec_prefix}/libexec/imapd.rc stop
	echo -n " imap"
	if test -x $COURIERTLS
	then
		${exec_prefix}/libexec/imapd-ssl.rc stop
		echo -n " imap-ssl"
	fi

	if test -f ${prefix}/etc/pop3d
	then
		${exec_prefix}/libexec/pop3d.rc stop
		echo -n " pop3"

		if test -x $COURIERTLS
		then
			${exec_prefix}/libexec/pop3d-ssl.rc stop
			echo -n " pop3-ssl"
		fi
	fi

	echo ""
	;;
restart)
	$0 stop
	$0 start
        ;;
esac
exit 0
