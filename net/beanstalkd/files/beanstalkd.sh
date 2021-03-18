#!/bin/sh
#
# $NetBSD: beanstalkd.sh,v 1.1 2021/03/18 22:54:52 khorben Exp $
#
# beanstalkd - simple, fast work queue daemon
#
# PROVIDE: beanstalkd
# REQUIRE: DAEMON NETWORKING SERVERS
#
# You will need to set some variables in @PKG_SYSCONFDIR@/rc.conf to start beanstalkd:
#
# beanstalkd=YES

. /etc/rc.subr

name="beanstalkd"
rcvar=${name}
beanstalkd_user="@BEANSTALK_USER@"
beanstalkd_host="127.0.0.1"
beanstalkd_port="11300"
start_cmd="beanstalkd_start"
restart_cmd="beanstalkd_stop ; beanstalkd_start"
stop_cmd="beanstalkd_stop"
command="@PREFIX@/bin/${name}"
command_args="-u ${beanstalkd_user} -l ${beanstalkd_host} -p ${beanstalkd_port}"

beanstalkd_start()
{
	${command} ${command_args} &
}

beanstalkd_stop()
{
        pkill -u @BEANSTALK_USER@ 2>/dev/null
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	eval ${start_cmd}
fi
