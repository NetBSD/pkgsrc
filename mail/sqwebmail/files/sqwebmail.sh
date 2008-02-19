#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sqwebmail.sh,v 1.11 2008/02/19 18:45:32 jlam Exp $
#
# Courier SqWebMail services daemon
#
# PROVIDE: sqwebmail
# REQUIRE: authdaemond
# KEYWORD: shutdown

. /etc/rc.subr

name="sqwebmail"
rcvar=${name}
command="@PREFIX@/sbin/courierlogger"
ctl_command="@PREFIX@/sbin/webmaild"
pidfile="@COURIER_STATEDIR@/tmp/sqwebmaild.pid"
required_files="@PKG_SYSCONFDIR@/calendarmode @PKG_SYSCONFDIR@/sqwebmaild"

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

sqwebmail_prestart()
{
	# Courier webmail and calendar (pcp) directories
	@MKDIR@ @SQWEBMAIL_STATEDIR@
	@MKDIR@ @SQWEBMAIL_CACHEDIR@
	mkdir_perms @SQWEBMAIL_CALENDARDIR@ \
			@ROOT_USER@ @COURIER_GROUP@ 0755
	mkdir_perms @SQWEBMAIL_CALENDARDIR@/public \
			@ROOT_USER@ @COURIER_GROUP@ 0755
	mkdir_perms @SQWEBMAIL_CALENDARDIR@/private \
			@ROOT_USER@ @COURIER_GROUP@ 0750
	mkdir_perms @SQWEBMAIL_CALENDARDIR@/localcache \
			@ROOT_USER@ @COURIER_GROUP@ 0750
	mkdir_perms @COURIER_STATEDIR@/tmp \
			@COURIER_USER@ @COURIER_GROUP@ 0770
}

sqwebmail_doit()
{
	action=$1
	case $action in
	start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				return 1
			fi
		done
		@ECHO@ "Starting ${name}."
		${ctl_command} $action
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		${ctl_command} $action
		;;
	esac
}

load_rc_config $name
run_rc_command "$1"
