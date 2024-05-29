# $NetBSD: Makefile,v 1.110 2024/05/29 16:32:14 adam Exp $

DISTNAME=	libgweather-40.0
PKGREVISION=	22
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/LibGWeather
COMMENT=	Weather information access library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config xgettext

PYTHON_FOR_BUILD_ONLY=	tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/gweather-3.0.pc

TOOL_DEPENDS+=		py${PYTHON_VERSION_DEFAULT}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../geography/geocode-glib/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
