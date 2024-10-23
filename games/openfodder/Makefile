# $NetBSD: Makefile,v 1.1 2024/10/23 08:30:29 nia Exp $

DISTNAME=	openfodder-1.9.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=openfodder/}

GITHUB_SUBMODULES+=	OpenFodder data \
			070a6086c62164e859fc3274b75b5f536fa9d902 \
			Run

GITHUB_SUBMODULES+=	OpenFodder scripts \
			dad04730860bcdd1189aa8562860e379b0f5d783 \
			Run/Scripts

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openfodder.com/
COMMENT=	Action-strategy 2D military shooting game
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config pax
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Source/ResourceMan.cpp
SUBST_VARS.paths=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/OpenFodder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/openfodder \
		${DESTDIR}${PREFIX}/bin/openfodder
	${INSTALL_DATA} ${WRKSRC}/FreeDesktop/openfodder.desktop \
		${DESTDIR}${PREFIX}/share/applications/openfodder.desktop
	${INSTALL_DATA} ${WRKSRC}/FreeDesktop/openfodder.png \
		${DESTDIR}${PREFIX}/share/pixmaps/openfodder.png
	cd ${WRKSRC}/Run && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/OpenFodder

.include "../../devel/cmake/build.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
