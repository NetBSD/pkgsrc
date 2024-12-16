# $NetBSD: Makefile,v 1.40 2024/12/16 08:25:29 wiz Exp $

DISTNAME=	taisei-1.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=taisei-project/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://taisei-project.org/
COMMENT=	Open source Touhou Project fan game
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-zstandard-[0-9]*:../../archivers/py-zstandard

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

MESON_ARGS+=	-Db_pch=false
MESON_ARGS+=	-Db_lto=false
MESON_ARGS+=	-Dstrip=false
MESON_ARGS+=	-Ddefault_library=shared
MESON_ARGS+=	-Ddocs=disabled
MESON_ARGS+=	-Ddeveloper=false
MESON_ARGS+=	-Dinstall_macos_bundle=disabled
MESON_ARGS+=	-Dvalidate_glsl=disabled
MESON_ARGS+=	-Dinstall_freedesktop=enabled
MESON_ARGS+=	-Duse_libcrypto=enabled

REPLACE_PYTHON+=	scripts/thunk.py
REPLACE_PYTHON+=	scripts/configure-file.py

BUILDLINK_TRANSFORM+=	rm:-Werror=implicit-function-declaration

PYTHON_FOR_BUILD_ONLY=		tool

.include "../../devel/meson/build.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
