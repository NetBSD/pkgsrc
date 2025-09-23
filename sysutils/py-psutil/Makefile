# $NetBSD: Makefile,v 1.62 2025/09/23 06:28:44 adam Exp $

DISTNAME=	psutil-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psutil
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-pyperf>0:../../devel/py-pyperf
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-instafail>0:../../devel/py-test-instafail
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests>0:../../devel/py-test-subtests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>0:../../devel/py-test-xdist

USE_TOOLS+=	gmake

# https://github.com/giampaolo/psutil/issues/2465
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m psutil.tests

# with this method, as of 7.1.0, after installation:
# 2 failed, 313 passed, 277 skipped, 2 warnings, 365 subtests passes
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${GMAKE} test

.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
