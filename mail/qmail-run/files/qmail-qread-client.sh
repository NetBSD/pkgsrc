#!@SH@
#
# $NetBSD: qmail-qread-client.sh,v 1.2 2004/08/03 08:59:24 schmonz Exp $
#
# @PKGNAME@ client program to allow local non-root users to see
# the queue. Requires that the corresponding server program be running.
# From Steinar Haug.
#

exec @LOCALBASE@/bin/tcpclient -RHl0 -- 127.0.0.1 20025 @SH@ -c 'exec @CAT@ <&6'
