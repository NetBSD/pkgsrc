#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: conserver.sh,v 1.5 2007/05/19 14:05:03 wiz Exp $
#
# PROVIDE: conserver
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
       . /etc/rc.subr
fi

name="conserver"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/conserver.cf"
pidfile="/var/run/conserver.pid"
command_args="-d"              # _must_ start as daemon from rc.d;
                               # add more flags through ${${name}_flags}
extra_commands="reload"

if [ -f /etc/rc.subr ]
then
       load_rc_config $name
       run_rc_command "$1"
else
       @ECHO@ -n ' ${name}'
       ${command} ${conserver_flags} ${command_args}
fi
