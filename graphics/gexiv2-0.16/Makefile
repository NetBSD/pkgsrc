# $NetBSD: Makefile,v 1.2 2026/09/02 19:02:36 wiz Exp $

DISTNAME=	gexiv2-0.16.0
PKGREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gexiv2/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17 filesystem
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=		output/meson-private/gexiv2-0.16.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.28
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
