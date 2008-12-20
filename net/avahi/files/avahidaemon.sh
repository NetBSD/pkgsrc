#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: avahidaemon.sh,v 1.2 2008/12/20 23:51:39 ahoka Exp $
#
# PROVIDE: avahidaemon
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="avahidaemon"
rcvar=${name}
command="@PREFIX@/sbin/avahi-daemon"
required_files="@PKG_SYSCONFDIR@/avahi-daemon.conf"
avahidaemon_flags="-D"

load_rc_config $name
run_rc_command "$1"
