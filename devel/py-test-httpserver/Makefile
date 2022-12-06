# $NetBSD: Makefile,v 1.1 2022/12/06 20:34:05 wiz Exp $

DISTNAME=	pytest_httpserver-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_httpserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/csernazs/pytest-httpserver
COMMENT=	HTTP server for pytest
LICENSE=	mit

DEPENDS+=		${PYPKGPREFIX}-werkzeug>=2:../../www/py-werkzeug
TEST_DEPENDS+=		${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=		${PYPKGPREFIX}-types-toml-[0-9]*:../../devel/py-types-toml
TEST_DEPENDS+=		${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# needs to be installed for testing
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
