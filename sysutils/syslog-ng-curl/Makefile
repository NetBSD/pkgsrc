# $NetBSD: Makefile,v 1.4 2017/01/10 18:54:55 fhajny Exp $

SYSLOG_MOD=		http
SYSLOG_MOD_TARGET=	curl
COMMENT=		Syslog-ng curl module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
