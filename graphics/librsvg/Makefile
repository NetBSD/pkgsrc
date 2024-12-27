# $NetBSD: Makefile,v 1.168 2024/12/27 08:47:57 wiz Exp $

DISTNAME=	librsvg-2.59.2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/LibRsvg
COMMENT=	SVG library for GNOME
LICENSE=	gnu-lgpl-v2.1

# Requires rst2man to generate rsvg-convert.1
TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
# Requires gi-docgen to generate HTML format API documentation
TOOL_DEPENDS+=		${PYPKGPREFIX}-gi-docgen>=2022.1nb1:../../devel/py-gi-docgen
TOOL_DEPENDS+=		cargo-c>=0.9.19:../../devel/cargo-c

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=		tool

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cairo}/lib

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--gc-sections

PKGCONFIG_OVERRIDE=		output/meson-private/librsvg-2.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

SUBST_CLASSES+=		rst2man
SUBST_MESSAGE.rst2man=	Fixing rst2man name used by pkgsrc due to versioning.
SUBST_STAGE.rst2man=	pre-configure
SUBST_FILES.rst2man=	meson.build
SUBST_SED.rst2man=	-e 's,rst2man.py,rst2man-${PYVERSSUFFIX},g'

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.50.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.48.11
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
RUST_REQ=	1.77.2
.include "../../lang/rust/cargo.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
