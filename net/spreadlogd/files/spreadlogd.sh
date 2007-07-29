#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: spreadlogd
# REQUIRE: DAEMON
#
# To start spreadlogd at startup, copy this script to /etc/rc.d and set
# spreadlogd=YES in /etc/rc.conf.
#
# Addtionally you may set spread_log to a file where to log stuff.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="spreadlogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
sig_stop=INT

required_files="@PKG_SYSCONFDIR@/spreadlogd.conf"

command_args=""

load_rc_config $name
run_rc_command "$1"
