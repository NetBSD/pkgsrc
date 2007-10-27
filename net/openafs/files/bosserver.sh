#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bosserver.sh,v 1.2 2007/10/27 09:11:10 gendalia Exp $
#
# PROVIDE: bosserver
# BEFORE: arlad
# REQUIRE: NETWORK

. /etc/rc.subr

name="bosserver"
rcvar=$name
hostname=`@HOSTNAME_CMD@`
command="@PREFIX@/sbin/$name"
start_precmd="ulimit -S -d 1048576;ulimit -S -c unlimited"
stop_precmd="@PREFIX@/bin/bos shutdown $hostname -local -wait"

load_rc_config $name
run_rc_command "$1"
