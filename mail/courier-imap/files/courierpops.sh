#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierpops.sh,v 1.18 2008/02/19 18:45:14 jlam Exp $
#
# Courier POP3/SSL services daemon
#
# PROVIDE: courierpops
# REQUIRE: authdaemond
# KEYWORD: shutdown

. /etc/rc.subr

name="courierpops"
rcvar=${name}
command="@PREFIX@/sbin/couriertcpd"
ctl_command="@PREFIX@/sbin/pop3d-ssl"
pidfile="@COURIER_STATEDIR@/tmp/pop3d-ssl.pid"
required_files="@PKG_SYSCONFDIR@/pop3d @PKG_SYSCONFDIR@/pop3d-ssl"

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

courierpops_prestart()
{
	mkdir_perms @COURIER_STATEDIR@/tmp \
		@COURIER_USER@ @COURIER_GROUP@ 0770
}

courierpops_doit()
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

		. @PKG_SYSCONFDIR@/pop3d
		. @PKG_SYSCONFDIR@/pop3d-ssl

		f="$TLS_CERTFILE"
		if [ -z "$f" ]; then
			@ECHO@ 1>&2 "$0: WARNING: TLS_CERTFILE is empty"
			return 1
		fi
		if [ ! -f "$f" ] && \
		   [ "$f" = "@PKG_SYSCONFDIR@/pop3d.pem" ]; then
			@ECHO@ "Generating POP3 SSL certificate in $f."
			@PREFIX@/sbin/mkpop3dcert >/dev/null 2>&1
		fi
		if [ ! -r "$f" ]; then
			@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
			return 1
		fi

		case x$POP3DSSLSTART in
		x[yY]*)
			@ECHO@ "Starting ${name}."
			${ctl_command} $action
               	;;
		esac
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		${ctl_command} $action
		;;
	esac
}

load_rc_config $name
run_rc_command "$1"
