# $NetBSD: Makefile,v 1.1 2020/03/16 14:27:25 wiz Exp $

DISTNAME=	google-api-core-1.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/google-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.6.0:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.4.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-google-auth>=0.4.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-grpcio-[0-9]*:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# These are not sufficient, package needs to be installed to be able to be tested
#TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
