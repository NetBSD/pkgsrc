#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pcpd.sh,v 1.2 2004/02/24 01:18:52 jlam Exp $
#
# Courier SqWebMail calendaring services daemon
#
# PROVIDE: pcpd
# REQUIRE: authdaemond

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="pcpd"
rcvar=${name}
command="@PREFIX@/libexec/courier/sqwebmail/pcpd"
required_files="@PKG_SYSCONFDIR@/calendarmode"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ "$0: WARNING: $f is not readable"
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

	${command} ${action}
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${start_cmd}
fi
