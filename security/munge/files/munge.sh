#!@RCD_SCRIPTS_SHELL@
# $NetBSD: munge.sh,v 1.3 2024/05/18 22:31:06 bacon Exp $
#
# PROVIDE: munge
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="munge"
rcvar=${name}
command="@PREFIX@/sbin/munged"
munge_user="munge"
munge_group="munge"

load_rc_config $name
run_rc_command "$1"
