#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isakmpd.sh,v 1.2 2003/07/31 10:38:33 jmmv Exp $
#
# PROVIDE: isakmpd
# REQUIRE: DAEMON NETWORK
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="isakmpd"
rcvar="${name}"
command="@PREFIX@/sbin/isakmpd"
pidfile="/var/run/isakmpd.pid"
required_files="@PKG_SYSCONFDIR@/isakmpd.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config "${name}"
	run_rc_command "$1"
else
	printf " ${name}"
	eval ${command} ${isakmpd_flags} ${command_args}
fi
