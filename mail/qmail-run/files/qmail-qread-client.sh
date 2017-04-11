#!@SH@
#
# $NetBSD: qmail-qread-client.sh,v 1.5 2017/04/11 14:04:37 schmonz Exp $
#
# @PKGNAME@ client program to allow local non-root users to see
# the queue. Requires that the corresponding server program be running.
# From Steinar Haug.
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config qmailqread
fi

: ${qmailqread_tcphost:="127.0.0.1"}
: ${qmailqread_tcpport:="20025"}

exec @PREFIX@/bin/tcpclient -RHl0 -- ${qmailqread_tcphost} ${qmailqread_tcpport} @SH@ -c 'exec @CAT@ <&6'
