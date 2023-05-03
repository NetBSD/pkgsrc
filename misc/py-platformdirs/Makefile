# $NetBSD: Makefile,v 1.15 2023/05/03 18:52:46 wiz Exp $

DISTNAME=	platformdirs-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/platformdirs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/platformdirs/platformdirs
COMMENT=	Python module for determining appropriate platform-specific dirs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.14:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
TEST_DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.10:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
