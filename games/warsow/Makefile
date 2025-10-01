# $NetBSD: Makefile,v 1.2 2025/10/01 19:39:32 wiz Exp $

WARSOW_VER=	2.1.2
WARSOW_SDK=	warsow_21_sdk
DISTFILES=	${WARSOW_SDK}.tar.gz
DISTFILES+=	warsow-${WARSOW_VER}.tar.gz
PKGNAME=	warsow-${WARSOW_VER}
CATEGORIES=	games
MASTER_SITES=	http://warsow.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.warsow.net/
COMMENT=	Fast-paced first-person shooter
LICENSE=	cc-by-sa-v4.0 AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/${WARSOW_SDK}
CONFIGURE_DIR=	source/source

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake pax

# see source/source/game/CMakeLists.txt
USE_CXX_FEATURES+=	c++11

CMAKE_CONFIGURE_ARGS+=	-DQFUSION_GAME=Warsow
# for cmake 4 compatibility, until upstream fixes it
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE=1

.include "../../mk/bsd.prefs.mk"

WARSOW_ARCH=		${MACHINE_ARCH}

PLIST_SUBST+=		WARSOW_ARCH=${WARSOW_ARCH}

CHECK_PORTABILITY_SKIP+=	source/libsrcs/*
CHECK_PORTABILITY_SKIP+=	gfx/*
CHECK_PORTABILITY_SKIP+=	maps/*
CHECK_PORTABILITY_SKIP+=	models/*
CHECK_PORTABILITY_SKIP+=	textures/*

INSTALLATION_DIRS+=	bin lib/warsow/basewsw
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/72x72/apps
INSTALLATION_DIRS+=	share/icons/hicolor/96x96/apps
INSTALLATION_DIRS+=	share/icons/hicolor/192x192/apps

WARSOW_ICON_PATH=	${WRKSRC}/source/platforms/android/projects/qfusion/res

pre-configure:
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@WARSOW_ARCH@,${WARSOW_ARCH},g' \
                < ${FILESDIR}/warsow.sh.in > \
                ${WRKDIR}/warsow

do-install:
	cd ${WRKSRC}/source/source/build && \
	    ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/lib/warsow
	cd ${WRKDIR}/warsow-${PKGVERSION_NOREV}/basewsw && \
	    ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/lib/warsow/basewsw
	${INSTALL_SCRIPT} ${WRKDIR}/warsow \
	    ${DESTDIR}${PREFIX}/bin/warsow
	${INSTALL_DATA} ${WARSOW_ICON_PATH}/mipmap-mdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/warsow.png
	${INSTALL_DATA} ${WARSOW_ICON_PATH}/mipmap-hdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/72x72/apps/warsow.png
	${INSTALL_DATA} ${WARSOW_ICON_PATH}/mipmap-xhdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/96x96/apps/warsow.png
	${INSTALL_DATA} ${WARSOW_ICON_PATH}/mipmap-xxxhdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/192x192/apps/warsow.png
	${INSTALL_DATA} ${FILESDIR}/warsow.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/warsow.desktop

.include "../../devel/cmake/build.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
