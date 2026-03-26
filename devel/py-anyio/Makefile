# $NetBSD: Makefile,v 1.34 2026/03/26 10:58:23 adam Exp $

DISTNAME=	anyio-4.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/anyio
COMMENT=	High level compatibility layer for multiple asynchronous event loops
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-idna>=2.8:../../www/py-idna
#TODO:
#TEST_DEPENDS+=	${PYPKGPREFIX}-blockbuster>=1.5.23
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.2.0:../../devel/py-exceptiongroup
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.6.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-truststore>=0.9.1:../../security/py-truststore
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.21:../../devel/py-uvloop

USE_LANGUAGES=	# none

# 12 failed, 1511 passed, 184 skipped, 6 xfailed
# as of 4.6.2.post1
# Fatal Python error: Aborted

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0.2:../../devel/py-exceptiongroup
.endif
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
