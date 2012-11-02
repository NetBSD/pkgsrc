#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: webmin.sh,v 1.4 2012/11/02 19:02:51 shattered Exp $
#

# PROVIDE: webmin
# REQUIRE: LOGIN

. /etc/rc.subr

name="webmin"
rcvar=${name}
command="@WEBMIN_DIR@/miniserv.pl"
command_interpreter="@PERL5@"
webmin_etcdir="@PKG_SYSCONFDIR@"
required_files="@PKG_SYSCONFDIR@/miniserv.conf"
extra_commands="reload"

reload_cmd="webmin_doit reload"
restart_cmd="webmin_doit restart"
start_cmd="webmin_doit start"
stop_cmd="webmin_doit stop"

webmin_doit()
{
	case "$1" in
	reload|restart|start|stop)	;;
	*)				return 1 ;;
	esac
	script="${webmin_etcdir}/$1"
	required_files="$required_files $script"
	for f in $required_files; do
		if [ ! -r "$f" ]; then
			echo 1>&2 "$0: WARNING: $f is not readable"
			if [ -z $rc_force ]; then
				return 1
			fi
		fi
	done
	$script
}

load_rc_config $name
run_rc_command "$1"
