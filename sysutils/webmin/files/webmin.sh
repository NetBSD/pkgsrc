#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: webmin.sh,v 1.1.1.1 2004/07/23 19:28:32 jlam Exp $
#
# PROVIDE: webmin
# REQUIRE: LOGIN

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="webmin"
rcvar=${name}
command="@WEBMIN_DIR@/miniserv.pl"
command_interpreter="@PERL5@"
webmin_etcdir="@WEBMIN_ETCDIR@"
required_files="@WEBMIN_ETCDIR@/miniserv.conf"

start_cmd="webmin_doit"
stop_cmd="webmin_doit"

webmin_doit()
{
	script="${webmin_etcdir}/${rc_arg}"
	required_files="${required_files} ${script}"
	for f in $required_files; do
		if [ ! -r "$f" ]; then
			@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
			if [ -z $rc_force ]; then
				return 1
			fi
		fi
	done
	${script}
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case "$1" in
	stop)
		eval ${stop_cmd}
		;;
	start)
		eval ${start_cmd}
		;;
	esac
fi
