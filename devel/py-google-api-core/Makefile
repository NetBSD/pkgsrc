# $NetBSD: Makefile,v 1.52 2026/04/15 17:29:42 wiz Exp $

DISTNAME=	google_api_core-2.30.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python/tree/main/packages/google-api-core
COMMENT=	Python support library for multiple Google libraries
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.14.1:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-googleapis-common-protos>=1.56.2:../../devel/py-googleapis-common-protos
DEPENDS+=	${PYPKGPREFIX}-proto-plus>=1.22.3:../../devel/py-proto-plus
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.25.8:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests
# grpc
DEPENDS+=	${PYPKGPREFIX}-grpcio>=1.49.1:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
