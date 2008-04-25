# $NetBSD: Makefile,v 1.5 2008/04/25 20:39:09 joerg Exp $
#

DISTNAME=	pygtkglext-1.1.0
PKGNAME=	${PYPKGPREFIX}-pygtkglext-1.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkglext/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkglext.sourceforge.net/
COMMENT=	Python bindings for gtkglext

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_ACCEPTED= 25 24

PKGCONFIG_OVERRIDE+=	pygtkglext.pc.in

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
