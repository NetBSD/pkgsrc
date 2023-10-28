# $NetBSD: Makefile,v 1.20 2023/10/28 19:57:16 wiz Exp $

DISTNAME=	structlog-21.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/structlog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.structlog.org/
COMMENT=	Painless structural logging
LICENSE=	apache-2.0 AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.2.8:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly-[0-9]*:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# needs to be installed first
# as of 21.5.0
# 620 passed, 18 skipped, 1 xfailed, 9 warnings, 43 errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
