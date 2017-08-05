#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhcrelay.sh,v 1.2 2017/08/05 20:09:27 bsiegert Exp $
#

# PROVIDE: dhcrelay
# REQUIRE: NETWORKING
#
#	Note that there no syslog logging of dhclient messages at boot because
#	dhclient needs to start before services that syslog depends upon do.
#

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="isc_dhcrelay"
rcvar="${name}"
command="@PREFIX@/sbin/dhcrelay"
pidfile="@VARBASE@/run/isc-dhcp/isc-dhcrelay.pid"
start_precmd="isc_dhcrelay_precmd"

isc_dhcrelay_precmd()
{
	if [ ! -d @VARBASE@/run/isc-dhcp ]; then
		@MKDIR@ @VARBASE@/run/isc-dhcp
		@CHMOD@ 0770 @VARBASE@/run/isc-dhcp
	fi
}

load_rc_config $rcvar
run_rc_command "$1"
