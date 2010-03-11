# $NetBSD: Makefile,v 1.12 2010/03/11 05:41:24 obache Exp $
#

DISTNAME=	pyclutter-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter/1.0/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Python modules for Clutter toolkit
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED=	26 25

PREV_PKGPATH=	graphics/py-pyclutter
SUPERSEDES=	${PYPKGPREFIX}-pyclutter-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	pyclutter.pc.in

PY_PATCHPLIST=	yes

.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
