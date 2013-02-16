#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gmediaserver.sh,v 1.2 2013/02/16 15:10:46 tron Exp $
#
# PROVIDE: gmediaserver
# REQUIRE: DAEMON

. /etc/rc.subr

name="gmediaserver"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/gmediaserver/${name}.pid"
command_flags="-b --pid-file=${pidfile} -o @VARBASE@/${name}/${name}.log"
required_files="@CFGFILE@"
start_cmd="gmediaserver_start"
extra_commands="rescan"
rescan_cmd="gmediaserver_rescan"

gmediaserver_start()
{
	directories=/nonexistent
	options=
	if [ -f "@CFGFILE@" ]; then
		. "@CFGFILE@"
	fi
	@ECHO@ "Starting ${name}."
	@SU@ @GMEDIA_USER@ -c "$command" $command_flags $options $directories
}

gmediaserver_rescan()
{
	if [ -f "${pidfile}" ] ; then
		@ECHO@ "Signalling ${name} to rescan directories."
		kill -USR1 `@CAT@ "${pidfile}"`
	fi
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case $1 in
	start)
		gmediaserver_start
		;;

	stop)
		if [ -f "${pidfile}" ] ; then
			@ECHO@ "Stopping ${name}."
			kill `@CAT@ "${pidfile}"`
		else
			@ECHO@ "${name} not running?"
			exit 1
		fi
		;;

	restart)
		"$0" stop
		exec "$0" start
		;;

	rescan)
		gmediaserver_rescan
		;;

	*)
		@ECHO@ "Usage: $0 {start|stop|restart|rescan}" 1>&2
		exit 64
		;;

	esac
fi
