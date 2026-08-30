# $NetBSD: Makefile,v 1.122 2026/08/30 15:37:15 wiz Exp $
#
# Changes: https://github.com/pylint-dev/pylint/releases

DISTNAME=	pylint-4.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-astroid>=4.0.2:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.7:../../textproc/py-dill
DEPENDS+=	${PYPKGPREFIX}-isort>=5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.1:../../textproc/py-tomlkit
TEST_DEPENDS+=	${PYPKGPREFIX}-gitpython>=3:../../devel/py-gitpython
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pylint pylint-config pyreverse symilar

# as of 4.0.6
# 25 failed, 1998 passed, 261 skipped, 5 xfailed

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
