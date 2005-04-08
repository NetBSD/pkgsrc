#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ztcfg.sh,v 1.1.1.1 2005/04/08 03:03:42 riz Exp $
#
# PROVIDE: ztcfg
# REQUIRE: aftermountlkm
# BEFORE: asterisk
#
# You will need to set some variables in /etc/rc.conf to run ztcfg:
#
# ztcfg=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ztcfg"
rcvar=$name
command="@PREFIX@/bin/ztcfg"
required_files="@PKG_SYSCONFDIR@/zaptel.conf"

load_rc_config $name
run_rc_command "$1"
