#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smtpfwdd.sh,v 1.1 2005/10/29 19:49:40 joerg Exp $
#
# PROVIDE: smtpfwdd
# REQUIRE: DAEMON

. /etc/rc.subr

name=smtpfwdd
rcvar=$name
start_precmd=smtpd_precmd
command="@PREFIX@/sbin/smtpfwdd"

SPOOL="@SPOOL@"

smtpd_precmd()
{
	(umask 077 && mkdir -p ${SPOOL}/etc)

	for f in TIMEZONE localtime resolv.conf; do
		if [ -f /etc/$f ]; then
			cmp -s /etc/$f ${SPOOL}/etc/$f ||
			    cp -p /etc/$f ${SPOOL}/etc/$f
		fi
	done
}

load_rc_config $name
run_rc_command "$1"
