#!@SH@
#
# $NetBSD: tinydyndns-pop3d.sh,v 1.3 2020/10/30 10:23:42 schmonz Exp $
#
# @PKGNAME@ fake POP3 server.

exec @PREFIX@/bin/nopop3d "$@"
