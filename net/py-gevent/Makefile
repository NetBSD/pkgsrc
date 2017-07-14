# $NetBSD: Makefile,v 1.7 2017/07/14 10:19:36 adam Exp $

DISTNAME=	gevent-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

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
