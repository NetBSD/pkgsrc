#!@SMF_METHOD_SHELL@
#
# $NetBSD: isc-dhcpd.sh,v 1.1 2014/03/12 14:29:31 jperkin Exp $
#
# Init script for isc-dhcpd.
#

case "$1" in
start)
	if [ ! -d @DHCP_HOME@ ]; then
		mkdir -p @DHCP_HOME@
		touch @DHCP_HOME@/dhcpd.leases
		chmod 0640 @DHCP_HOME@/dhcpd.leases
	fi
	mkdir -p @DHCP_PID@
	chmod 0770 @DHCP_PID@
	@PREFIX@/sbin/dhcpd
	;;
stop)
	if [ -s @DHCP_PID@/isc-dhcpd.pid ]; then
		kill `cat @DHCP_PID@/isc-dhcpd.pid`
	fi
	;;
refresh)
	$0 stop
	$0 start
	;;
esac
