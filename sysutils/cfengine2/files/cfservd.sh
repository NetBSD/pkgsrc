#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfservd.sh,v 1.1 2004/08/19 17:13:36 ben Exp $

# PROVIDE: cfservd
# REQUIRE: cfexecd

. /etc/rc.subr

name="cfservd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="/var/cfengine/inputs/cfservd.conf"

load_rc_config $name
run_rc_command "$1"
