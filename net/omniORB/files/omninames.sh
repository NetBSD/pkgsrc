#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: omninames.sh,v 1.1.1.1 2010/09/01 15:52:58 drochner Exp $
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
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
