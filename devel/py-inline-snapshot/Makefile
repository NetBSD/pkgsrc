# $NetBSD: Makefile,v 1.3 2025/01/14 08:38:20 adam Exp $

DISTNAME=	inline_snapshot-0.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/inline_snapshot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://15r10nk.github.io/inline-snapshot/latest/
COMMENT=	Golden master/snapshot/approval testing library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-asttokens>=2.0.5:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-executing>=2.1.0:../../lang/py-executing
DEPENDS+=	${PYPKGPREFIX}-rich>=13.7.1:../../comms/py-rich
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=24.3.0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals>=0.7.0:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.75.5:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=1.2.0:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic>=1:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer>=0.4.8:../../devel/py-test-freezer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests>=0.11.0:../../devel/py-test-subtests
# tests also need unpackaged:
#  "pyright>=1.1.359",

# as of 0.14.0
# 4 failed, 339 passed, 39 skipped, 5 warnings, 3 errors, 903 subtests

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.0:../../textproc/py-tomli
.endif

pre-test:
	cd ${BUILDLINK_DIR}/bin && ${LN} -sf ${PREFIX}/bin/pytest-${PYVERSSUFFIX} pytest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
