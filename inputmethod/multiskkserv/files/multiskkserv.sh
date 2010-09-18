#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: multiskkserv.sh,v 1.1.1.1 2010/09/18 11:04:17 obache Exp $
#
# PROVIDE: multiskkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="multiskkserv"
rcvar=$name
command="@PREFIX@/sbin/${name}"

multiskkserv_flags="@SKKJISYOCDBDIR@/share/skk/SKK-JISYO.L.cdb &"

load_rc_config $name
run_rc_command "$1"
