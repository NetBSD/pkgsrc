#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: winbindd.sh,v 1.1 2005/06/19 18:38:40 taca Exp $
#
# PROVIDE: winbindd
# REQUIRE: nmbd

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="winbindd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_vars="nmbd"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${winbindd_flags}
fi
