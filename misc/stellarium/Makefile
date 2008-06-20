# $NetBSD: Makefile,v 1.25 2008/06/20 01:09:27 joerg Exp $

DISTNAME=	stellarium-0.9.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
CM_ARGS+= -D CMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CM_ARGS+= -D FreeType2_INCLUDE_DIR:PATH=${LOCALBASE}/include/freetype2
CM_ARGS+= -D FreeType2_LIBRARIES:PATH=${LOCALBASE}/lib
CM_ARGS+= -D SDLMIXER_INCLUDE_DIR:PATH=${LOCALBASE}/include/SDL

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} cmake ${CM_ARGS} .)

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
