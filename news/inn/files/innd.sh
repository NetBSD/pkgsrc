#!/bin/sh
#
# $NetBSD: innd.sh,v 1.14 2008/06/23 09:10:53 spz Exp $
#
# PROVIDE: inn
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -x @INN_PATHBIN@/rc.news -a -s @INN_DATA_DIR@/db/active ]
then
	if [ ! -f @PREFIX@/etc/nntp/server ]
	then
		hostname >@PREFIX@/etc/nntp/server
	fi

	if [ ! -f @PREFIX@/etc/nntp/domainname ]
	then
		(set - X `grep ^fromhost: @PKG_SYSCONFDIR@/inn.conf`
		if [ $# -eq 3 ]
		then
			echo $3 >@PREFIX@/etc/nntp/domainname
		fi)
	fi

	if [ $# -eq 0 ]
	then
		echo -n ' innd'
		su news -c "@INN_PATHBIN@/rc.news start" >/dev/null
		exit 0
	fi

	case "$1" in
	start )
		echo "Starting INN."
		su news -c "@INN_PATHBIN@/rc.news $1" >/dev/null
		exit 0
		;;
	stop )
		su news -c "@INN_PATHBIN@/rc.news $1"
		exit 0
		;;
	restart )
		$0 stop
		sleep 5
		exec $0 start
		;;
	* )
		echo "Usage: $0 (start|stop|restart)"
		exit 1
		;;
	esac
fi

exit 0
