# $NetBSD: Makefile,v 1.12 2020/03/30 19:36:39 joerg Exp $

DISTNAME=	devilutionx-1.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=diasurgical/}
GITHUB_PROJECT=	devilutionX

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/diasurgical/devilutionX
COMMENT=	Port of the RPG Diablo for modern operating systems
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++14

# std::make_unique, etc
GCC_REQD+=	5

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DASAN=OFF -DUBSAN=OFF
CMAKE_ARGS+=	-DDEBUG=OFF
CMAKE_ARGS+=	-DFASTER=OFF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CXXFLAGS+=	-DO_LARGEFILE=0 -Dstat64=stat -Dlstat64=lstat -Dlseek64=lseek -Doff64_t=off_t -Dfstat64=fstat -Dftruncate64=ftruncate
.endif

# /usr/include/g++/cstdio:176:11: error: '::vfscanf' has not been declared
# No idea.
CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/devilutionx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/devilutionx.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/16.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/devilutionx.png
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/Diablo_32.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/devilutionx.png
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/Diablo_48.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/devilutionx.png

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
