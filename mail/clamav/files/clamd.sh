#!/bin/sh
#
# $NetBSD: clamd.sh,v 1.2 2004/03/30 00:32:29 xtraeme Exp $
#
# clamd does anti-virus checking.
#
## only for NetBSD
# PROVIDE: clamd
# REQUIRE: LOGIN
##	only because it might be used by mimedefang
# BEFORE: mail
# KEYWORD: shutdown
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:@PREFIX@/sbin:@PREFIX@/bin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="clamd"
rcvar=$name
required_files="@PKG_SYSCONFDIR@/clamav.conf"
command="@PREFIX@/sbin/${name}"
pidfile=$(@AWK@ '/^#/ {next}; /PidFile/ {print $2}' ${required_files})
socket=$(@AWK@ '/^#/ {next}; /LocalSocket/ {print $2}' ${required_files})
clamd_user=$(@AWK@ '/^#/ {next}; /User/ {print $2}' ${required_files})

start_precmd="clamd_precmd"
stop_postcmd="clamd_postcmd"

clamd_precmd()
{
    @RM@ -f ${socket}
    @TOUCH@ ${pidfile}
    @CHOWN@ ${clamd_user} ${pidfile}
}

clamd_postcmd()
{
    if [ -f "${pidfile}" ]; then
        @RM@ -f ${pidfile}
    fi
    
    if [ -e "${socket}" ]; then
        @RM@ -f ${socket}
    fi
}
                                                                                     
load_rc_config $name
run_rc_command "$1"
