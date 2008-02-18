#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: authdaemond.sh,v 1.4 2008/02/18 20:35:48 jlam Exp $
#
# Courier user authentication daemon
#
# PROVIDE: authdaemond
# REQUIRE: LOGIN

. /etc/rc.subr

name="authdaemond"
rcvar=${name}
command="@PREFIX@/sbin/courierlogger"
ctl_command="@PREFIX@/sbin/authdaemond"
pidfile="@AUTHDAEMONVAR@/pid"
required_files="@PKG_SYSCONFDIR@/authdaemonrc"

start_precmd="authdaemond_prestart"
start_cmd="authdaemond_doit start"
stop_cmd="authdaemond_doit stop"

mkdir_perms()
{
	dir="$1"; user="$2"; group="$3"; mode="$4"
	@TEST@ -d $dir || @MKDIR@ $dir
	@CHOWN@ $user $dir
	@CHGRP@ $group $dir
	@CHMOD@ $mode $dir
}

authdaemond_prestart()
{
	mkdir_perms @AUTHDAEMONVAR@ \
		@COURIER_USER@ @COURIER_GROUP@ 0750
}

authdaemond_doit()
{
	action=$1
	case ${action} in
	start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				if [ -z $rc_force ]; then
					return 1
				fi
			fi
		done
		@ECHO@ "Starting ${name}."
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		;;
	esac

	${ctl_command} ${action}
}

load_rc_config $name
run_rc_command "$1"
