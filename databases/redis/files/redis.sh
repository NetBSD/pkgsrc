#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: redis.sh,v 1.5 2022/12/02 05:51:26 triaxx Exp $
#
# PROVIDE: redis
# REQUIRE: DAEMON NETWORKING
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="redis"
rcvar=$name
command="@PREFIX@/bin/redis-server"
redis_user="@REDIS_USER@"
redis_flags="@PKG_SYSCONFDIR@/redis.conf"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${redis_user} -c "${command}"
fi
