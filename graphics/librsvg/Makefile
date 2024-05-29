# $NetBSD: Makefile,v 1.162 2024/05/29 16:32:59 adam Exp $

DISTNAME=	librsvg-2.58.0
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/LibRsvg
COMMENT=	SVG library for GNOME
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake aclocal autoconf automake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-Bsymbolic
TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

# Requires rst2man to generate rsvg-convert.1
TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
# Requires gi-docgen to generate HTML format API documentation
TOOL_DEPENDS+=		${PYPKGPREFIX}-gi-docgen>=2022.1nb1:../../devel/py-gi-docgen

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cairo}/lib

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--gc-sections

PKGCONFIG_OVERRIDE=	librsvg.pc.in

SUBST_CLASSES+=		rst2man
SUBST_MESSAGE.rst2man=	Fixing rst2man name used by pkgsrc due to versioning.
SUBST_STAGE.rst2man=	pre-configure
SUBST_FILES.rst2man=	configure
SUBST_SED.rst2man=	-e 's,rst2man.py,rst2man-${PYVERSSUFFIX},g'

.include "cargo-depends.mk"

.include "../../mk/bsd.prefs.mk"

# librsvg broken on aarch64 by rustc>=1.54.0 including 1.57.0 due to:
# libtool: error: object name conflicts in archive
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || ${MACHINE_PLATFORM:MDarwin-*-aarch64}
RUSTFLAGS+=	-C target-feature=-lse
PKG_LIBTOOL=	${WRKDIR}/libtool
pre-configure:
	sed 's,$$AR t "$$f_ex_an_ar_oldlib",& | grep -v lse.o,'	\
	  < ${PREFIX}/bin/libtool > ${WRKDIR}/libtool
	chmod +x ${WRKDIR}/libtool
.endif

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
RUST_REQ=	1.65.0
.include "../../lang/rust/cargo.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
