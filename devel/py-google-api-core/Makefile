# $NetBSD: Makefile,v 1.30 2024/02/20 20:43:06 wiz Exp $

DISTNAME=	google-api-core-2.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.14.1:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.56.2:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.12.6:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
# extras
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.33.2:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-proto-plus-[0-9]*:../../devel/py-proto-plus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# test status as of 2.15.0:
# 15 failed, 400 passed, 23 skipped, 7 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
