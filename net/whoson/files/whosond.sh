#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: whosond.sh,v 1.1.1.1 2004/10/11 16:51:54 abs Exp $
#
# PROVIDE: whosond
# REQUIRE: NETWORK
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="whosond"
rcvar="${name}"
command="@PREFIX@/sbin/whosond"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf ' whosond'
	${command} ${whosond_flags} ${command_args}
fi
