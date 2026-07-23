# $NetBSD: Makefile,v 1.11 2026/07/23 12:50:46 adam Exp $

DISTNAME=	dictdiffer-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dictdiffer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inveniosoftware/dictdiffer
COMMENT=	Library that helps you to diff and patch dictionaries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort>=1.2.0:../../devel/py-test-isort
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-pydocstyle>=2.2.0:../../devel/py-test-pydocstyle
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=3:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=3.7.0:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
