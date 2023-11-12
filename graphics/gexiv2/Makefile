# $NetBSD: Makefile,v 1.34 2023/11/12 13:21:57 wiz Exp $

DISTNAME=	gexiv2-0.14.1
PKGREVISION=	4
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gexiv2/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=	c99 c++11
USE_CXX_FEATURES+=	filesystem
USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dcpp_std=c++11

PKGCONFIG_OVERRIDE=	gexiv2.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./gexiv2/gexiv2.map

PYTHON_VERSIONS_INCOMPATIBLE=	27
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

MESON_REQD=	1.2.0
.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
# for BMFF support
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.27.5nb1
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
