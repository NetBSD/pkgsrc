DISTNAME=	suika3-26.04.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=awemorris/}
GITHUB_PROJECT=	suika3
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	awe@noctvm.io
HOMEPAGE=	https://github.com/awemorris/suika3
COMMENT=	2D game engine with DSL for visual novels
LICENSE=	zlib

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

DEPENDS+=	noto-fonts-[0-9]*:../../fonts/noto-fonts

.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DSUIKA_DIR_DOCS="share/doc/suika3"
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_DIR_GAME="share/examples/suika3"
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_AOTCOMP=ON
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_BYTECOMP=ON
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_DIST=ON
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_I18N=ON
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_INSTALL=ON
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_PACK=ON

INSTALLATION_DIRS+=	share/examples/suika3/game/system/font

# Create a symlink to NotoSans.
post-build:
	${MKDIR} ${DESTDIR}${PREFIX}/share/examples/suika3/game/system/font
	${LN} -s ${PREFIX}/share/fonts/X11/TTF/NotoSans-Regular.ttf \
		${DESTDIR}${PREFIX}/share/examples/suika3/game/system/font/rounded-l-mplus-1c-bold.ttf

.include "../../archivers/brotli/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
