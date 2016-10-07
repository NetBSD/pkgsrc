# $NetBSD: Makefile,v 1.2 2016/10/07 18:26:11 adam Exp $

SYSLOG_MOD=		http
SYSLOG_MOD_TARGET=	curl
COMMENT=		Syslog-ng curl module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
