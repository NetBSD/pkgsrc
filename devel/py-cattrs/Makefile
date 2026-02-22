# $NetBSD: Makefile,v 1.15 2026/02/22 11:10:44 wiz Exp $

DISTNAME=	cattrs-26.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cattrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-attrs/cattrs
COMMENT=	Composable complex class support for attrs and dataclasses
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-attrs>=24.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions
# optional dependency
# https://github.com/py-bson/bson/issues/122
#TEST_DEPENDS+=	${PYPKGPREFIX}-bson>=0:../../wip/py-bson
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.6.1:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.111.2:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-immutables>=0.20:../../misc/py-immutables
TEST_DEPENDS+=	${PYPKGPREFIX}-orjson>=0:../../textproc/py-orjson
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=4.0.0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist
# not listed in pyproject but used
TEST_DEPENDS+=	${PYPKGPREFIX}-msgspec>=0:../../devel/py-msgspec
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.1.1:../../devel/py-exceptiongroup
.endif

# as of 25.3.0
# 8 failed, 857 passed, 15 xfailed, 25 errors

# bson, see above; leading to
# tests/preconf/test_pyyaml.py:13: in <module>
#     from ..test_preconf import Everything, everythings, native_unions
# E   ModuleNotFoundError: No module named 'tests.test_preconf'
pre-test:
	${RM} -f ${WRKSRC}/tests/test_preconf.py
	${RM} -f ${WRKSRC}/tests/preconf/test_pyyaml.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
