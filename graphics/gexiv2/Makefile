# $NetBSD: Makefile,v 1.6 2019/08/02 08:21:05 nia Exp $

DISTNAME=	gexiv2-0.12.0
CATEGORIES=	graphics devel
MASTER_SITES=	https://ftp.acc.umu.se/pub/gnome/sources/gexiv2/0.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

# uses std::auto_ptr, deprecated in c++11
USE_LANGUAGES=	c c++03
USE_TOOLS+=	pkg-config

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gexiv2

MESON_ARGS+=	-Dpython2_girdir=no
MESON_ARGS+=	-Dpython3_girdir=no

PKGCONFIG_OVERRIDE=	gexiv2.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./gexiv2/gexiv2.map

.include "../../devel/py-meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
