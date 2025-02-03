# $NetBSD: Makefile,v 1.35 2025/02/03 18:30:52 ktnb Exp $

DISTNAME=		naev-0.12.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=naev/}
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_SUBMODULES=	naev naev-artwork-production a685780631a345b2e3e635606961574c1ad2a0c3 artwork
DIST_SUBDIR=		naev

LYAML_VERSION=	6.2.8

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	lyaml-${LYAML_VERSION}.tar.gz

SITES.lyaml-${LYAML_VERSION}.tar.gz= \
	-https://github.com/gvvaughan/lyaml/archive/refs/tags/v${LYAML_VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/naev/naev
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_TOOLS+=	bash:run pkg-config cmake

REPLACE_BASH+=	artwork/gfx/outfit/check.sh
REPLACE_BASH+=	artwork/gfx/spob/check.sh
REPLACE_BASH+=	artwork/gfx/ship/update.sh
REPLACE_BASH+=	artwork/snd/music/checkgain.sh

REPLACE_PYTHON+=	dat/naevpedia/ships/ships.py
REPLACE_PYTHON+=	dat/naevpedia/outfits/outfits.py

GAME_DIR=	${PREFIX}/share/naev/

INSTALL_TARGET=	install install-data-local ${GAME_DIR}

MESON_ARGS+=		-Dndata_path="${GAME_DIR}"

SUBST_CLASSES+=		alloca
SUBST_FILES.alloca+=	meson.build
SUBST_FILES.alloca+=	src/utf8.c
SUBST_SED.alloca+=	-e "s,HAVE_ALLOCA_H,NAEV_HAVE_ALLOCA_H,"
SUBST_STAGE.alloca=	post-extract
SUBST_MESSAGE.alloca=	Avoid symbol conflict with SDL2.

# naev doesn't check that lyaml installed on the system but rather the
# source is found in the subprojects.
post-extract:
	mkdir ${WRKSRC}/subprojects/packagecache/
	${CP} ${DISTDIR}/lyaml-${LYAML_VERSION}.tar.gz ${WRKSRC}/subprojects/packagecache/

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/application.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libunibreak/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../math/suitesparse/buildlink3.mk"
.include "../../x11/nativefiledialog-extended/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
