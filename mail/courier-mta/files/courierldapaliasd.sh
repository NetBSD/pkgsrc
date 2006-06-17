#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierldapaliasd.sh,v 1.3 2006/06/17 19:38:43 jlam Exp $
#
# Courier LDAP mail aliasing daemon
#
# PROVIDE: courierldapaliasd
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="courierldapaliasd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@COURIER_STATEDIR@/tmp/ldapaliasd.pid"
required_files="@PKG_SYSCONFDIR@/ldapaliasrc"

restart_cmd="courierldapaliasd_doit restart"
start_precmd="courierldapaliasd_prestart"
start_cmd="courierldapaliasd_doit start"
stop_cmd="courierldapaliasd_doit stop"

mkdir_perms() {
	dir="$1"; user="$2"; group="$3"; mode="$4"
	@TEST@ -d $dir || @MKDIR@ $dir
	@CHOWN@ $user $dir
	@CHGRP@ $group $dir
	@CHMOD@ $mode $dir
}

courierldapaliasd_prestart()
{
	@MKDIR@ @COURIER_STATEDIR@
	mkdir_perms @COURIER_STATEDIR@/tmp \
			@COURIER_USER@ @COURIER_GROUP@ 0770
}

courierldapaliasd_doit()
{
	action=$1

	case $action in
	restart|start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				return 1
			fi
		done
		case $action in
		restart)	@ECHO@ "Restarting ${name}." ;;
		start)		@ECHO@ "Starting ${name}." ;;
		esac
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		;;
	esac

	${command} $action
}

load_rc_config $name
run_rc_command "$1"
