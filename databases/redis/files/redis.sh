#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: redis.sh,v 1.2 2013/06/13 18:26:02 mspo Exp $
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
redis_flags="${redis_flags:- --bind 127.0.0.1 --daemonize yes}"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${redis_user} -c "${command}"
fi
