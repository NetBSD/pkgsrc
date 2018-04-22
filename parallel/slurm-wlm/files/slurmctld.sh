#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmctld.sh,v 1.1 2018/04/22 21:31:09 bacon Exp $
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
