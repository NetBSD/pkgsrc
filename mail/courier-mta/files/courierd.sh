#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierd.sh,v 1.5 2008/02/19 18:45:24 jlam Exp $
#
# Courier core processes 
#
# PROVIDE: courierd
# REQUIRE: authdaemond courierfilter @COURIERLDAPALIASD@
# KEYWORD: shutdown

. /etc/rc.subr

name="courierd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
ctl_command="@PREFIX@/sbin/courier"

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

courierd_prestart()
{
	# Courier mail submission directories
	mkdir_perms @COURIER_STATEDIR@/msgq \
			@COURIER_USER@ @COURIER_GROUP@ 0750
	mkdir_perms @COURIER_STATEDIR@/msgs \
			@COURIER_USER@ @COURIER_GROUP@ 0750
	mkdir_perms @COURIER_STATEDIR@/tmp \
			@COURIER_USER@ @COURIER_GROUP@ 0770
	mkdir_perms @COURIER_STATEDIR@/track \
			@COURIER_USER@ @COURIER_GROUP@ 0755

	# Courier webadmin directories
	mkdir_perms @COURIER_STATEDIR@/webadmin \
			@COURIER_USER@ @COURIER_GROUP@ 0700
	mkdir_perms @COURIER_STATEDIR@/webadmin/added \
			@COURIER_USER@ @COURIER_GROUP@ 0700
	mkdir_perms @COURIER_STATEDIR@/webadmin/removed \
			@COURIER_USER@ @COURIER_GROUP@ 0700

	# Courier delivery configuration directories
	mkdir_perms @PKG_SYSCONFDIR@/aliasdir \
			@COURIER_USER@ @COURIER_GROUP@ 0755
	mkdir_perms @PKG_SYSCONFDIR@/aliases \
			@COURIER_USER@ @COURIER_GROUP@ 0750
	mkdir_perms @PKG_SYSCONFDIR@/smtpaccess \
			@COURIER_USER@ @COURIER_GROUP@ 0755
}

courierd_doit()
{
	action=$1

	case $action in
	restart)
		@ECHO@ "Restarting ${name}."
		;;
	start)
		@TEST@ -f @PKG_SYSCONFDIR@/aliases.dat ||
			@PREFIX@/sbin/makealiases
		@ECHO@ "Starting ${name}."
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		;;
	esac

	${ctl_command} $action
}

load_rc_config $name
run_rc_command "$1"
