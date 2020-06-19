#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lldpd.sh,v 1.2 2020/06/19 10:05:07 hauke Exp $
#

# PROVIDE: lldpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="lldpd"
rcvar="lldpd"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
