#!/bin/sh
#
# $NetBSD: pgsql.sh,v 1.2 2001/02/12 20:11:56 jlam Exp $
#
# PostgreSQL database rc.d control script
#
# PROVIDE: pgsql
# REQUIRE: DAEMON
# KEYWORD: shutdown

name="postgres"
ctl_command="@PREFIX@/bin/pg_ctl"
command="@PREFIX@/bin/postmaster"
command_args="-S -o -F"			# start in silent mode and disable
					#   automatic fsync after each
					#   transaction
#command_args="-S -i -o -F"		# as above, but also allows TCP/IP
					#   connections

USER="@PGUSER@"
PGHOME="@PREFIX@/${USER}"
SU="@SU@"

cmd=${1:-start}

if [ -x ${ctl_command} -a -x ${command} ]
then
	case ${cmd} in
	restart)
		echo "Restarting ${name}."
		echo "exec ${ctl_command} restart >> ${PGHOME}/errlog" \
			| ${SU} -l ${USER}
		;;

	start)
		echo "Starting ${name}."
		echo "exec ${ctl_command} \
			-p ${command} -o \"${command_args}\" start" \
			| ${SU} -l ${USER}
		;;

	stop)
		echo "Stopping ${name}."
		echo "exec ${ctl_command} stop >> ${PGHOME}/errlog" \
			| ${SU} -l ${USER}
		;;

	status)
		echo "exec ${ctl_command} status" \
			| ${SU} -l ${USER}
		;;

	*)
		echo 1>&2 "Usage: $0 [restart|start|stop|status]"
		exit 1
		;;
	esac
fi
