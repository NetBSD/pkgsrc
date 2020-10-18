#!@SH@
#
# $NetBSD: tinydyndns-call-update.sh,v 1.1 2020/10/18 12:41:33 schmonz Exp $
#
# @PKGNAME@ program to update DNS record for POP3 authenticated user

if [ $# -eq 0 ]; then
	@ECHO@ "usage: $0 program" >&2
	exit 1
fi

@ECHO@ "login: ${USER}: ${TCPREMOTEIP}" >&7
cd @PKG_SYSCONFDIR@
@PREFIX@/bin/setlock data.cdb \
	@PREFIX@/bin/tinydyndns-update ${USER}.$(@HEAD@ -1 domain) ${TCPREMOTEIP} >&7 \
	2>&1
exec "$@"
