# $NetBSD: Makefile,v 1.38 2024/06/07 05:29:12 adam Exp $

DISTNAME=	responses-0.25.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/responses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getsentry/responses
COMMENT=	Utility library for mocking out the requests Python library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.30.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.0.0:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.0.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver-[0-9]*:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w-[0-9]*:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-types-yaml-[0-9]*:../../textproc/py-types-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
