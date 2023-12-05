# $NetBSD: Makefile,v 1.25 2023/12/05 18:21:59 adam Exp $

DISTNAME=	pytest-runner-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-runner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-runner
COMMENT=	Invoke py.test as distutils command with dependency resolution
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-black>=0.3.7:../../devel/py-test-black
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy>=0.9.1:../../devel/py-test-mypy
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-enabler>=1.0.1:../../devel/py-test-enabler
# introduces dependency cycle
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=0:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=2.4:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-types-setuptools-[0-9]*:../../devel/py-types-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
