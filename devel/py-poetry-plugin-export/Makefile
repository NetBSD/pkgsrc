# $NetBSD: Makefile,v 1.15 2026/11/25 08:51:21 adam Exp $

DISTNAME=	poetry_plugin_export-1.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry-plugin-export/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Poetry plugin to export the dependencies to various formats
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-poetry>=2.1.0:../../devel/py-poetry
DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.1.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.4:../../textproc/py-tomlkit
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.9:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
