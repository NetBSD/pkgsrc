#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: minerd.sh,v 1.3 2021/05/29 20:23:40 khorben Exp $
#
# Startup script for cpuminer
#
# PROVIDE: minerd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start minerd:
#
# minerd=YES
#
# Optionally, "minerd_flags" contains options for the service, e.g.
#	minerd_flags="-a scrypt"		# used by Litecoin
#	minerd_flags="-o URL"			# sets the URL of the server
#	minerd_flags="-O username:password"	# sets the credentials to use
# See minerd(1) for possible options.

. /etc/rc.subr

name="minerd"
rcvar=${name}
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/minerd.conf"
minerd_flags="-B -S -c @PKG_SYSCONFDIR@/minerd.conf"

load_rc_config $name
run_rc_command "$1"
