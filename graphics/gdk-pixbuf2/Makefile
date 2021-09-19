# $NetBSD: Makefile,v 1.49 2021/09/19 16:05:15 adam Exp $

DISTNAME=	gdk-pixbuf-2.42.6
PKGNAME=	${DISTNAME:S/pixbuf/pixbuf2/}
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/gdk-pixbuf
COMMENT=	Library for image loading and manipulation
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

CONFLICTS+=	gtk2+<2.22

USE_TOOLS+=	pkg-config xgettext
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf

MESON_ARGS+=			-D installed_tests=false
MESON_ARGS+=			-D x11=false
PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE=		output/meson-private/gdk-pixbuf-2.0.pc

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

.include "../../lang/python/tool.mk"

_BUILDING_GTK2= yes
.include "loaders.mk"

.include "../../devel/meson/build.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.37.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
