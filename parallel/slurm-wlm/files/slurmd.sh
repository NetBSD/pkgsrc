#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmd.sh,v 1.1 2018/04/22 21:31:09 bacon Exp $
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
