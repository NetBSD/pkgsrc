#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fwknopd.sh,v 1.2 2021/11/07 18:37:03 khorben Exp $
#
# Startup script for fwknopd
#
# PROVIDE: fwknopd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start fwknopd:
#
# fwknopd=YES
#
# Optionally, "fwknopd_flags" contains additional parameters for the service.
# See fwknopd(8) for possible options.

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="fwknopd"
rcvar=${name}
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/fwknop/fwknopd.conf"
fwknopd_flags=

load_rc_config $name
run_rc_command "$1"
