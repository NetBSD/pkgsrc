#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmd.sh,v 1.1 2014/09/13 16:49:27 asau Exp $
#
# PROVIDE: slurmd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="slurmd"
rcvar=${name}
command="@PREFIX@/sbin/slurmd"

slurmd_user="slurm"

load_rc_config $name
run_rc_command "$1"
