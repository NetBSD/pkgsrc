#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfexecd.sh,v 1.1 2011/02/06 18:44:23 pettai Exp $

# PROVIDE: cfexecd

. /etc/rc.subr

name="cfexecd"
rcvar=$name
command="@PREFIX@/sbin/cf-execd"
required_files="/var/cfengine/inputs/promises.cf"

load_rc_config $name
run_rc_command "$1"
