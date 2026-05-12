# $NetBSD: Makefile,v 1.72 2026/05/12 10:53:50 adam Exp $

DISTNAME=	mypy-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mypy-lang.org/
COMMENT=	Optional static typing for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ast-serialize>=0.3.0:../../lang/py-ast-serialize
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=1.0.0:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-librt>=0.11.0:../../lang/py-librt
DEPENDS+=	${PYPKGPREFIX}-pathspec>=1.0.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=18.0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock>=3.3.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=4.0:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist

USE_LANGUAGES=	c # for tests

# as of 2.0.0
# 5 failed, 13567 passed, 403 skipped, 12 xfailed
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

REPLACE_PYTHON+=	mypy/typeshed/scripts/update-stubtest-whitelist.py
REPLACE_PYTHON+=	mypy/typeshed/tests/*.py

PY_RENAME_BINARIES=	dmypy mypy mypyc stubgen stubtest

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
