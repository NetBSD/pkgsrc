#!/bin/sh
#
# $NetBSD: vsftpd.sh,v 1.1 2003/05/09 23:31:39 salo Exp $
#

# PROVIDE: vsftpd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="vsftpd"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="&"
required_dirs="/var/chroot/vsftpd"
required_files="@PKG_SYSCONFDIR@/vsftpd.conf"

load_rc_config $name
run_rc_command "$1"
