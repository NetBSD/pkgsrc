#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: arlad.sh,v 1.5 2005/03/15 15:58:52 wennmach Exp $
#
# PROVIDE: arlad
# REQUIRE: beforemountlkm
# KEYWORD: shutdown

. /etc/rc.subr

name="arlad"
rcvar=$name
command="/usr/pkg/libexec/${name}"
command_args="-z /dev/nnpfs0"
required_files="/dev/nnpfs0"

load_rc_config $name
run_rc_command "$1"
