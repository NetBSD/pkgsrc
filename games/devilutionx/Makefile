# $NetBSD: Makefile,v 1.35 2025/08/21 20:13:19 triaxx Exp $

DISTNAME=	devilutionx-1.2.1
PKGREVISION=	14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=diasurgical/}
GITHUB_PROJECT=	devilutionX

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/diasurgical/devilutionX
COMMENT=	Port of the RPG Diablo for modern operating systems
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
TOOL_DEPENDS=	dos2unix-[0-9]*:../../converters/dos2unix

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	unique_ptr

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DASAN=OFF -DUBSAN=OFF
CMAKE_CONFIGURE_ARGS+=	-DDEBUG=OFF
CMAKE_CONFIGURE_ARGS+=	-DVERSION_NUM=${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DDEVILUTIONX_SYSTEM_LIBSODIUM=ON
CMAKE_CONFIGURE_ARGS+=	-DDEVILUTIONX_STATIC_LIBSODIUM=OFF

LDFLAGS.SunOS+=	-lsocket

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/512x512/apps

pre-patch:
	dos2unix ${WRKSRC}/CMakeLists.txt

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
# Install macOS bundle
MACOS_BUNDLE_PREFIX=	${PREFIX}/Applications
INSTALLATION_DIRS+=	${MACOS_BUNDLE_PREFIX}/devilutionx.app/Contents/MacOS
INSTALLATION_DIRS+=	${MACOS_BUNDLE_PREFIX}/devilutionx.app/Contents/Resources

PLIST_SRC=		PLIST.bundle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/devilutionx.app/Contents/MacOS/devilutionx \
		${DESTDIR}${MACOS_BUNDLE_PREFIX}/devilutionx.app/Contents/MacOS/devilutionx
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/devilutionx.app/Contents/Info.plist \
		${DESTDIR}${MACOS_BUNDLE_PREFIX}/devilutionx.app/Contents/Info.plist
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/devilutionx.app/Contents/Resources/AppIcon.icns \
		${DESTDIR}${MACOS_BUNDLE_PREFIX}/devilutionx.app/Contents/Resources/AppIcon.icns
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/devilutionx.app/Contents/Resources/CharisSILB.ttf \
		${DESTDIR}${MACOS_BUNDLE_PREFIX}/devilutionx.app/Contents/Resources/CharisSILB.ttf
.else
pre-configure:
	${MKDIR} -p ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/devilutionx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/devilutionx.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/512x512/apps/devilutionx.png
.endif

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
