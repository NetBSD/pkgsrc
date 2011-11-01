# $NetBSD: Makefile,v 1.23 2011/11/01 06:01:43 sbd Exp $
#

DISTNAME=	pyclutter-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/pyclutter/1.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Python modules for Clutter toolkit
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED=	27 26 25

PREV_PKGPATH=	graphics/py-pyclutter
SUPERSEDES=	${PYPKGPREFIX}-pyclutter-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	pyclutter.pc.in

PY_PATCHPLIST=	yes

PLIST_VARS+=	x11

.include "../../graphics/clutter/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
PLIST.x11=	yes
.endif
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
