#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: proxsmtpd.sh,v 1.1.1.1 2004/12/02 04:08:18 jlam Exp $
#
# PROVIDE: proxsmtpd
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="proxsmtpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"

start_precmd="proxsmtpd_prestart"
stop_postcmd="proxsmtpd_poststop"

user="nobody"
tempdir="/tmp"
pidfile=/var/run/${name}.pid
conffile="@PKG_SYSCONFDIR@/${name}.conf"
if [ -f "${conffile}" ]; then
	user=`@AWK@ 'BEGIN {r = "nobody"}; /^User:/ {r = $2}; END {print r}' ${conffile}`
	tempdir=`@AWK@ 'BEGIN {r = "/tmp"}; /^TempDirectory:/ {r = $2}; END {print r}' ${conffile}`

	case ${tempdir} in
	/tmp)	;;
	*)	pidfile="${tempdir}/${name}.pid" ;;
	esac
fi

command_args="-p ${pidfile}"

proxsmtpd_prestart()
{
	case ${tempdir} in
	/tmp)	;;
	*)	if [ ! -d "${tempdir}" ]; then
			@MKDIR@ -p ${tempdir}
		fi
		@CHOWN@ -R ${user} ${tempdir}
		@CHMOD@ -R 0700 ${tempdir}
		;;
	esac
	@TOUCH@ ${pidfile}
	@CHOWN@ ${user} ${pidfile}
}

proxsmtpd_poststop()
{
	@RM@ -f ${pidfile}
	case ${tempdir} in
	/tmp)	;;
	*)	@RMDIR@ -p ${tempdir} 2>/dev/null || @TRUE@
	esac
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	${command} ${proxsmtpd_flags} ${command_args}
fi
