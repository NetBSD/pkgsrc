#!/bin/sh
#
# Xymon site monitoring server
# Startup script contributed by Nathan Arthur (originally for hobbitmon)
#
# PROVIDE: xymon
# REQUIRE: DAEMON xymonclient

name="xymon"

# user-settable rc.conf variables
: ${xymon_launchcfg:="@XYETCDIR@/hobbitlaunch.cfg"}
: ${xymon_servercfg:="@XYETCDIR@/hobbitserver.cfg"}
: ${xymon_log:="@BBLOGDIR@/hobbitlaunch.log"}
: ${xymon_pidfile:="/var/run/${name}.pid"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
xymon_user="xymon"
pidfile=${xymon_pidfile}
required_files="${xymon_launchcfg} ${xymon_servercfg}"
command="@XYBINDIR@/hobbitlaunch"
command_args="--config=${xymon_launchcfg} --env=${xymon_servercfg} --log=${xymon_log} --pidfile=${xymon_pidfile}"

xymon_precmd()
{
	HOBBITCLIENTHOME="@BBHOME@/client"
        export HOBBITCLIENTHOME

	touch ${xymon_pidfile} && chown ${xymon_user} ${xymon_pidfile}
}

start_precmd="xymon_precmd"

load_rc_config $name
run_rc_command "$1"
