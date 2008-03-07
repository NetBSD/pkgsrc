#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: portmap.sh,v 1.1.1.1 2008/03/07 23:40:06 reed Exp $
#

# PROVIDE: portmap
# REQUIRE: NETWORKING ntpdate syslogd named ppp

. /etc/rc.subr

name="portmap"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
