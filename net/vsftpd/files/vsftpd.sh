#!/bin/sh
#
# $NetBSD: vsftpd.sh,v 1.2 2004/11/11 13:51:31 xtraeme Exp $
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
