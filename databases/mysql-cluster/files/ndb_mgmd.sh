#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ndb_mgmd.sh,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $
#
# PROVIDE: ndb_mgmd
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start MySQL:
#
# ndb_mgmd=YES
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="ndb_mgmd"
rcvar=${name}
command="@PREFIX@/sbin/$name"

mysqld_start()
{
	@ECHO@ "Starting ${name}."
	cd @PREFIX@
	${command}
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	pidfile="/var/run/${name}.pid"
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	pidfile="/var/run/${name}.pid"
	case "$1" in
	stop)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Stopping ${name}."
			kill `@CAT@ ${pidfile}`
		fi
		;;
	start
		eval ${start_cmd}
		;;
	esac
fi
