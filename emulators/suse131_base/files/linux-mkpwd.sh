#!/bin/sh
#
# $NetBSD: linux-mkpwd.sh,v 1.1 2013/12/05 11:42:14 obache Exp $
#

######################################################################
#
# NAME
#	@LINUX_BASE@-mkpwd -- create passwd/group files for COMPAT_LINUX
#
# SYNOPSYS
#	@LINUX_BASE@-mkpwd
#
# DESCRIPTION
#	@LINUX_BASE@-mkpwd creates passwd and group files and databases
#	for a COMPAT_LINUX installation based on the files found in
#	/etc, e.g. /etc/passwd, /etc/master.passwd, /etc/group, etc.
#
######################################################################

SRCDIR=/etc
DESTDIR=@EMULDIR@/etc

[ -d $DESTDIR ] || exit 1

umask 22
cd $DESTDIR
cp -f $SRCDIR/passwd .
sed s/^wheel:/root:/ <$SRCDIR/group >group

umask 77
awk -F: '{print($1":"$2":0:0:10000::::")}' <$SRCDIR/master.passwd >shadow
sed s/^wheel:/root:/ <$SRCDIR/group |
awk -F: '{print($1":*:root:root")}' >gshadow

exit 0
