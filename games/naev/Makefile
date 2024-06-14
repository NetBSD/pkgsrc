# $NetBSD: Makefile,v 1.29 2024/06/14 13:26:23 ktnb Exp $

DISTNAME=		naev-0.11.5
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=naev/}
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_SUBMODULES=	naev naev-artwork-production e2d2edab2317d296eb14a830505b1dc41d02dec1 artwork

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/naev/naev
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_TOOLS+=	bash:run pkg-config

REPLACE_BASH+=	artwork/gfx/outfit/check.sh
REPLACE_BASH+=	artwork/gfx/spob/check.sh
REPLACE_BASH+=	artwork/gfx/ship/update.sh
REPLACE_BASH+=	artwork/snd/music/checkgain.sh

GAME_DIR=	${PREFIX}/share/naev/

INSTALL_TARGET=	install install-data-local ${GAME_DIR}

MESON_ARGS+=		-Dndata_path="${GAME_DIR}"

SUBST_CLASSES+=		alloca
SUBST_FILES.alloca+=	meson.build
SUBST_FILES.alloca+=	src/utf8.c
SUBST_SED.alloca+=	-e "s,HAVE_ALLOCA_H,NAEV_HAVE_ALLOCA_H,"
SUBST_STAGE.alloca=	post-extract
SUBST_MESSAGE.alloca=	Avoid symbol conflict with SDL2.

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libunibreak/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/suitesparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
