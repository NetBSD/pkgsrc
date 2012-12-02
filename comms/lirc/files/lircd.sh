#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lircd.sh,v 1.1 2012/12/02 01:21:51 cheusov Exp $
#
# PROVIDE: lircd
# REQUIRE: LOGIN

. /etc/rc.subr

name="lircd"
lircd_flags=${lircd_flags--H default -d /dev/lirc0}
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/lirc/${name}.pid"
required_files="@PKG_SYSCONFDIR@/lircd.conf"

load_rc_config $name
run_rc_command "$1"
