#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhclient.sh,v 1.1.1.1 2007/12/12 20:02:08 adrianp Exp $
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
rcvar="isc_dhclient"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/isc-dhcp/${name}.pid"
start_precmd="isc_dhclient_precmd"

isc_dhclient_precmd()
{
	if [ ! -d @VARBASE@/run/isc-dhcp ]; then
		@MKDIR@ @VARBASE@/run/isc-dhcp
		@CHMOD@ 0770 @VARBASE@/run/isc-dhcp
	fi
}

load_rc_config $name
run_rc_command "$1"
