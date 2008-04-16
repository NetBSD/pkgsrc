# $NetBSD: Makefile,v 1.30 2008/04/16 12:36:59 abs Exp $
#

DISTNAME=	pyorbit-2.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyorbit/ORBit/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyorbit/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for ORBit2

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	YES
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pyorbit-2.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	25 24

do-test:
	(cd ${WRKSRC}/tests/c-inproc && ${PYTHONBIN} test-c-inproc.py)

.include "../../net/ORBit2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
