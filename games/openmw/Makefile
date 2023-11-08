# $NetBSD: Makefile,v 1.70 2023/11/08 13:19:20 wiz Exp $

DISTNAME=	openmw-openmw-0.47.0
PKGNAME=	${DISTNAME:S/^openmw-//1}
PKGREVISION=	29
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITLAB:=OpenMW/}
GITLAB_PROJECT=	openmw
GITLAB_RELEASE=	${PKGNAME_NOREV}

GITHUB_SUBMODULES+=	bulletphysics bullet3 3.17 extern/fetched/bullet

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://openmw.org/
COMMENT=	Recreation of The Elder Scrolls III: Morrowind game engine
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++11

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DGLOBAL_CONFIG_DIR=${PKG_SYSCONFDIR}
# System bullet is unacceptable due to OpenMW requiring
# double-precision bullet.
CMAKE_ARGS+=	-DOPENMW_USE_SYSTEM_BULLET=OFF

EGDIR=		${PREFIX}/share/examples/openmw

PKG_SYSCONFSUBDIR=	openmw

CONF_FILES+=	${EGDIR}/defaults.bin ${PKG_SYSCONFDIR}/defaults.bin
CONF_FILES+=	${EGDIR}/gamecontrollerdb.txt ${PKG_SYSCONFDIR}/gamecontrollerdb.txt
CONF_FILES+=	${EGDIR}/openmw.cfg ${PKG_SYSCONFDIR}/openmw.cfg
CONF_FILES+=	${EGDIR}/version ${PKG_SYSCONFDIR}/version

.include "options.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/unshield/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
#.include "../../devel/bullet/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/mygui/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
