#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: delegated.sh,v 1.3 2003/07/30 11:37:03 jmmv Exp $
#
# PROVIDE: delegated
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="delegated"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-P8080 ADMIN=@ADMIN@ CHARCODE=JIS \
              CACHEDIR=/var/spool/delegate/cache \
              EXPIRE=7d RELIABLE=hostname >/dev/null 2>&1"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${delegated_flags} ${command_args} >/dev/null 2>&1
fi
