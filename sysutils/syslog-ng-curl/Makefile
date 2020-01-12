# $NetBSD: Makefile,v 1.17 2020/01/12 20:20:45 ryoon Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module
PKGREVISION=		6

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
