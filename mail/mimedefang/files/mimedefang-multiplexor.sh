#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mimedefang-multiplexor.sh,v 1.2 2023/02/28 11:33:03 bouyer Exp $
#
# mimedefang-multiplexor handles communications between sendmail and
# the real processor
#
## only for NetBSD
# PROVIDE: mimedefang-multiplexor
# REQUIRE: LOGIN 
# BEFORE: mail
# KEYWORD: shutdown
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/pkg/bin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi


name="mimedefang_multiplexor"
rcvar="$name"

defangdir="@DEFANG_SPOOLDIR@"
command="@PREFIX@/bin/mimedefang-multiplexor"
pidfile="@VARBASE@/run/${name}.pid"
lockfile="${defangdir}/${name}.lock"
defang_user=${defang_user-"@DEFANG_USER@"}
command_args="-p ${pidfile} -o ${lockfile} -U ${defang_user}"

# default values, may be overridden on NetBSD by setting them in /etc/rc.conf
mimedefang_multiplexor_flags=${mimedefang_multiplexor_flags-\
	    "-s ${defangdir}/mimedefang-multiplexor.sock"}
mimedefang_multiplexor=${mimedefang_multiplexor:-NO}
mimedefang_multiplexor_fdlimit=${mimedefang_multiplexor_fdlimit-"128"}

sig_stop="TERM"
sig_reload="INT"
extra_commands="reload"

# A default limit of 64 (at least on NetBSD) may be too low for many
# people (eg with addional RBL rules)
SOFT_FDLIMIT=`ulimit -S -n`
HARD_FDLIMIT=`ulimit -H -n`

if [ ${mimedefang_multiplexor_fdlimit} -gt ${SOFT_FDLIMIT} ]; then
  if [ ${mimedefang_multiplexor_fdlimit} -le ${HARD_FDLIMIT} ]; then 
    ulimit -S -n ${mimedefang_multiplexor_fdlimit}
  else
    ulimit -S -n ${HARD_FDLIMIT}
  fi
fi

load_rc_config $name
run_rc_command "$1"
