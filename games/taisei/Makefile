# $NetBSD: Makefile,v 1.35 2024/05/29 16:32:44 adam Exp $

DISTNAME=	taisei-v1.3.2
PKGNAME=	${DISTNAME:S/-v/-/}
PKGREVISION=	18
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=taisei-project/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://taisei-project.org/
COMMENT=	Open source Touhou Project fan game
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++14

MESON_ARGS+=	-Db_pch=false
MESON_ARGS+=	-Db_lto=false
MESON_ARGS+=	-Dstrip=false
MESON_ARGS+=	-Ddefault_library=shared
MESON_ARGS+=	-Dversion_fallback=${PKGVERSION_NOREV}
MESON_ARGS+=	-Ddocs=false
MESON_ARGS+=	-Ddeveloper=false
MESON_ARGS+=	-Ddebug_opengl=false
MESON_ARGS+=	-Dmacos_bundle=false
MESON_ARGS+=	-Dvalidate_glsl=false
MESON_ARGS+=	-Dinstall_freedesktop=true
MESON_ARGS+=	-Duse_libcrypto=true

SUBST_CLASSES+=		ver
SUBST_STAGE.ver=	pre-configure
SUBST_MESSAGE.ver=	Setting the package verison.
SUBST_FILES.ver+=	scripts/meson.build
SUBST_VARS.ver=		PKGVERSION

REPLACE_PYTHON+=	scripts/thunk.py
REPLACE_PYTHON+=	scripts/configure-file.py

BUILDLINK_TRANSFORM+=	rm:-Werror=implicit-function-declaration

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/meson/build.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/cglm/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
