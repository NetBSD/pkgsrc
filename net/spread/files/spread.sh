#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spread.sh,v 1.1 2003/02/22 23:37:14 mjl Exp $
#
# PROVIDE: spread
# REQUIRE: DAEMON
#
# To start spread at startup, copy this script to /etc/rc.d and set
# spread=YES in /etc/rc.conf.
#
# Addtionally you may set spread_log to a file where to log stuff.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="spread"
rcvar=$name
command="@PREFIX@/sbin/${name}"
if [ X"${spread_log}" != "X" ] ; then
   log=">${spread_log} 2>&1"
else
   log=">/dev/null 2>&1"
fi
required_files="@PKG_SYSCONFDIR@/spread.conf"

command_args="${log} </dev/null &"

load_rc_config $name
run_rc_command "$1"
