# $NetBSD: Makefile,v 1.14 2022/06/30 11:18:25 nia Exp $

DISTNAME=	gemrb-0.9.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=gemrb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gemrb.org/
COMMENT=	Reimplementation of the Infinity Engine used in 2D RPGs by Bioware
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

GCC_REQD+=	4.7 # -std=gnu++11

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/gemrb
LDFLAGS+=	-lm # ldexpf

CMAKE_ARGS+=	-DDISABLE_WERROR=ON
CMAKE_ARGS+=	-DUSE_LIBVLC=OFF
CMAKE_ARGS+=	-DMAN_DIR="${PREFIX}/${PKGMANDIR}/man6"
CMAKE_ARGS+=	-DEXAMPLE_CONF_DIR="${PREFIX}/share/examples/gemrb"
CMAKE_ARGS+=	-DSDL_BACKEND="SDL2"

CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	build

REPLACE_PYTHON=	admin/extend2da.py

# https://github.com/gemrb/gemrb/issues/101 (closed)
# https://github.com/gemrb/gemrb/issues/1289
PYTHON_VERSIONS_ACCEPTED=	27

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
