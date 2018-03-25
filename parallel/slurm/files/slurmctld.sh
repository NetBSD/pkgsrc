#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmctld.sh,v 1.2 2018/03/25 14:55:30 bacon Exp $
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
