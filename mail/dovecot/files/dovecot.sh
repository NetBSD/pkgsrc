#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dovecot.sh,v 1.4 2008/07/10 00:54:30 jnemeth Exp $
#

# PROVIDE: dovecot
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dovecot"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
extra_commands="reload"

dovecot_fdlimit=${dovecot_fdlimit-"768"}

# A default limit of 64 (at least on NetBSD) may be too low for many people
SOFT_FDLIMIT=`ulimit -S -n`
HARD_FDLIMIT=`ulimit -H -n`

if [ ${dovecot_fdlimit} -gt ${SOFT_FDLIMIT} ]; then
  if [ ${dovecot_fdlimit} -le ${HARD_FDLIMIT} ]; then
    ulimit -S -n ${dovecot_fdlimit}
  else
    ulimit -S -n ${HARD_FDLIMIT}
  fi
fi

load_rc_config $name
run_rc_command "$1"
