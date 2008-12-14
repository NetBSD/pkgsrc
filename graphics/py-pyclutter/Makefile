# $NetBSD: Makefile,v 1.1.1.1 2008/12/14 11:19:24 obache Exp $
#

DISTNAME=	pyclutter-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Python modules for Clutter toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	pyclutter.pc.in

PY_PATCHPLIST=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=0.8.4
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
