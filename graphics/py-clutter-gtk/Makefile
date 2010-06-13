# $NetBSD: Makefile,v 1.2 2010/06/13 22:44:42 wiz Exp $
#

DISTNAME=	pyclutter-gtk-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter-gtk/0.10/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Python modules for Clutter-Gtk
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED=	26 25

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	pyclutter-gtk.pc.in

PY_PATCHPLIST=	yes

BUILDLINK_API_DEPENDS.clutter-gtk+=	clutter-gtk>=0.10.2
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/py-clutter/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
