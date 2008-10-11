#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nasd.sh,v 1.1 2008/10/11 21:00:53 markd Exp $
#
# PROVIDE: nasd
# REQUIRE: LOGIN

. /etc/rc.subr

name="nasd"
nasd_flags='-b '${nasd_flags-"-aa -local"}
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/nasd.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
