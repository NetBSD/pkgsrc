# $NetBSD: Makefile,v 1.13 2018/12/13 19:52:23 adam Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module
PKGREVISION=		2

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
