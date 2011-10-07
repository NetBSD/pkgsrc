#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vsftpd.sh,v 1.3 2011/10/07 22:37:05 shattered Exp $
#

# PROVIDE: vsftpd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="vsftpd"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="&"
required_dirs="@VARBASE@/chroot/vsftpd"
required_files="@PKG_SYSCONFDIR@/vsftpd.conf"

load_rc_config $name
run_rc_command "$1"
