#!/bin/sh
#
# $NetBSD: sshd.sh,v 1.3 2000/07/24 16:44:52 jlam Exp $
#

name="sshd"
pidfile="/var/run/${name}.pid"

command=${1:-start}

case ${command} in
start)
	if [ ! -f @SSH_CONF_DIR@/ssh_host_key ]
	then
		@PREFIX@/bin/ssh-keygen -b 1024 -N "" -f /etc/ssh_host_key
	fi
	if [ ! -f @SSH_CONF_DIR@/ssh_host_dsa_key ]
	then
		/usr/pkg/bin/ssh-keygen -d -N "" -f /etc/ssh_host_dsa_key
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
