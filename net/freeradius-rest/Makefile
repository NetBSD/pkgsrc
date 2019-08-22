# $NetBSD: Makefile,v 1.11 2019/08/22 12:23:39 ryoon Exp $

PKGREVISION= 2
.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-rest/}
COMMENT=	Free RADIUS rlm_rest module

CONFIGURE_ARGS+=	--with-rlm_rest
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_rest.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
