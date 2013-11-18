#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: opensmtpd.sh,v 1.1 2013/11/18 22:50:01 pettai Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN
#       we make mail start late, so that things like .forward's are not
#       processed until the system is fully operational

. /etc/rc.subr

name="smtpd"
rcvar=opensmtpd
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/smtpd.conf"

load_rc_config $name
run_rc_command "$1"
