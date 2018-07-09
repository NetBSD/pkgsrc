# $NetBSD: Makefile,v 1.10 2018/07/09 07:51:16 adam Exp $

DISTNAME=	gevent-1.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11.5:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.13:../../devel/py-greenlet
MAKE_ENV+=	CARES_EMBED=0 LIBEV_EMBED=0

USE_LANGUAGES=	c c++

# Explicitly disable inotify on SunOS, assumes Linux statfs.
MAKE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no

do-test:
	cd ${WRKSRC}/src/greentest && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py --config known_failures.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
