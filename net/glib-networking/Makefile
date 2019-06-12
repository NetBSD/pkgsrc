# $NetBSD: Makefile,v 1.42 2019/06/12 22:04:40 leot Exp $

DISTNAME=	glib-networking-2.60.3
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-networking/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Network-related giomodules for glib
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config gmake gettext

REPLACE_PYTHON+=	meson_post_install.py

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.56.0
.include "../../devel/glib2/modules.mk"
BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.3.1
.include "../../www/libproxy/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
