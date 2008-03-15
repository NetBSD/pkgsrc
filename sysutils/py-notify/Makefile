# $NetBSD: Makefile,v 1.4 2008/03/15 16:53:02 joerg Exp $
#

DISTNAME=	notify-python-0.1.1
PKGNAME=	${PYPKGPREFIX}-notify-0.1.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES= \
 http://www.galago-project.org/files/releases/source/notify-python/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Python bindings for libnotify

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	notify-python-0.1.1/notify-python.pc.in
PYTHON_VERSIONS_ACCEPTED=	24
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
