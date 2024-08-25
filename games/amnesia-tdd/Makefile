# $NetBSD: Makefile,v 1.9 2024/08/25 06:18:42 wiz Exp $

DISTNAME=	amnesia-tdd-0.3.2
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=shamazmazum/}
GITHUB_PROJECT=	AmnesiaTheDarkDescent
GITHUB_TAG=	d3abfdd93bb650b12aa224ecc6f6aace42424189

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://frictionalgames.com/
COMMENT=	Amnesia: The Dark Descent
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DSYSTEMWIDE_RESOURCES=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEMWIDE_RESOURCES_LOCATION="${PREFIX}/share/amnesia-tdd"
CMAKE_CONFIGURE_ARGS+=	./amnesia/src

USE_CXX_FEATURES+=	c++11
FORCE_CXX_STD=		c++11

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} != "x86_64"
# Disables SSE use in HPL2/dependencies/Newton
CFLAGS+=		-D_SCALAR_ARITHMETIC_ONLY=1
.endif

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
