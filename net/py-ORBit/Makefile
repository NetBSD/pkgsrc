# $NetBSD: Makefile,v 1.2 2003/07/13 13:52:59 wiz Exp $
#

DISTNAME=	pyorbit-1.99.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyorbit/ORBit/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyorbit/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for ORBit2

PY_PATCHPLIST=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pyorbit-2.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSION_REQD=	22pth
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2

.include "../../net/ORBit2/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
