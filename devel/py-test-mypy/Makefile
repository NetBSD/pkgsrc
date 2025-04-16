# $NetBSD: Makefile,v 1.8 2025/04/16 21:08:28 adam Exp $

DISTNAME=	pytest_mypy-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dbader/pytest-mypy
COMMENT=	Mypy static type checker plugin for Pytest
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-mypy>=1.0:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.4:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
