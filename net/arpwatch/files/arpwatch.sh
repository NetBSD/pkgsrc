#!@RCD_SCRIPTS_SHELL@
#
# $id$
#

# PROVIDE: arpwatch 
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="arpwatch"
rcvar=$name
command="/usr/pkg/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
