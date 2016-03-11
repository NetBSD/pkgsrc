#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pgpool2.sh,v 1.1 2016/03/11 21:30:55 fhajny Exp $
#
# PROVIDE: pgpool2
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="pgpool2"
rcvar=$name
command="@PREFIX@/bin/pgpool"
pgpool_user="@PGPOOL_USER@"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${pgpool_user} -c "${command}"
fi
