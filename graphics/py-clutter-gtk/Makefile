# $NetBSD: Makefile,v 1.11 2011/11/01 06:01:43 sbd Exp $
#

DISTNAME=	pyclutter-gtk-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/pyclutter-gtk/0.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Python modules for Clutter-Gtk
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED=	27 26 25

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
