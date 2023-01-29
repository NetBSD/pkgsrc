# $NetBSD: Makefile,v 1.25 2023/01/29 21:16:31 ryoon Exp $

DISTNAME=	gexiv2-0.14.0
PKGREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gexiv2/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

# uses std::auto_ptr, deprecated in c++11
# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=	c99 c++03
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	gexiv2.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./gexiv2/gexiv2.map

PYTHON_VERSIONS_INCOMPATIBLE=	27
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
# for BMFF support
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.27.5nb1
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
