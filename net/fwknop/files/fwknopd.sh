#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fwknopd.sh,v 1.1 2021/05/29 22:39:46 khorben Exp $
#
# Startup script for fwknopd
#
# PROVIDE: fwknopd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start fwknopd:
#
# fwknopd=YES
#
# Optionally, "fwknopd_flags" contains additional parameters for the service.
# See fwknopd(8) for possible options.

. /etc/rc.subr

name="fwknopd"
rcvar=${name}
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/fwknop/fwknopd.conf"
fwknopd_flags=

load_rc_config $name
run_rc_command "$1"
