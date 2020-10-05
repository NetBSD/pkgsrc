#!@SH@
#
# $NetBSD: qmail-qread-client.sh,v 1.6 2020/10/05 12:17:20 schmonz Exp $
#
# @PKGNAME@ client program to allow local non-root users to see
# the queue. Requires that the corresponding server program be running.
# From Steinar Haug.
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

# User-settable rc.conf variables and their default values
# (shared with the qmailqread service):
: ${qmailqread_tcphost:="127.0.0.1"}
: ${qmailqread_tcpport:="20025"}

if [ -f /etc/rc.subr ]; then
	load_rc_config qmailqread
fi

exec @PREFIX@/bin/tcpclient -RHl0 -- ${qmailqread_tcphost} ${qmailqread_tcpport} @SH@ -c 'exec @CAT@ <&6'
