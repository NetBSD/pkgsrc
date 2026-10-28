# $NetBSD: Makefile,v 1.147 2026/10/28 05:36:48 adam Exp $

DISTNAME=	pytest-9.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pytest.org/
COMMENT=	Python testing tool
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=10.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-iniconfig>=2:../../devel/py-iniconfig
DEPENDS+=	${PYPKGPREFIX}-packaging>=24:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.6:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.15:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-argcomplete>=0:../../devel/py-argcomplete
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=23.1:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.75:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-xmlschema>=0:../../textproc/py-xmlschema

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:build

PY_RENAME_BINARIES=	py.test pytest

# as of 8.3.3
# 3621 passed, 112 skipped, 11 xfailed, 1 xpassed

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
