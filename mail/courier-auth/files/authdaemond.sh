#! /bin/sh
#
# $NetBSD: authdaemond.sh,v 1.1.1.1 2002/01/22 22:00:22 jlam Exp $
#
# Courier user authentication daemon
#
# PROVIDE: authdaemond
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="authdaemond"
rcvar=${name}
command="@PREFIX@/libexec/courier/authlib/authdaemond"
pidfile="/var/authdaemon/pid"
required_files="@PKG_SYSCONFDIR@/authdaemonrc"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
        action=$1
        case ${action} in
        start)  echo "Starting ${name}." ;;
        stop)   echo "Stopping ${name}." ;;
        esac

        @SETENV@ - ${command} ${action}
}

if [ -e /etc/rc.subr ]
then
        load_rc_config $name
        run_rc_command "$1"
else
        echo -n " ${name}"
        ${start_cmd}
fi
