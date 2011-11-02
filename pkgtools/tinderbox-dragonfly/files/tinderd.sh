#!/bin/sh
#
# $MCom: portstools/tinderbox/etc/rc.d/tinderd,v 1.7.2.2 2011/05/23 15:05:31 marcus Exp $
#

# PROVIDE: tinderd
# REQUIRE: LOGIN mysqld pgsql
# KEYWORD: shutdown

# Add the following line to /etc/rc.conf to enable `tinderd':
#
#tinderd_enable="YES"
#

. /etc/rc.subr

name="tinderd"
rcvar=`set_rcvar`

# read settings, set default values
load_rc_config "${name}"
: ${tinderd_enable="NO"}
: ${tinderd_directory="/usr/pkg/tinderbox/scripts"}
: ${tinderd_flags=""}
: ${tinderd_debug="NO"}

# path to your executable, might be libexec, bin, sbin, ...
command="${tinderd_directory}/tinderd"

# needed when your daemon is a shell script
command_interpreter="/bin/sh"

# extra required arguments
if checkyesno tinderd_debug
then
    command_args=" &"
else
    command_args=">/dev/null 2>&1 &"
fi

run_rc_command "$1"
