# $NetBSD: Makefile,v 1.39 2023/10/11 08:32:21 adam Exp $

DISTNAME=	pyzmq-25.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyzmq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3 AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPBUILDARGS+=	--zmq=${BUILDLINK_PREFIX.zeromq:Q}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
