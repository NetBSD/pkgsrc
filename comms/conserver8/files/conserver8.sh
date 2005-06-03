#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: conserver8.sh,v 1.1.1.1 2005/06/03 20:08:04 wiz Exp $
#
# PROVIDE: conserver
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
       . /etc/rc.subr
fi

name="conserver"
rcvar=${name}8
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/conserver.cf"
pidfile="/var/run/conserver.pid"
command_args="-d"              # _must_ start as daemon from rc.d;
                               # add more flags through ${${name}_flags}
extra_commands="reload status"

if [ -f /etc/rc.subr ]
then
       load_rc_config $name
       run_rc_command "$1"
else
       @ECHO@ -n ' ${name}'
       ${command} ${conserver_flags} ${command_args}
fi
