# $NetBSD: Makefile,v 1.3 2023/11/07 22:37:59 wiz Exp $

DISTNAME=	dictdiffer-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dictdiffer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inveniosoftware/dictdiffer
COMMENT=	Library that helps you to diff and patch dictionaries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner>=2.7:../../devel/py-test-runner
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.1.0:../../devel/py-setuptools_scm
#TEST_DEPENDS+=	${PYPKGPREFIX}-check-manifest>=0.42:../../wip/py-check-manifest
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort>=1.2.0:../../devel/py-test-isort
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-codestyle>=2.2.0:../../devel/py-test-codestyle
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-docstyle>=2.2.0:../../devel/py-test-docstyle
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=3:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=3.7.0:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
