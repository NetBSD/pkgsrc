# $NetBSD: Makefile,v 1.20 2022/01/27 11:48:22 wiz Exp $

DISTNAME=	google-api-core-1.31.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.25.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.6.0:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.29.0:../../net/py-grpcio
DEPENDS+=	${PYPKGPREFIX}-packaging>=14.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.12.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.3.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.13.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# all fail, even after 'make install', with:
# ModuleNotFoundError: No module named 'google.api_core'
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
