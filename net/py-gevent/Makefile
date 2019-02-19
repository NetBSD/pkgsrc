# $NetBSD: Makefile,v 1.14 2019/02/19 12:26:13 adam Exp $

DISTNAME=	gevent-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11.5:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.14:../../devel/py-greenlet
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
TEST_DEPENDS+=	${PYPKGPREFIX}-objgraph-[0-9]*:../../graphics/py-objgraph
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
TEST_DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

MAKE_ENV+=	CARES_EMBED=0 LIBEV_EMBED=0

USE_LANGUAGES=	c c++

# Explicitly disable inotify on SunOS, assumes Linux statfs.
MAKE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
BUILDLINK_TRANSFORM.SunOS+=	opt:-D_XOPEN_SOURCE=500:-D_XOPEN_SOURCE=600
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
