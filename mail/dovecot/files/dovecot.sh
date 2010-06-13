#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dovecot.sh,v 1.6 2010/06/13 23:01:50 erh Exp $
#

# PROVIDE: dovecot
# REQUIRE: DAEMON LOGIN ntpdate

. /etc/rc.subr

name="dovecot"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
extra_commands="reload"

load_rc_config $name
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

run_rc_command "$1"
