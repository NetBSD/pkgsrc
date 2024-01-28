# $NetBSD: Makefile,v 1.40 2024/01/28 20:44:28 adam Exp $

DISTNAME=	zeroconf-0.131.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeroconf/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jstasiak/python-zeroconf
COMMENT=	Pure Python Multicast DNS Service Discovery Library
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.5:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.5.2:../../devel/py-poetry-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65.4.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ifaddr>=0.1.7:../../net/py-ifaddr
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.20.3:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=3.0.0:../../devel/py-async-timeout
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
