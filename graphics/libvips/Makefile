# $NetBSD: Makefile,v 1.4 2025/10/05 19:26:03 js Exp $

DISTNAME=		vips-8.17.1
PKGNAME=		lib${DISTNAME}
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=libvips/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		base@atomicules.co.uk
HOMEPAGE=		https://libvips.github.io/libvips/
COMMENT=		Demand-driven, horizontally threaded image processing lib
LICENSE=		gnu-lgpl-v2.1

# disable examples and deprecated interfaces
MESON_ARGS+=		-Ddeprecated=false -Dexamples=false

USE_TOOLS+=		pkg-config msgfmt xgettext
USE_LANGUAGES=		c c++
PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON+=	cplusplus/gen-operators.py
REPLACE_PYTHON+=	doc/gen-function-list.py

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/vips-cpp.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/vips.pc

# disable relro otherwise it'll crash on NetBSD:
# https://github.com/libvips/libvips/issues/3977 and
# https://mail-index.netbsd.org/netbsd-bugs/2023/12/26/msg080904.html
RELRO_SUPPORTED=	no

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lerc/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
