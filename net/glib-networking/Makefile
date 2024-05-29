# $NetBSD: Makefile,v 1.74 2024/05/29 16:33:52 adam Exp $

DISTNAME=	glib-networking-2.80.0
PKGREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-networking/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Network-related giomodules for glib
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config gettext

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON+=	meson_post_install.py

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.60.0
.include "../../devel/glib2/modules.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.4.6
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
