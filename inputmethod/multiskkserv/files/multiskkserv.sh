#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: multiskkserv.sh,v 1.3 2024/01/31 15:17:51 ryoon Exp $
#
# PROVIDE: multiskkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="multiskkserv"
rcvar=$name
command="@PREFIX@/sbin/${name}"

multiskkserv_flags="@PREFIX@/share/skk/SKK-JISYO.L.cdb @PREFIX@/share/skk/SKK-JISYO.JIS3_4.cdb &"

load_rc_config $name
run_rc_command "$1"
