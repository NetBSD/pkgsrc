#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: miniupnpd.sh,v 1.1 2009/01/06 23:39:53 jmcneill Exp $
#
# PROVIDE: miniupnpd
# REQUIRE: DAEMON @FWNAME@
# KEYWORD: shutdown

. /etc/rc.subr

name="miniupnpd"
rcvar=$name
command="@PREFIX@/sbin/miniupnpd"

load_rc_config $name
run_rc_command "$1"
