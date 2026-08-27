# $NetBSD: Makefile,v 1.65 2026/08/27 09:33:35 wiz Exp $

DISTNAME=	zeroconf-0.150.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeroconf/}

# .so files are missing from PLIST with Cython 3.3.0
# https://github.com/python-zeroconf/python-zeroconf/issues/1818
PATCHFILES+=	1820.diff
PATCH_SITES=	https://patch-diff.githubusercontent.com/raw/python-zeroconf/python-zeroconf/pull/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jstasiak/python-zeroconf
COMMENT=	Pure Python Multicast DNS Service Discovery Library
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.3.0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ifaddr>=0.1.7:../../net/py-ifaddr
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.20.3:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-codspeed>=3.1.0:../../devel/py-test-codspeed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

post-install:
	find ${DESTDIR}${PREFIX} -name *.orig_dist -delete

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
