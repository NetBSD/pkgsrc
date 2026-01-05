# $NetBSD: Makefile,v 1.20 2026/01/05 01:40:53 wiz Exp $

DISTNAME=	pylast-7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylast/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pylast/pylast
COMMENT=	Python interface to Last.fm and Libre.fm
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-random-order-[0-9]*:../../devel/py-test-random-order
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# 93 failed, 44 passed, 9 skipped, 1 xfailed, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
