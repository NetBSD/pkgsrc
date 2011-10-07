#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: LPRng.sh,v 1.5 2011/10/07 22:37:05 shattered Exp $
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
