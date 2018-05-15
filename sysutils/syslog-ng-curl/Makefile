# $NetBSD: Makefile,v 1.11 2018/05/15 13:06:19 fhajny Exp $

SYSLOG_MOD=		http
COMMENT=		Syslog-ng curl module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
