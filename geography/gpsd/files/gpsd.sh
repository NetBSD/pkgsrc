#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gpsd.sh,v 1.1 2022/05/20 19:52:41 khorben Exp $
#
# Interface daemon for GPS receivers
#
# PROVIDE: gpsd
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start gpsd:
#
# gpsd=YES
# gpsd_devices=		# List of devices for gpsd to monitor
#			#   this variable is required.
# gpsd_flags=		# Additional options to provide to gpsd
#			#   this variable is optional and defaults to "-n".

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="gpsd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
start_precmd="gpsd_start_precmd"

gpsd_start_precmd()
{
	rc_flags="$rc_flags ${gpsd_devices}"
}

load_rc_config $name
: ${gpsd_flags:=-n}
run_rc_command "$1"
