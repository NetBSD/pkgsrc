# $NetBSD: Makefile,v 1.30 2009/03/09 13:24:44 hasso Exp $

DISTNAME=	stellarium-0.10.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
USE_CMAKE=		yes

CMAKE_ARGS+= -D FreeType2_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CMAKE_ARGS+= -D FreeType2_LIBRARIES:PATH=${BUILDLINK_PREFIX.freetype2}/lib
CMAKE_ARGS+= -D SDLMIXER_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.SDL}/include/SDL

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
