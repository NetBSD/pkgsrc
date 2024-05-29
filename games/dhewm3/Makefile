# $NetBSD: Makefile,v 1.26 2024/05/29 16:32:33 adam Exp $

DISTNAME=	dhewm3-1.5.1-src
PKGNAME=	${DISTNAME:S/-src//1}
PKGREVISION=	16
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=dhewm/}
GITHUB_PROJECT=	dhewm3
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dhewm3.org/
COMMENT=	Source port of the original Doom 3
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c gnu++11

USE_CXX_FEATURES+=	c++11

CONFIGURE_DIRS+=	neo

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DDEDICATED=ON

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DIOAPI_NO_64
CXXFLAGS+=	-DIOAPI_NO_64
.endif

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/neo/sys/linux/setup/image/doom3.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/dhewm3.desktop \
	    ${DESTDIR}${PREFIX}/share/applications

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
