#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: webmin.sh,v 1.2 2005/01/23 04:36:27 jlam Exp $
#

# PROVIDE: webmin
# REQUIRE: LOGIN

. /etc/rc.subr

name="webmin"
rcvar=${name}
command="@WEBMIN_DIR@/miniserv.pl"
command_interpreter="@PERL5@"
webmin_etcdir="@WEBMIN_ETCDIR@"
required_files="@WEBMIN_ETCDIR@/miniserv.conf"

start_cmd="webmin_doit start"
stop_cmd="webmin_doit stop"

webmin_doit()
{
	case $1 in
	start)	script="${webmin_etcdir}/start" ;;
	stop)	script="${webmin_etcdir}/stop" ;;
	*)
	esac
	required_files="$required_files $script"
	for f in $required_files; do
		if [ ! -r "$f" ]; then
			@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
			if [ -z $rc_force ]; then
				return 1
			fi
		fi
	done
	$script
}

load_rc_config $name
run_rc_command "$1"
