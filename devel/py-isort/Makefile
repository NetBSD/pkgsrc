# $NetBSD: Makefile,v 1.37 2026/09/08 05:25:48 adam Exp $

DISTNAME=	isort-9.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/isort
COMMENT=	Python utility/library to sort imports
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-mypyc>=0:../../lang/py-hatch-mypyc
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=1.1.0:../../lang/py-mypy_extensions
TEST_DEPENDS+=	git-base>=0:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-black>=0:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.10.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith>=0.1.3:../../devel/py-hypothesmith
TEST_DEPENDS+=	${PYPKGPREFIX}-libcst>=0.3.18:../../lang/py-libcst
TEST_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	isort isort-identify-imports

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 9.0.1
# 5 failed, 632 passed, 2 skipped, 2 errors

pre-test:
	${LN} -fs ${PREFIX}/bin/isort-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/isort

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
