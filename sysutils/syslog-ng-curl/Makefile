# $NetBSD: Makefile,v 1.27 2022/12/15 10:09:43 wiz Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
