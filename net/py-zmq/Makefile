# $NetBSD: Makefile,v 1.54 2025/09/11 06:29:58 adam Exp $

DISTNAME=	pyzmq-27.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyzmq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3 AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.10:../../devel/py-scikit-build-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.17:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config

PYSETUPBUILDARGS+=	--zmq=${BUILDLINK_PREFIX.zeromq:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
