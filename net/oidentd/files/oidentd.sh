#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: oidentd.sh,v 1.2 2004/04/12 14:18:15 tron Exp $
#

# PROVIDE: oidentd
# REQUIRE: DAEMON

conf_file="@PKG_SYSCONFDIR@/oidentd.conf"

name="oidentd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="${conf_file}"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	. /etc/rc.subr
	. /etc/rc.conf

	load_rc_config $name
	run_rc_command "$1"

else				# old NetBSD, Solaris, Linux, etc...

	case $1 in
	start)
		${command}
		;;
	stop)
		pkill ${name}
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop}" 1>&2
		exit 64
		;;
	esac

fi
