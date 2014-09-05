#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rsyslogd.sh,v 1.1 2014/09/05 07:15:41 fhajny Exp $
# NetBSD: syslogd,v 1.15 2004/10/11 13:29:52 lukem Exp
#

# PROVIDE: rsyslogd
# REQUIRE: mountcritremote sysdb wscons
# BEFORE:  SERVERS

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rsyslogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/rsyslog.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
