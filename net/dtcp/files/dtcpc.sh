#!/bin/sh
#
# $FreeBSD: /repoman/r/pcvs/ports/net/dtcp/files/dtcpc.sh,v 1.1 2004/04/19 18:40:52 ume Exp $
# $NetBSD: dtcpc.sh,v 1.3 2005/02/01 14:26:14 hamajima Exp $
#

# PROVIDE: dtcpc
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move dtcpc.sh to /etc/rc.d/dtcpc

prefix=@PREFIX@

# Define these dtcpc_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/dtcpc
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
#dtcpc=${dtcpc_enable:-"NO"}			# Enable dtcpc
#dtcpc_program="${prefix}/sbin/dtcpc"		# Location of dtcpc
dtcpc_server=${dtcpc_server:-""}		# DTCP server name
dtcpc_username=${dtcpc_username:-""}		# DTCP user name
dtcpc_flags=${dtcpc_flags:-"-t network -Dl"}	# Flags to dtcpc program

. /etc/rc.subr

name="dtcpc"
rcvar=$name
command="${prefix}/sbin/${name}"
command_interpreter="@RUBY@"
pidfile="/var/run/${name}.pid"
extra_commands="reload"

load_rc_config $name
command_args="-u ${dtcpc_username} ${dtcpc_server}"
run_rc_command "$1"
