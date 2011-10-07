#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: innd.sh,v 1.18 2011/10/07 22:37:05 shattered Exp $
#
# PROVIDE: inn
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -d @INN_DATA_DIR@/etc ] ; then
	echo ""
	echo "WARNING WARNING WARNING WARNING WARNING WARNING WARNING"
	echo ""
	echo "WARNING: old inn config directory @INN_DATA_DIR@/etc found"
	echo "WARNING: please move your config to @PREFIX@/etc/inn"
	echo "WARNING: before starting your new inn install"
	echo ""
	echo "WARNING WARNING WARNING WARNING WARNING WARNING WARNING"
	echo ""
	sleep 120
fi

if [ -x @INN_PATHBIN@/rc.news -a -s @INN_DATA_DIR@/db/active ]
then
	if [ ! -d @PREFIX@/etc/nntp ]
	then
		mkdir @PREFIX@/etc/nntp
	fi

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

	if [ -f @INN_DATA_DIR@/db/history -a \
		! -s @INN_DATA_DIR@/db/history ]
	then
		@INN_PATHBIN@/makedbz -i -o -s 10000
	fi

	if [ $# -eq 0 ]
	then
		echo -n ' innd'
		su -m news -c "@INN_PATHBIN@/rc.news start" >/dev/null
		exit 0
	fi

	case "$1" in
	start )
		echo "Starting INN."
		su -m news -c "@INN_PATHBIN@/rc.news $1" >/dev/null
		exit 0
		;;
	stop )
		su -m news -c "@INN_PATHBIN@/rc.news $1"
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
