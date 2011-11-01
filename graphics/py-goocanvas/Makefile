# $NetBSD: Makefile,v 1.18 2011/11/01 06:01:43 sbd Exp $
#

DISTNAME=	pygoocanvas-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	9
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygoocanvas/0.14/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/PyGoocanvas
COMMENT=	Python bindings for GooCanvas
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pygoocanvas.pc.in

CONFIGURE_ARGS+=	--disable-docs

PY_PATCHPLIST=	yes

# This restriction came from py-gtk2 and py-cairo,
# pygoocanvas itself just require >=22.
PYTHON_VERSIONS_ACCEPTED= 27 26 25

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10.0
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.goocanvas+=	goocanvas>=0.14.0
.include "../../graphics/goocanvas/buildlink3.mk"
BUILDLINK_API_DEPENDS.pycairo+=	${PYPKGPREFIX}-cairo>=1.8.4
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
