# $NetBSD: Makefile,v 1.23 2008/01/18 05:08:37 tnn Exp $

DISTNAME=	stellarium-0.9.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
CM_ARGS+= -D CMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CM_ARGS+= -D FreeType2_INCLUDE_DIR:PATH=${LOCALBASE}/include/freetype2
CM_ARGS+= -D FreeType2_LIBRARIES:PATH=${LOCALBASE}/lib

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} cmake ${CM_ARGS} .)

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
