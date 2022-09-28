# $NetBSD: Makefile,v 1.22 2022/09/28 11:06:45 wiz Exp $

DISTNAME=	google-api-core-2.10.1
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
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.33.2:../../net/py-grpcio
# separate packages or part of grpcio?
#DEPENDS+=	${PYPKGPREFIX}-grpcio-status>=1.33.2:../../net/py-grpcio-status
#DEPENDS+=	${PYPKGPREFIX}-grpcio-gcp>=0.2.2:../../net/py-grpcio-gcp
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-proto-plus-[0-9]*:../../devel/py-proto-plus

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# needs to be installed for testing
# as of 2.10.1:
# 5 failed, 572 passed, 71 skipped, 138 warnings
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
