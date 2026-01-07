# $NetBSD: Makefile,v 1.41 2026/01/07 08:48:15 wiz Exp $

PKGREVISION= 7
.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-rest/}
COMMENT=	Free RADIUS rlm_rest module

CONFIGURE_ARGS+=	--with-rlm_rest
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_rest.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
