#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pppoe.sh,v 1.3 2003/01/23 01:35:51 simonb Exp $
#
# PROVIDE: pppoe
# REQUIRE: ipnat

test -f /etc/ppp/pppoe.conf || exit 1
CONFIG=/etc/ppp/pppoe.conf

case $1 in
start)
	. /etc/ppp/pppoe.conf 
	ifconfig $ETH up
	@PREFIX@/sbin/adsl-start
	;;
stop)
	@PREFIX@/sbin/adsl-stop
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
