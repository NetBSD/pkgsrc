# $NetBSD: Makefile,v 1.7 2023/12/01 12:58:12 adam Exp $

DISTNAME=	cattrs-23.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cattrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-attrs/cattrs
COMMENT=	Composable complex class support for attrs and dataclasses
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-attrs>=20:../../devel/py-attrs
# optional dependency
# https://github.com/py-bson/bson/issues/122
#TEST_DEPENDS+=	${PYPKGPREFIX}-bson>=0:../../wip/py-bson
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-immutables>=0:../../misc/py-immutables
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# bson, see above
# as of 23.2.1
# 597 passed, 1 skipped, 15 xfailed
pre-test:
	${RM} -f ${WRKSRC}/tests/test_preconf.py

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=0:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
