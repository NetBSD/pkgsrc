# $NetBSD: Makefile,v 1.9 2024/09/12 19:45:33 adam Exp $

DISTNAME=	cattrs-24.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cattrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-attrs/cattrs
COMMENT=	Composable complex class support for attrs and dataclasses
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>0:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-attrs>=23.1.0:../../devel/py-attrs
# optional dependency
# https://github.com/py-bson/bson/issues/122
#TEST_DEPENDS+=	${PYPKGPREFIX}-bson>=0:../../wip/py-bson
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.4.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.79.4:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-immutables>=0.20:../../misc/py-immutables
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=4.0.0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.1.1:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1.0:../../devel/py-typing-extensions
.endif

# bson, see above
# as of 23.2.1
# 597 passed, 1 skipped, 15 xfailed
pre-test:
	${RM} -f ${WRKSRC}/tests/test_preconf.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
