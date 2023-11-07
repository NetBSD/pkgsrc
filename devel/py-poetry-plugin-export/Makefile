# $NetBSD: Makefile,v 1.8 2023/11/07 09:27:36 wiz Exp $

DISTNAME=	poetry_plugin_export-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry-plugin-export/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Poetry plugin to export the dependencies to various formats
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.6.0:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-poetry>=1.5.0:../../devel/py-poetry
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.9:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
