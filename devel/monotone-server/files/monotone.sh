#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: monotone.sh,v 1.3 2006/02/21 16:09:16 jmmv Exp $
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
              --confdir=@PKG_SYSCONFDIR@ \
              --db=${monotone_home}/monotone.db \
              --rcfile=@PKG_SYSCONFDIR@/hooks.conf \
              serve ${monotone_branches} \
              >>${monotone_home}/monotone.log 2>&1 &"
required_dirs="@PKG_SYSCONFDIR@/keys"
required_files="@PKG_SYSCONFDIR@/branches.conf \
                @PKG_SYSCONFDIR@/hooks.conf \
                @PKG_SYSCONFDIR@/read-permissions \
                @PKG_SYSCONFDIR@/write-permissions \
                ${monotone_home}/monotone.db"
start_precmd="monotone_start_precmd"

monotone_start_precmd() {
	echo "=> Session started at `date`" >>${monotone_home}/monotone.log
}

load_rc_config $name
run_rc_command "$1"
