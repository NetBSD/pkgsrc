#!/bin/sh
#
# $NetBSD: beanstalkd.sh,v 1.2 2021/08/30 22:29:18 khorben Exp $
#
# beanstalkd - simple, fast work queue daemon
#
# PROVIDE: beanstalkd
# REQUIRE: DAEMON NETWORKING SERVERS
# KEYWORD: shutdown
#
# You will need to set some variables in @PKG_SYSCONFDIR@/rc.conf to start beanstalkd:
#
# beanstalkd=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	. @SYSCONFBASE@/rc.subr
	load_rc_config_var beanstalkd_user beanstalkd_user
	load_rc_config_var beanstalkd_host beanstalkd_host
	load_rc_config_var beanstalkd_port beanstalkd_port
fi

name="beanstalkd"
rcvar=${name}
beanstalkd_user="${beanstalkd_user:-@BEANSTALK_USER@}"
beanstalkd_host="${beanstalkd_host:-127.0.0.1}"
beanstalkd_port="${beanstalkd_port:-11300}"
pidfile="@VARBASE@/run/${name}.pid"
start_cmd="beanstalkd_start"
command="@PREFIX@/bin/${name}"
command_args="-u ${beanstalkd_user} -l ${beanstalkd_host} -p ${beanstalkd_port}"

beanstalkd_start()
{
	echo "Starting ${name}."
	${command} ${beanstalkd_flags} ${command_args} &
	echo $! > ${pidfile}
}

if [ -f @SYSCONFBASE@/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${start_cmd}
fi
