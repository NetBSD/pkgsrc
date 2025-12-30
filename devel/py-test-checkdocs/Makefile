# $NetBSD: Makefile,v 1.16 2025/12/30 13:32:43 adam Exp $

DISTNAME=	pytest_checkdocs-2.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-checkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/pytest-checkdocs
COMMENT=	Check the README when running tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.15:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jaraco.packaging>=9.5:../../devel/py-jaraco.packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-jaraco.packaging -> py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
