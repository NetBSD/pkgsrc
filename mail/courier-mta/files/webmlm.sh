#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: webmlm.sh,v 1.1 2007/08/10 17:57:04 jlam Exp $
#
# Courier mailing list management daemon
#
# PROVIDE: webmlm
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="webmlm"
rcvar=${name}
command="@PREFIX@/sbin/courierlogger"
ctl_command="@PREFIX@/bin/webmlmd.rc"
pidfile="@COURIER_STATEDIR@/webmlm.pid"
required_files="@PKG_SYSCONFDIR@/webmlmrc"

restart_cmd="${name}_doit restart"
start_precmd="${name}_prestart"
start_cmd="${name}_doit start"
stop_cmd="${name}_doit stop"

mkdir_perms()
{
	dir="$1"; user="$2"; group="$3"; mode="$4"
	@TEST@ -d $dir || @MKDIR@ $dir
	@CHOWN@ $user $dir
	@CHGRP@ $group $dir
	@CHMOD@ $mode $dir
}

webmlmd_prestart()
{
	@MKDIR@ @COURIER_STATEDIR@
	mkdir_perms @COURIER_STATEDIR@/webmlm \
			@COURIER_USER@ @COURIER_GROUP@ 0755
}

webmlm_doit()
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

	${ctl_command} @PREFIX@/bin/webmlmd $action
}

load_rc_config $name
run_rc_command "$1"
