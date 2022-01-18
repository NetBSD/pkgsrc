# $NetBSD: Makefile,v 1.7 2022/01/18 15:23:24 tnn Exp $

PKGNAME=	nxengine-evo-2.6.5.1
PKGREVISION=	1
CATEGORIES=	games
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	nxengine-evo.tar.gz
DISTFILES+=	cavestoryen.zip
SITES.nxengine-evo.tar.gz= \
	-https://github.com/nxengine/nxengine-evo/archive/v2.6.5-1.tar.gz
SITES.cavestoryen.zip= \
	-https://www.cavestory.org/downloads/cavestoryen.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/nxengine/nxengine-evo
COMMENT=	Complete rewrite of the platform-adventure game Cave Story
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/nxengine-evo-2.6.5-1

ALL_ENV+=	SDL2DIR=${PREFIX}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DCMAKE_SYSTEM_PREFIX_PATH=${PREFIX}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/256x256/apps
INSTALLATION_DIRS+=	share/nxengine/data

pre-configure:
	${RM} -rf ${WRKSRC}/deps/spdlog
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
	    < ${FILESDIR}/nxengine-evo.sh.in > \
	    ${WRKDIR}/nxengine-evo.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nxengine-evo \
	    ${DESTDIR}${PREFIX}/share/nxengine/nxengine-evo
	${INSTALL_SCRIPT} ${WRKDIR}/nxengine-evo.sh \
	    ${DESTDIR}${PREFIX}/bin/nxengine-evo
	${INSTALL_DATA} ${WRKSRC}/platform/xdg/org.nxengine.nxengine_evo.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/platform/xdg/org.nxengine.nxengine_evo.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	cd ${WRKDIR}/CaveStory && ${PAX} -rw -pp . \
	    ${DESTDIR}${PREFIX}/share/nxengine
	cd ${WRKSRC}/data && ${PAX} -rw -pp . \
	    ${DESTDIR}${PREFIX}/share/nxengine/data
	cd ${DESTDIR}${PREFIX}/share/nxengine && ${WRKSRC}/nxextract

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
