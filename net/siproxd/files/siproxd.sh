#!/bin/sh
#
# $NetBSD: siproxd.sh,v 1.1 2018/11/14 15:25:28 hauke Exp $
#

# PROVIDE: siproxd
# REQUIRE: DAEMON
# BEFORE:  LOGIN
# KEYWORD: chrootdir

$_rc_subr_loaded . /etc/rc.subr

name="siproxd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}/${name}.pid"
required_files="@PKG_SYSCONFDIR@/siproxd.conf"
start_precmd="siproxd_precmd"

siproxd_precmd()
{
        rc_flags="-p ${pidfile} $rc_flags"

        local piddir="$(dirname "${pidfile}")"

        # Make sure @VARBASE@/run/siproxd exists
        mkdir -p "${siproxd_chrootdir}${piddir}"
	chown @SIPROXD_USER@:@SIPROXD_GROUP@ "${siproxd_chrootdir}${piddir}"

	# If chrooted, provide a link to the pid and registrations file
	# Note: siproxd chroots itself, if so configured

        if [ -n "${siproxd_chrootdir}" ]; then
	        ln -snf "${siproxd_chrootdir}${piddir}" "${piddir}"
	fi

        return 0
}

load_rc_config $name
run_rc_command "$1"
