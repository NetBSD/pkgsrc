# $NetBSD: Makefile,v 1.23 2021/09/16 09:22:47 wiz Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
