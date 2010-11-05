#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfserverd.sh,v 1.1.1.1 2010/11/05 13:57:21 pettai Exp $

# PROVIDE: cfserverd

. /etc/rc.subr

name="cfserverd"
rcvar=$name
command="@PREFIX@/sbin/cf-serverd"
required_files="/var/cfengine/inputs/site.cf"

load_rc_config $name
run_rc_command "$1"
