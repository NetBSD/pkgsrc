#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pppoe.sh,v 1.4 2007/09/29 21:46:33 bad Exp $
#
# PROVIDE: pppoe
# REQUIRE: ipnat

test -f /etc/ppp/pppoe.conf || exit 1
CONFIG=/etc/ppp/pppoe.conf

case $1 in
start)
	. /etc/ppp/pppoe.conf 
	ifconfig $ETH up
	@PREFIX@/sbin/pppoe-start
	;;
stop)
	@PREFIX@/sbin/pppoe-stop
	. /etc/ppp/pppoe.conf 
	ifconfig $ETH down
	;;
restart)
	sh $0 stop
	sleep 5
	sh $0 start
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac
