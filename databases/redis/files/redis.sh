#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: redis.sh,v 1.1 2013/06/13 17:41:34 mspo Exp $
#
# PROVIDE: redis 
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="redis"
rcvar=$name
command="@PREFIX@/bin/redis-server"
redis_user="@REDIS_USER@"
command_args="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${redis_user} -c "${command} ${command_args}"
fi
