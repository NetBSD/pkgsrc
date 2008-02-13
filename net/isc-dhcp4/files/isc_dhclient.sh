#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhclient.sh,v 1.1.1.1 2008/02/13 22:03:58 adrianp Exp $
#

# PROVIDE: dhclient
# REQUIRE: network mountcritlocal
# BEFORE:  NETWORKING
#
#	Note that there no syslog logging of dhclient messages at boot because
#	dhclient needs to start before services that syslog depends upon do.
#

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhclient"
rcvar="isc_${name}"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/isc-dhcp/isc-${name}.pid"
start_precmd="isc_dhclient_precmd"

isc_dhclient_precmd()
{
	if [ ! -d @VARBASE@/run/isc-dhcp ]; then
		@MKDIR@ @VARBASE@/run/isc-dhcp
		@CHMOD@ 0770 @VARBASE@/run/isc-dhcp
	fi
}

load_rc_config $rcvar
run_rc_command "$1"
