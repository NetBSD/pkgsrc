# $NetBSD: Makefile,v 1.18 2025/09/10 22:01:06 charlotte Exp $

DISTNAME=	lugaru-${VERSION}
VERSION=	1.2
PKGREVISION=	13
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/osslugaru/lugaru/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://osslugaru.gitlab.io/
COMMENT=	Cross-platform third-person action game from Wolfire
LICENSE=	gnu-gpl-v2 AND cc-by-sa-v3.0 AND cc-by-sa-v4.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_INSTALL=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
