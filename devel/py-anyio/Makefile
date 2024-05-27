# $NetBSD: Makefile,v 1.21 2024/05/27 14:46:28 adam Exp $

DISTNAME=	anyio-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/anyio
COMMENT=	High level compatibility layer for multiple asynchronous event loops
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-idna>=2.8:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.1:../../misc/py-sniffio
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.2.0:../../devel/py-exceptiongroup
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.6.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.17:../../devel/py-uvloop

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0.2:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
