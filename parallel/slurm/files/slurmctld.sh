#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmctld.sh,v 1.1 2014/09/13 16:49:27 asau Exp $
#
# PROVIDE: slurmctld
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="slurmctld"
rcvar=${name}
command="@PREFIX@/sbin/slurmctld"

load_rc_config $name
run_rc_command "$1"
