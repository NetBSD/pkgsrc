#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mimedefang.sh,v 1.1 2004/03/07 11:18:33 markd Exp $
#
# mimedefang does "in-stream" spam and virus checking using 
# sendmail's MailFilter interfaces.
#
## only for NetBSD
# PROVIDE: mimedefang
# REQUIRE: LOGIN mimedefang-multiplexor
# BEFORE: mail
# KEYWORD: shutdown
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/pkg/bin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

defangdir="@DEFANG_SPOOLDIR@"

name="mimedefang"
rcvar=$name
command="@PREFIX@/bin/mimedefang"
pidfile="${defangdir}/${name}.pid"
mimedefang_user=${mimedefang_user-"@DEFANG_USER@"}
command_args="-P ${pidfile}"

# default values, may be overridden on NetBSD by setting them in /etc/rc.conf
mimedefang_flags=${mimedefang_flags-"-p ${defangdir}/mimedefang.sock \
			-m ${defangdir}/mimedefang-multiplexor.sock"}

mimedefang=${mimedefang:-NO}
mimedefang_fdlimit=${mimedefang_fdlimit-"128"}

# A default limit of 64 (at least on NetBSD) may be too low for many
# people (eg with addional RBL rules)
SOFT_FDLIMIT=`ulimit -S -n`
HARD_FDLIMIT=`ulimit -H -n`

if [ ${mimedefang_fdlimit} -gt ${SOFT_FDLIMIT} ]; then
  if [ ${mimedefang_fdlimit} -le ${HARD_FDLIMIT} ]; then 
    ulimit -S -n ${mimedefang_fdlimit}
  else
    ulimit -S -n ${HARD_FDLIMIT}
  fi
fi

load_rc_config $name
run_rc_command "$1"
