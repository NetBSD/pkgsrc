# $NetBSD: Makefile,v 1.40 2026/03/06 06:08:02 adam Exp $

DISTNAME=	platformdirs-4.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/platformdirs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/platformdirs
COMMENT=	Python module for determining appropriate platform-specific dirs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.15.1:../../devel/py-test-mock

USE_LANGUAGES=	# none

# as of 4.9.2
# 1 failed, 752 passed, 71 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
