#!@RCD_SCRIPTS_SHELL@
#
# Xymon site monitoring server
# Startup script contributed by Nathan Arthur (originally for hobbitmon)
#
# PROVIDE: xymonclient
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="xymonclient"

# user-settable rc.conf variables
: ${xymon_launchcfg:="@XYETCDIR@/clientlaunch.cfg"}
: ${xymon_clientcfg:="@XYETCDIR@/xymonclient.cfg"}
: ${xymon_configclass:=""}
: ${xymon_log:="@XYMONLOGDIR@/clientlaunch.log"}
: ${xymon_pidfile:="/var/run/xymonclient.pid"}

rcvar=${name}
xymonclient_user="xymon"
pidfile=${xymon_pidfile}
required_files="${xymon_launchcfg} ${xymon_clientcfg}"
command="@XYBINDIR@/client/xymonlaunch"
command_args="--config=${xymon_launchcfg} --env=${xymon_clientcfg} --log=${xymon_log} --pidfile=${xymon_pidfile}"

xymon_precmd()
{
	XYMONCLIENTHOME="@XYMONHOME@/client"
	export XYMONCLIENTHOME
	if [ ! -h $XYMONCLIENTHOME/bin ]; then
		ln -s @XYBINDIR@/client $XYMONCLIENTHOME/bin
	fi
	if [ ! -h $XYMONCLIENTHOME/etc ]; then
		ln -s @XYETCDIR@ $XYMONCLIENTHOME/etc
	fi
	if [ ! -h $XYMONCLIENTHOME/ext ]; then
		ln -s @XYEXTDIR@/client $XYMONCLIENTHOME/ext
	fi
	if [ ! -h $XYMONCLIENTHOME/tmp ]; then
		ln -s @XYTMPDIR@/client $XYMONCLIENTHOME/tmp
	fi
	if [ ! -h $XYMONCLIENTHOME/logs ]; then
		ln -s @XYMONLOGDIR@ $XYMONCLIENTHOME/logs
	fi
	touch ${xymon_pidfile} && chown ${xymonclient_user} ${xymon_pidfile}

	MACHINEDOTS="`uname -n`"
	export MACHINEDOTS
	SERVEROSTYPE="`uname -s | tr '[ABCDEFGHIJKLMNOPQRSTUVWXYZ/]' '[abcdefghijklmnopqrstuvwxyz_]'`"
	export SERVEROSTYPE
	XYMONOSSCRIPT="xymonclient-$SERVEROSTYPE.sh"
	export XYMONOSSCRIPT

	if [ -z "$xymon_configclass" ]; then
		CONFIGCLASS="$SERVEROSTYPE"
	else
		CONFIGCLASS="$xymon_configclass"
	fi
	export CONFIGCLASS
}

start_precmd="xymon_precmd"

load_rc_config $name
run_rc_command "$1"
