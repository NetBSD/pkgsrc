#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ircd.sh,v 1.1 2003/03/01 05:22:23 grant Exp $
#

# PROVIDE: ircd
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ircd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/ircd.conf"
pidfile="/var/ircd/${name}.pid"
command_args="-d /var/ircd -f ${required_files}"
ircd_user="@IRCD_USER@"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${ircd_flags} ${command_args}
fi
