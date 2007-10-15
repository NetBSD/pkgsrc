#!@SH@
#
# $NetBSD: sharedindexupdate.sh,v 1.4 2007/10/15 15:37:09 jlam Exp $
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

# split on the first character of the username
@TEST@ -x $sbindir/authenumerate || exit 1
$sbindir/authenumerate -s > $sysconfdir/shared.tmp/.tmplist || exit 1
$sbindir/sharedindexsplit $sysconfdir/shared.tmp 1 < $sysconfdir/shared.tmp/.tmplist || exit 1
@RM@ -f $sysconfdir/shared.tmp/.tmplist
$sbindir/sharedindexinstall
