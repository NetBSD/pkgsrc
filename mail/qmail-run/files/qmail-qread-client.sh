#!@SH@
#
# $NetBSD: qmail-qread-client.sh,v 1.4 2015/11/25 12:51:30 jperkin Exp $
#
# @PKGNAME@ client program to allow local non-root users to see
# the queue. Requires that the corresponding server program be running.
# From Steinar Haug.
#

exec @PREFIX@/bin/tcpclient -RHl0 -- 127.0.0.1 20025 @SH@ -c 'exec @CAT@ <&6'
