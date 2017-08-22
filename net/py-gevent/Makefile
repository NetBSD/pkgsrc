# $NetBSD: Makefile,v 1.8 2017/08/22 07:57:51 adam Exp $

DISTNAME=	gevent-1.2.2
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.3.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.10:../../devel/py-greenlet
MAKE_ENV+=	CARES_EMBED=0 LIBEV_EMBED=0

USE_LANGUAGES=	c c++

do-test:
	cd ${WRKSRC}/src/greentest && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py --config known_failures.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
