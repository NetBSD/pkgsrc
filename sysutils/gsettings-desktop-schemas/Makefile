# $NetBSD: Makefile,v 1.14 2020/11/06 17:48:05 nia Exp $

DISTNAME=	gsettings-desktop-schemas-3.38.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gsettings-desktop-schemas/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Collection of GSettings schemas for the GNOME desktop
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	gsettings-desktop-schemas.pc.in

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/schemas.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.31
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
