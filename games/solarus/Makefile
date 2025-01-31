# $NetBSD: Makefile,v 1.76 2025/01/31 08:07:01 wiz Exp $

VERSION=	1.6.5
DISTNAME=	solarus-${VERSION}-src
PKGNAME=	${DISTNAME:S/-src//1}
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITLAB:=solarus-games/}
GITLAB_PROJECT=	solarus
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.solarus-games.org/solarus/
COMMENT=	Open-source Zelda-like 2D game engine licensed under GPL
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}
USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	-lsocket -lnsl

USE_CXX_FEATURES+=	c++11
FORCE_CXX_STD=		c++11

CXXFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0.14
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_ttf+=	SDL2_ttf>=2.0.12
.include "../../fonts/SDL2_ttf/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_image+=	SDL2_image>=2.0.0
.include "../../graphics/SDL2_image/buildlink3.mk"
BUILDLINK_API_DEPENDS.glm+=	glm>=1.0.0
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
