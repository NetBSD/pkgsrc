# $NetBSD: Makefile,v 1.33 2009/09/08 16:37:34 drochner Exp $
#

DISTNAME=	pyorbit-2.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyorbit/ORBit/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyorbit/2.24/}
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

PYTHON_VERSIONS_ACCEPTED=	26 25 24
BUILDLINK_API_DEPENDS.python26+= python26>=2.6.2nb4
BUILDLINK_API_DEPENDS.python25+= python25>=2.5.4nb2
BUILDLINK_API_DEPENDS.python24+= python24>=2.4.5nb4

do-test:
	(cd ${WRKSRC}/tests/c-inproc && ${PYTHONBIN} test-c-inproc.py)

.include "../../net/ORBit2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
