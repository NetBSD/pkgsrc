# $NetBSD: Makefile,v 1.60 2025/04/14 08:31:30 adam Exp $

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
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>0:../../devel/py-test-xdist

# https://github.com/giampaolo/psutil/issues/2465
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m psutil.tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
