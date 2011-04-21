#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: omninames.sh,v 1.2 2011/04/21 16:34:18 drochner Exp $
#
# omniORB NameService rc.d control script
#
# PROVIDE: omninames
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start omniNames:
#
# omniNames=YES
#
# The following variables are optional:
#
#	omniNames_flags="-start 423"	# Listen on a different port
#
# "omniNames_flags" contains options for the omniNames service.  See
# omniNames(1) for possible options.

$_rc_subr_loaded . /etc/rc.subr

name="omniNames"
rcvar=$name
command="@PREFIX@/bin/${name}"
logdir="/var/db"
errlogfile="/var/log/${name}.log"
command_args="-start -always -logdir ${logdir} -errlog ${errlogfile} &"

load_rc_config $name
run_rc_command "$1"
