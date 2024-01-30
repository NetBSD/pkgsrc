# $NetBSD: Makefile,v 1.30 2024/01/30 14:21:53 ryoon Exp $

DISTNAME=	devilutionx-1.2.1
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=diasurgical/}
GITHUB_PROJECT=	devilutionX

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/diasurgical/devilutionX
COMMENT=	Port of the RPG Diablo for modern operating systems
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
TOOL_DEPENDS=	dos2unix-[0-9]*:../../converters/dos2unix

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	unique_ptr

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DASAN=OFF -DUBSAN=OFF
CMAKE_ARGS+=	-DDEBUG=OFF
CMAKE_ARGS+=	-DVERSION_NUM=${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DDEVILUTIONX_SYSTEM_LIBSODIUM=ON
CMAKE_ARGS+=	-DDEVILUTIONX_STATIC_LIBSODIUM=OFF

LDFLAGS.SunOS+=	-lsocket

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/512x512/apps

pre-patch:
	dos2unix ${WRKSRC}/CMakeLists.txt

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/devilutionx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/devilutionx.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/512x512/apps/devilutionx.png

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
