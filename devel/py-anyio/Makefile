# $NetBSD: Makefile,v 1.10 2022/01/16 08:39:57 adam Exp $

DISTNAME=	anyio-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/anyio
COMMENT=	High level compatibility layer for multiple asynchronous event loops
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-idna>=2.8:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.1:../../misc/py-sniffio
DEPENDS+=	${PYPKGPREFIX}-uvloop-[0-9]*:../../devel/py-uvloop
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme
#TEST_DEPEDS+=	${PYPKGPREFIX}-trio

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-uvloop

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
