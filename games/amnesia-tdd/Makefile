# $NetBSD: Makefile,v 1.16 2025/08/30 22:45:04 wiz Exp $

DISTNAME=	amnesia-tdd-0.3.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=shamazmazum/}
GITHUB_PROJECT=	AmnesiaTheDarkDescent
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://frictionalgames.com/
COMMENT=	Amnesia: The Dark Descent
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

CMAKE_CONFIGURE_ARGS+=	-DSYSTEMWIDE_RESOURCES=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEMWIDE_RESOURCES_LOCATION="${PREFIX}/share/amnesia-tdd"
CMAKE_CONFIGURE_ARGS+=	./amnesia/src

USE_CXX_FEATURES+=	c++11
FORCE_CXX_STD=		c++11

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
# HPL2/dependencies/Newton
CFLAGS+=		-msse
.endif

.include "../../devel/cmake/build.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
