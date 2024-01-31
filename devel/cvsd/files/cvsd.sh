#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cvsd.sh,v 1.2 2024/01/31 13:38:46 hauke Exp $
#
# PROVIDE: cvsd
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
       . /etc/rc.subr
fi

name="cvsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile=$(awk '/^#/ {next}; /PidFile/ {print $2}' ${required_files})
# pidfile=/var/run/cvsd.pid
command_args=""              
                               # add more flags through ${${name}_flags}

if [ -e /etc/rc.subr ]
then
       load_rc_config $name
       run_rc_command "$1"
else
       echo -n ' ${name}'
       ${command} ${cvsd_flags} ${command_args}
fi
