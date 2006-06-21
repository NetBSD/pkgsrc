#!/bin/sh
#
# $NetBSD: LPRng.sh,v 1.4 2006/06/21 13:50:46 jlam Exp $
#
# PROVIDE: LPRng lpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="LPRng"
rcvar=$name
command="@PREFIX@/sbin/lpd"
pidfile="/var/run/lpd.pid"
required_files="@PKG_SYSCONFDIR@/lpd/lpd.conf"

LPRng_prestart()
{
	# Verify permissions of spool directories for existing printcap
	# entries.
	#
	@TEST@ ! -x @PREFIX@/sbin/checkpc || @PREFIX@/sbin/checkpc -f
}

start_precmd="LPRng_prestart"

load_rc_config $name
run_rc_command "$1"
