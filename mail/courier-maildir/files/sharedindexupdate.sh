#!@SH@
#
# $NetBSD: sharedindexupdate.sh,v 1.2 2005/02/18 22:12:50 jlam Exp $
#
# This script updates the index of shared folders on the system and is
# only needed if Courier-IMAP or SqWebMail used to serve mail and shared
# folders are used.  If so, then this script should be run regularly as a
# system process to ensure the shared folder index is kept up-to-date.
#
# The courier-authlib package must be separately installed to provide the
# "authenumerate" program used in this script.

sysconfdir="@PKG_SYSCONFDIR@"
sbindir="@PREFIX@/sbin"

@RM@ -rf $sysconfdir/shared.tmp
@MKDIR@ $sysconfdir/shared.tmp || exit 1

@TEST@ -x $sbindir/authenumerate || exit 1
$sbindir/authenumerate > $sysconfdir/shared.tmp/.tmplist || exit 1
$sysconfdir/sharedindexsplit $sysconfdir/shared.tmp 1 < $sysconfdir/shared.tmp/.tmplist || exit 1
@RM@ -f $sysconfdir/shared.tmp/.tmplist
$sysconfdir/sharedindexinstall
