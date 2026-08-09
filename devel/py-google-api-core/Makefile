# $NetBSD: Makefile,v 1.57 2026/08/09 21:24:48 wiz Exp $

DISTNAME=	google_api_core-2.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python/tree/main/packages/google-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.69.2:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-protobuf>=6.33.5:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-proto-plus>=1.26.1:../../devel/py-proto-plus
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.14.1:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests>=2.33.0:../../devel/py-requests
# undocumented but used
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
# grpc
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.75.1:../../net/py-grpcio
# undocumented but used
DEPENDS+=	${PYPKGPREFIX}-grpcio-status>=1.75.1:../../net/py-grpcio-status
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

# as of 2.34.0
# 1165 passed, 10 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
