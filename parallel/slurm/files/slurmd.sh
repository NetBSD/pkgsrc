#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmd.sh,v 1.2 2018/03/25 14:55:30 bacon Exp $
#
# PROVIDE: slurmd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="slurmd"
rcvar=${name}
command="@PREFIX@/sbin/slurmd"

slurmd_user="root"

load_rc_config $name
run_rc_command "$1"
