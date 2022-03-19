# $NetBSD: Makefile,v 1.139 2022/03/19 00:37:44 gutteridge Exp $

DISTNAME=	librsvg-2.52.8
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/LibRsvg
COMMENT=	SVG library for GNOME
LICENSE=	gnu-lgpl-v2.1

MAKE_FLAGS+=	CARGO_MAKE_JOBS=-j${_MAKE_JOBS_N}

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake aclocal autoconf automake
USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tools
#CONFIGURE_ARGS+=	--enable-Bsymbolic=auto
CONFIGURE_ARGS+=	--disable-Bsymbolic

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cairo-gobject}/lib

PKGCONFIG_OVERRIDE=	librsvg.pc.in

TEST_TARGET=		check

.include "cargo-depends.mk"

.include "../../mk/bsd.prefs.mk"

# librsvg broken on aarch64 by rustc>=1.54.0 including 1.57.0 due to:
# libtool: error: object name conflicts in archive
.if \
  !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64)	|| \
  !empty(MACHINE_PLATFORM:MDarwin-*-aarch64)
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
BUILDLINK_API_DEPENDS.pango+=	pango>=1.44
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
RUST_REQ=	1.52.0
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
