#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: monotone.sh,v 1.1.1.1 2005/01/12 12:52:50 jmmv Exp $
#
# PROVIDE: monotone
# REQUIRE: DAEMON

. /etc/rc.subr

if [ -f "@PKG_SYSCONFDIR@/rc.conf" ]; then
    . @PKG_SYSCONFDIR@/rc.conf
fi

if [ -f "@PKG_SYSCONFDIR@/branches.conf" ]; then
    monotone_branches=$(cat @PKG_SYSCONFDIR@/branches.conf | grep -v '^#')
fi

: ${monotone_group=@MONOTONE_GROUP@}
: ${monotone_home=@VARBASE@/monotone}
: ${monotone_user=@MONOTONE_USER@}

name="monotone"
rcvar=${name}
command="@PREFIX@/bin/monotone"
command_args="--norc \
              --rcfile=@PKG_SYSCONFDIR@/hooks.conf \
              --db=${monotone_home}/monotone.db \
              serve 0.0.0.0 ${monotone_branches} \
              >>${monotone_home}/monotone.log 2>&1 &"
required_files="@PKG_SYSCONFDIR@/branches.conf \
                @PKG_SYSCONFDIR@/hooks.conf \
                ${monotone_home}/monotone.db"

load_rc_config $name
run_rc_command "$1"
