# $NetBSD: Makefile,v 1.25 2021/12/08 16:06:37 adam Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module
PKGREVISION=		2

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
