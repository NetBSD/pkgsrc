#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: redis.sh,v 1.6 2023/10/06 07:27:43 triaxx Exp $
#
# PROVIDE: redis
# REQUIRE: DAEMON NETWORKING
# KEYWORD: shutdown

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="redis"
rcvar=$name
command="@PREFIX@/bin/redis-server"
redis_user="@REDIS_USER@"
redis_flags="@PKG_SYSCONFDIR@/redis.conf"

if [ -f @SYSCONFBASE@/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${redis_user} -c "${command}"
fi
