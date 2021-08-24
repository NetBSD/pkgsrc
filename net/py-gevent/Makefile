# $NetBSD: Makefile,v 1.15 2021/08/24 10:42:50 nia Exp $

DISTNAME=	gevent-21.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11.5:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.14:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

MAKE_ENV+=	CARES_EMBED=0
MAKE_ENV+=	LIBEV_EMBED=0
MAKE_ENV+=	LIBUV_EMBED=0

USE_LANGUAGES=	c c++

# Explicitly disable inotify on SunOS, assumes Linux statfs.
MAKE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
BUILDLINK_TRANSFORM.SunOS+=	opt:-D_XOPEN_SOURCE=500:-D_XOPEN_SOURCE=600
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
