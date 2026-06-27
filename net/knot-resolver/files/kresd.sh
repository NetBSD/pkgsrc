#!/bin/sh
#
# $NetBSD: kresd.sh,v 1.1 2026/06/27 20:39:04 drixter Exp $
#

# PROVIDE: kresd
# REQUIRE: DAEMON

. /etc/rc.subr

name="kresd"
rcvar="kresd_enable"

knotresolver_user="${name}"
knotresolver_command="@PREFIX@/sbin/${name} -n -c @PKG_SYSCONFDIR@/${name}.conf @PKG_SYSCONFDIR@/knot-resolver"

kresd_precmd()
{
    if [ ! -d "@VARBASE@/log/${name}/" ]; then
        install -d -o ${name} -g ${name} -m 755 "@VARBASE@/log/${name}/"
    fi

    if [ ! -e "@VARBASE@/log/${name}/${name}.log" ]; then
        install -o ${name} -g ${name} -m 644 /dev/null "@VARBASE@/log/${name}/${name}.log"
    fi
}

pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/daemonize"
command_args="-a -p ${pidfile} -u ${knotresolver_user} -o @VARBASE@/log/${name}/${name}.log -e @VARBASE@/log/${name}/${name}.log -- ${knotresolver_command}"

procname="@PREFIX@/sbin/${name}"

load_rc_config $name
start_precmd="kresd_precmd"

run_rc_command "$1"

