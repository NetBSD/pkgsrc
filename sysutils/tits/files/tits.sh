#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tits.sh,v 1.1 2006/05/18 15:45:09 gavan Exp $
#

# PROVIDE: tits
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="tits"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/tits.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${tits_flags}
fi
