# $NetBSD: Makefile,v 1.41 2025/02/02 15:58:10 wiz Exp $

DISTNAME=	google_api_core-2.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/python-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.14.1:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.56.2:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-proto-plus>=1.22.3:../../devel/py-proto-plus
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.12.6:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
# grpc
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.49.1:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

# test status as of 2.20.0
# 24 failed, 912 passed, 42 skipped, 90 warnings
# as of 2.24.0, python3.13 dumps core with grpc in the backtrace

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
