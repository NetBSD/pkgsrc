#!@SH@
#
# $NetBSD: sharedindexupdate.sh,v 1.1.1.1 2004/07/14 20:05:50 jlam Exp $
#
# This script updates the index of shared folders on the system and is
# only needed if Courier-IMAP or SqWebMail used to serve mail and shared
# folders are used.  If so, then this script should be run regularly as a
# system process to ensure the shared folder index is kept up-to-date.
#
# The courier-auth package must be separately installed to provide the
# "authenumerate" program used in this script.

sysconfdir="@PKG_SYSCONFDIR@"
sbindir="@PREFIX@/sbin"
datadir="@DATADIR@"

@RM@ -rf $sysconfdir/shared.tmp
@MKDIR@ $sysconfdir/shared.tmp || exit 1

@TEST@ -x $sbindir/authenumerate || exit 1
$sbindir/authenumerate > $sysconfdir/shared.tmp/.tmplist || exit 1
$datadir/sharedindexsplit $sysconfdir/shared.tmp 1 < $sysconfdir/shared.tmp/.tmplist || exit 1
@RM@ -f $sysconfdir/shared.tmp/.tmplist
$datadir/sharedindexinstall
