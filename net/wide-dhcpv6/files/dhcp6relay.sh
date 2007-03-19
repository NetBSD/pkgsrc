#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dhcp6relay.sh,v 1.1.1.1 2007/03/19 17:32:07 taca Exp $
#

# PROVIDE: dhcp6relay
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dhcp6relay"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
