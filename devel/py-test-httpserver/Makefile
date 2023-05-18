# $NetBSD: Makefile,v 1.2 2023/05/18 08:46:37 adam Exp $

DISTNAME=	pytest_httpserver-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_httpserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/csernazs/pytest-httpserver
COMMENT=	HTTP server for pytest
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.0.0:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=2.28.1:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-types-toml-[0-9]*:../../devel/py-types-toml

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# needs to be installed for testing
#TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
