#!/bin/sh
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
: ${xymon_clientcfg:="@XYETCDIR@/hobbitclient.cfg"}
: ${xymon_log:="@BBLOGDIR@/clientlaunch.log"}
: ${xymon_pidfile:="/var/run/xymonclient.pid"}

rcvar=${name}
xymon_user="xymon"
pidfile=${xymon_pidfile}
required_files="${xymon_launchcfg} ${xymon_clientcfg}"
command="@XYBINDIR@/client/hobbitlaunch"
command_args="--config=${xymon_launchcfg} --env=${xymon_clientcfg} --log=${xymon_log} --pidfile=${xymon_pidfile}"

xymon_precmd()
{
	HOBBITCLIENTHOME="@BBHOME@/client"
	export HOBBITCLIENTHOME
	if [ ! -h $HOBBITCLIENTHOME/bin ]; then
		ln -s @XYBINDIR@/client $HOBBITCLIENTHOME/bin
	fi
	if [ ! -h $HOBBITCLIENTHOME/etc ]; then
		ln -s @XYETCDIR@ $HOBBITCLIENTHOME/etc
	fi
	if [ ! -h $HOBBITCLIENTHOME/ext ]; then
		ln -s @XYEXTDIR@/client $HOBBITCLIENTHOME/ext
	fi
	if [ ! -h $HOBBITCLIENTHOME/tmp ]; then
		ln -s @XYTMPDIR@/client $HOBBITCLIENTHOME/tmp
	fi
	if [ ! -h $HOBBITCLIENTHOME/logs ]; then
		ln -s @BBLOGDIR@ $HOBBITCLIENTHOME/logs
	fi
}

start_precmd="xymon_precmd"

load_rc_config $name
run_rc_command "$1"
