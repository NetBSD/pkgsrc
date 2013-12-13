#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhcpd6.sh,v 1.1 2013/12/13 16:34:17 jakllsch Exp $
#

# PROVIDE: dhcpd6
# REQUIRE: DAEMON
# BEFORE:  LOGIN

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="isc_dhcpd6"
rcvar="${name}"
command="@PREFIX@/sbin/dhcpd"
command_args="-6 -cf @PKG_SYSCONFDIR@/dhcpd6.conf"
pidfile="@VARBASE@/run/isc-dhcp/isc-dhcpd6.pid"
required_files="@PKG_SYSCONFDIR@/dhcpd6.conf"
start_precmd="isc_dhcpd_precmd"

isc_dhcpd_precmd()
{
	if [ ! -d @VARBASE@/run/isc-dhcp ]; then
		@MKDIR@ @VARBASE@/run/isc-dhcp
		@CHMOD@ 0770 @VARBASE@/run/isc-dhcp
	fi

	if [ ! -f @DHCP_HOME@/dhcpd6.leases ]; then
		@MKDIR@ @DHCP_HOME@
		@TOUCH@ @DHCP_HOME@/dhcpd6.leases
		@CHMOD@ 0640 @DHCP_HOME@/dhcpd6.leases
	fi
}

load_rc_config $rcvar
run_rc_command "$1"
