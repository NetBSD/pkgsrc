# $NetBSD: Makefile,v 1.43 2026/11/27 11:01:43 adam Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
