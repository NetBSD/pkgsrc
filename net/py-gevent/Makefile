# $NetBSD: Makefile,v 1.22 2023/06/18 05:26:01 adam Exp $

DISTNAME=	gevent-22.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.12.2:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-greenlet>=1.1.3:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.event-[0-9]*:../../devel/py-zope.event
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface

MAKE_ENV+=	GEVENTSETUP_EMBED_CARES=0
MAKE_ENV+=	GEVENTSETUP_EMBED_LIBEV=0
MAKE_ENV+=	GEVENTSETUP_EMBED_LIBUV=0

CHECK_PORTABILITY_SKIP=	deps/libuv/autogen.sh

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Explicitly disable inotify on SunOS, assumes Linux statfs.
MAKE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*) || !empty(CC_VERSION:Mgcc-1[0-9].*)
BUILDLINK_TRANSFORM.SunOS+=	opt:-D_XOPEN_SOURCE=500:-D_XOPEN_SOURCE=600
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
