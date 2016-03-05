# $NetBSD: Makefile,v 1.4 2016/03/05 11:27:53 jperkin Exp $

DISTNAME=	gevent-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.1:../../devel/py-greenlet

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

do-test:
	${RUN} cd ${WRKSRC}/greentest; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py

.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.6
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
