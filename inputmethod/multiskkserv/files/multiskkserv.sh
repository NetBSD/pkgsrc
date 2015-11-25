#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: multiskkserv.sh,v 1.2 2015/11/25 12:50:58 jperkin Exp $
#
# PROVIDE: multiskkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="multiskkserv"
rcvar=$name
command="@PREFIX@/sbin/${name}"

multiskkserv_flags="@PREFIX@/share/skk/SKK-JISYO.L.cdb &"

load_rc_config $name
run_rc_command "$1"
