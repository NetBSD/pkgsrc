# $NetBSD: Makefile,v 1.16 2005/01/23 20:41:48 recht Exp $
#

DISTNAME=	pyorbit-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyorbit/ORBit/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyorbit/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for ORBit2

PY_PATCHPLIST=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pyorbit-2.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	24 23 22
BUILDLINK_DEPENDS.python22=	python22>=2.2.2nb2

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
