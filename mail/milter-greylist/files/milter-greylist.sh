#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: milter-greylist.sh,v 1.4 2009/03/08 15:54:26 tron Exp $
#

# PROVIDE: milter-greylist
# REQUIRE: DAEMON
# BEFORE:  mail

name="miltergreylist"
rcvar="miltergreylist"
command="@PREFIX@/bin/milter-greylist"
command_args="-p /var/milter-greylist/milter-greylist.sock -u @MILTER_USER@"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	. /etc/rc.subr
	. /etc/rc.conf

	load_rc_config $name
	run_rc_command "$1"

else				# old NetBSD, Solaris, Linux, etc...
	pidfile=/var/run/${name}.pid

	case $1 in
	start)
		nohup ${command} -D ${command_args} </dev/null >/dev/null 1>&2 &
		echo $! >${pidfile}
		
		;;
	stop)
		if [ -f ${pidfile} ]
		then
			kill `cat ${pidfile}`
			rm -f ${pidfile}
		fi
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop}" 1>&2
		exit 64
		;;
	esac

fi
