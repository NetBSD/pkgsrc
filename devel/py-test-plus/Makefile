# $NetBSD: Makefile,v 1.3 2025/02/03 08:31:04 adam Exp $

DISTNAME=	pytest_plus-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-plus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-plus
COMMENT=	Extends pytest functionality
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=63.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.5:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=7.4.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.0.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-html>0:../../devel/py-test-html

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
