#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhcrelay.sh,v 1.1.1.1 2007/12/12 20:02:08 adrianp Exp $
#

# PROVIDE: dhcrelay
# REQUIRE: DAEMON
# BEFORE:  NETWORKING
#
#	Note that there no syslog logging of dhclient messages at boot because
#	dhclient needs to start before services that syslog depends upon do.
#

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhcrelay"
rcvar="isc_dhcrelay"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/isc-dhcp/${name}.pid"
start_precmd="isc_dhcrelay_precmd"

isc_dhcrelay_precmd()
{
	if [ ! -d @VARBASE@/run/isc-dhcp ]; then
		@MKDIR@ @VARBASE@/run/isc-dhcp
		@CHMOD@ 0770 @VARBASE@/run/isc-dhcp
	fi
}

load_rc_config $name
run_rc_command "$1"
