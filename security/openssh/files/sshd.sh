#!/bin/sh
#
# $NetBSD: sshd.sh,v 1.6 2001/10/19 09:42:08 veego Exp $
#
# PROVIDE: sshd
# REQUIRE: DAEMON LOGIN

name="sshd"
pidfile="@SSH_PID_DIR@/${name}.pid"

command=${1:-start}

case ${command} in
start)
	if [ ! -f @SSH_CONF_DIR@/ssh_host_key ]
	then
		@PREFIX@/bin/ssh-keygen -t rsa1 -N "" -f /etc/ssh_host_key
	fi
	if [ ! -f @SSH_CONF_DIR@/ssh_host_rsa_key ]
	then
		@PREFIX@/bin/ssh-keygen -t rsa -N "" -f /etc/ssh_host_rsa_key
	fi
	if [ ! -f @SSH_CONF_DIR@/ssh_host_dsa_key ]
	then
		@PREFIX@/bin/ssh-keygen -t dsa -N "" -f /etc/ssh_host_dsa_key
	fi
	if [ -x @PREFIX@/sbin/sshd -a -f @SSH_CONF_DIR@/sshd_config ]
	then
		echo "Starting ${name}."
		@PREFIX@/sbin/sshd
	fi
	;;
stop)
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
		echo "Stopping ${name}."
		kill -TERM ${pid}
	else
		echo "${name} not running?"
	fi
	;;
restart)
	( $0 stop )
	sleep 1
	$0 start
	;;
status)
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
		echo "${name} is running as pid ${pid}."
	else
		echo "${name} is not running."
	fi
	;;
esac
exit 0
