#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: conserver.sh,v 1.4 2004/07/10 22:35:32 salo Exp $
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

if [ -f /etc/rc.subr ]
then
       load_rc_config $name
       run_rc_command "$1"
else
       @ECHO@ -n ' ${name}'
       ${command} ${conserver_flags} ${command_args}
fi
