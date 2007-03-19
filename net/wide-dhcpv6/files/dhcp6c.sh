#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dhcp6c.sh,v 1.1.1.1 2007/03/19 17:32:07 taca Exp $
#

# PROVIDE: dhcp6c
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dhcp6c"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
