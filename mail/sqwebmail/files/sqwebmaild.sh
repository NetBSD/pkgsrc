#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sqwebmaild.sh,v 1.1 2004/02/23 23:41:43 jlam Exp $
#
# Courier SqWebMail services daemon
#
# PROVIDE: sqwebmail
# REQUIRE: authdaemond

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="sqwebmaild"
rcvar=${name}
command="@PREFIX@/libexec/courier/sqwebmail/sqwebmaild"
required_files="@PKG_SYSCONFDIR@/authmodulelist"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)	@ECHO@ "Starting ${name}." ;;
	stop)	@ECHO@ "Stopping ${name}." ;;
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
