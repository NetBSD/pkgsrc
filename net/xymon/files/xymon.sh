#!@RCD_SCRIPTS_SHELL@
#
# Xymon site monitoring server
# Startup script contributed by Nathan Arthur (originally for hobbitmon)
#
# PROVIDE: xymon
# REQUIRE: DAEMON xymonclient

name="xymon"

# user-settable rc.conf variables
: ${xymon_launchcfg:="@XYETCDIR@/tasks.cfg"}
: ${xymon_servercfg:="@XYETCDIR@/xymonserver.cfg"}
: ${xymon_log:="@XYMONLOGDIR@/xymonlaunch.log"}
: ${xymon_pidfile:="/var/run/${name}.pid"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
xymon_user="xymon"
pidfile=${xymon_pidfile}
required_files="${xymon_launchcfg} ${xymon_servercfg}"
command="@XYBINDIR@/xymonlaunch"
command_args="--config=${xymon_launchcfg} --env=${xymon_servercfg} --log=${xymon_log} --pidfile=${xymon_pidfile}"

xymon_precmd()
{
	XYMONHOME="@XYMONHOME@"
        export XYMONHOME
	XYMONCLIENTHOME="@XYMONHOME@/client"
        export XYMONCLIENTHOME

	touch ${xymon_pidfile} && chown ${xymon_user} ${xymon_pidfile}
}

start_precmd="xymon_precmd"

load_rc_config $name
run_rc_command "$1"
