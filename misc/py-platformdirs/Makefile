# $NetBSD: Makefile,v 1.62 2026/11/22 19:48:06 wiz Exp $

DISTNAME=	platformdirs-4.14.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/platformdirs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/platformdirs
COMMENT=	Python module for determining appropriate platform-specific dirs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-sbom>=0:../../devel/py-sbom
TEST_DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.15.1:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
