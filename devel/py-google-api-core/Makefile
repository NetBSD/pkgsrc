# $NetBSD: Makefile,v 1.36 2024/10/19 10:54:46 wiz Exp $

DISTNAME=	google_api_core-2.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
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
DEPENDS+=	${PYPKGPREFIX}-proto-plus>=1.22.3:../../devel/py-proto-plus
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.12.6:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
# grpc
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.49.1:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

# test status as of 2.20.0
# 24 failed, 912 passed, 42 skipped, 90 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
