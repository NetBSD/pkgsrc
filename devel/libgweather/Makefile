# $NetBSD: Makefile,v 1.83 2020/11/05 09:06:51 ryoon Exp $

DISTNAME=	libgweather-3.36.1
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=/sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/LibGWeather
COMMENT=	Weather information access library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config xgettext

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/gweather-3.0.pc

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../geography/geocode-glib/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
