# $NetBSD: Makefile,v 1.34 2024/11/01 12:54:32 wiz Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module
PKGREVISION=		7

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
