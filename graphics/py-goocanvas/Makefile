# $NetBSD: Makefile,v 1.56 2020/03/08 16:50:06 wiz Exp $

DISTNAME=	pygoocanvas-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	33
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygoocanvas/0.14/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://live.gnome.org/PyGoocanvas
COMMENT=	Python bindings for GooCanvas
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pygoocanvas.pc.in

CONFIGURE_ARGS+=	--disable-docs

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 27 # py-gtk2

.include "../../lang/python/pyversion.mk"

.include "../../graphics/py-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10.0
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.goocanvas+=	goocanvas>=0.14.0
.include "../../graphics/goocanvas/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
