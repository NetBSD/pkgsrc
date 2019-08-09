# $NetBSD: Makefile,v 1.1 2019/08/09 16:26:09 nia Exp $

DISTNAME=	openmw-0.45.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenMW/}
GITHUB_TAG=	openmw-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://openmw.org/
COMMENT=	Recreation of The Elder Scrolls III: Morrowind game engine
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

# C++11
GCC_REQD+=	4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DGLOBAL_CONFIG_DIR=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/openmw

PKG_SYSCONFSUBDIR=	openmw

CONF_FILES+=	${EGDIR}/gamecontrollerdb.txt ${PKG_SYSCONFDIR}/gamecontrollerdb.txt
CONF_FILES+=	${EGDIR}/gamecontrollerdb_204.txt ${PKG_SYSCONFDIR}/gamecontrollerdb_204.txt
CONF_FILES+=	${EGDIR}/gamecontrollerdb_205.txt ${PKG_SYSCONFDIR}/gamecontrollerdb_205.txt
CONF_FILES+=	${EGDIR}/openmw-cs.cfg ${PKG_SYSCONFDIR}/openmw-cs.cfg
CONF_FILES+=	${EGDIR}/openmw.cfg ${PKG_SYSCONFDIR}/openmw.cfg
CONF_FILES+=	${EGDIR}/settings-default.cfg ${PKG_SYSCONFDIR}/settings-default.cfg
CONF_FILES+=	${EGDIR}/version ${PKG_SYSCONFDIR}/version

.include "options.mk"
.include "../../archivers/unshield/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/mygui/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
