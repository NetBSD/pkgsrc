# $NetBSD: Makefile,v 1.61 2025/09/22 21:50:35 wiz Exp $

DISTNAME=	psutil-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psutil
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-pyperf>0:../../devel/py-pyperf
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>0:../../devel/py-test-xdist

USE_TOOLS+=	gmake

# https://github.com/giampaolo/psutil/issues/2465
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m psutil.tests

# with this method, as of 7.0.0, after installation:
# 6 failed, 306 passed, 272 skipped, 2 warnings, 1 error
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${GMAKE} test

.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
