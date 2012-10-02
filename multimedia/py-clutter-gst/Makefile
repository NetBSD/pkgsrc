# $NetBSD: Makefile,v 1.18 2012/10/02 17:11:42 tron Exp $
#

DISTNAME=	pyclutter-gst-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/pyclutter-gst/1.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Python modules for Clutter-Gstreamer
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	pyclutter-gst.pc.in

PY_PATCHPLIST=	yes

.include "../../graphics/py-clutter/buildlink3.mk"
.include "../../multimedia/clutter-gst/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
