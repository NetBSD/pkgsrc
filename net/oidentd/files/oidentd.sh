#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: oidentd.sh,v 1.1.1.1 2004/01/03 23:21:45 tron Exp $
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
		if [ -x ${command} -a -f ${conf_file} ] ; then
			eval ${command} && @ECHO@ -n " ${name}"
		fi
		;;
	stop)
		${stop_cmd}
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop}" 1>&2
		exit 64
		;;
	esac

fi
