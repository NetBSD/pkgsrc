#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: and.sh,v 1.1 2023/06/15 09:55:25 hauke Exp $
#
# PROVIDE: and
# REQUIRE: DAEMON

name="and"
command="@PREFIX@/sbin/${name}"

if [ -f @SYSCONFBASE@/rc.subr ]; then
    	. @SYSCONFBASE@/rc.subr

	rcvar=${name}
	required_files="@PKG_SYSCONFDIR@/${name}.conf"
	pidfile="@VARBASE@/run/${name}.pid"

	load_rc_config ${name}
	run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
	${command} ${and_flags}
fi
