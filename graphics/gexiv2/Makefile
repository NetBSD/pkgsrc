# $NetBSD: Makefile,v 1.22 2022/07/22 17:07:13 micha Exp $

DISTNAME=	gexiv2-0.12.2
PKGREVISION=	7
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gexiv2/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

# uses std::auto_ptr, deprecated in c++11
# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=	c99 c++03
USE_TOOLS+=	pkg-config

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gexiv2

PYTHON_FOR_BUILD_ONLY=	tool

MESON_ARGS+=	-Dpython2_girdir=no
MESON_ARGS+=	-Dpython3_girdir=no

PKGCONFIG_OVERRIDE=	gexiv2.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./gexiv2/gexiv2.map

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
