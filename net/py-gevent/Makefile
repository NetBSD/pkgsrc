# $NetBSD: Makefile,v 1.38 2026/10/26 06:15:30 wiz Exp $

DISTNAME=	gevent-26.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gevent/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cffi>=2.1.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-greenlet>=3.2.2:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-zope.event>=0:../../devel/py-zope.event
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=0:../../devel/py-zope.interface

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	311

# See docs/development/installing_from_source.rst
MAKE_ENV+=		GEVENTSETUP_EMBED=0
# Explicitly disable inotify on SunOS, assumes Linux statfs.
MAKE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no

CHECK_PORTABILITY_SKIP=	deps/libuv/autogen.sh

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || ${CC_VERSION:Mgcc-[6-9]*} || ${CC_VERSION:Mgcc-1[0-9].*}
BUILDLINK_TRANSFORM.SunOS+=	opt:-D_XOPEN_SOURCE=500:-D_XOPEN_SOURCE=600
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
