# $NetBSD: Makefile,v 1.5 2024/02/28 10:31:01 adam Exp $

DISTNAME=	pytest_httpserver-1.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_httpserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/csernazs/pytest-httpserver
COMMENT=	HTTP server for pytest
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.0.0:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.971:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=2.28.1:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-types-toml-[0-9]*:../../devel/py-types-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
