# $NetBSD: Makefile,v 1.6 2017/08/24 20:03:40 adam Exp $

SYSLOG_MOD=		http
SYSLOG_MOD_TARGET=	curl
COMMENT=		Syslog-ng curl module
PKGREVISION=		2

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
