# $NetBSD: Makefile,v 1.31 2026/11/02 11:21:10 adam Exp $

DISTNAME=	watchdog-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/watchdog/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gorakhargosh/watchdog
COMMENT=	Filesystem events monitoring
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# watchmedo
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0.3:../../devel/py-test-timeout

PY_RENAME_BINARIES=	watchmedo

# as of 6.0.0
# 3 failed, 146 passed, 13 skipped, 21 warnings

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
