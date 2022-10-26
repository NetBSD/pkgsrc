# $NetBSD: Makefile,v 1.26 2022/10/26 10:32:01 wiz Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module
PKGREVISION=		3

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
