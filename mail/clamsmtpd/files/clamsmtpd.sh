#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: clamsmtpd.sh,v 1.1.1.1 2004/07/21 03:51:11 xtraeme Exp $
#
# PROVIDE: clamsmtpd
# REQUIRE: LOGIN clamd
# BEFORE: mail
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="clamsmtpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/tmp/${name}.pid"
clamsmtpd_user="@CLAMAV_USER@"
clamav_conf="@PKG_SYSCONFDIR@/clamav.conf"
socket=$(@AWK@ '/^#/ {next}; /LocalSocket/ {print $2}' ${clamav_conf})
command_args="-c ${socket} -p ${pidfile} 127.0.0.1:10026"

load_rc_config $name
run_rc_command "$1"
