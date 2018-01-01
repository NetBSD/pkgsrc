# $NetBSD: Makefile,v 1.2 2018/01/01 21:18:47 adam Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-rest/}
COMMENT=		Free RADIUS rlm_rest module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_rest

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_rest.so ${DESTDIR}${PREFIX}/lib

.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
