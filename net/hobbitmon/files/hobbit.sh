#!/bin/sh
#
# Hobbit site monitoring server
# Startup script contributed by Nathan Arthur 
#
# PROVIDE: hobbit
# REQUIRE: DAEMON

name="hobbit"

# user-settable rc.conf variables
: ${hobbit_launchcfg:="/usr/pkg/hobbit/server/etc/hobbitlaunch.cfg"}
: ${hobbit_servercfg:="/usr/pkg/hobbit/server/etc/hobbitserver.cfg"}
: ${hobbit_log:="/var/log/hobbit/hobbitlaunch.log"}
: ${hobbit_pidfile:="/var/run/${name}.pid"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
hobbit_user="hobbit"
pidfile=${hobbit_pidfile}
required_files="${hobbit_launchcfg} ${hobbit_servercfg}"
command="/usr/pkg/hobbit/server/bin/hobbitlaunch"
command_args="--config=${hobbit_launchcfg} --env=${hobbit_servercfg} --log=${hobbit_log} --pidfile=${hobbit_pidfile}"

load_rc_config $name
run_rc_command "$1"
