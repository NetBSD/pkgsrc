# $NetBSD: Makefile,v 1.23 2022/10/31 10:42:45 adam Exp $

DISTNAME=	google-api-core-2.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.56.2:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.20.1:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.25.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
# extras
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.33.2:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-proto-plus-[0-9]*:../../devel/py-proto-plus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs to be installed for testing
# as of 2.10.1:
# 5 failed, 572 passed, 71 skipped, 138 warnings
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
