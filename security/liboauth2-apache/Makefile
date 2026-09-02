# $NetBSD: Makefile,v 1.2 2026/09/02 19:04:17 wiz Exp $

PKGREVISION= 1
.include "../../security/liboauth2/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-apache-/}

COMMENT=		OAuth 2.x and OpenID Connect C library - Apache specific lib

PKGCONFIG_OVERRIDE+=	liboauth2_apache.pc.in

BUILD_TARGET=		liboauth2_apache.la

INSTALLATION_DIRS+=	include/oauth2 lib/pkgconfig

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/liboauth2_apache.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/oauth2/apache.h \
		${DESTDIR}${PREFIX}/include/oauth2
	${INSTALL_DATA} ${WRKSRC}/liboauth2_apache.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

USE_APR=		YES
.include "../../mk/apache.mk"
.include "../../security/liboauth2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
