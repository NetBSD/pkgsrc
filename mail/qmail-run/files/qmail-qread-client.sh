#!@SH@
#
# $NetBSD: qmail-qread-client.sh,v 1.3 2014/12/06 22:14:27 schmonz Exp $
#
# @PKGNAME@ client program to allow local non-root users to see
# the queue. Requires that the corresponding server program be running.
# From Steinar Haug.
#

exec @UCSPI_TCP_PREFIX@/bin/tcpclient -RHl0 -- 127.0.0.1 20025 @SH@ -c 'exec @CAT@ <&6'
