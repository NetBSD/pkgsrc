# $NetBSD: Makefile,v 1.7 2026/05/12 06:25:34 adam Exp $

DISTNAME=	pytest_subprocess-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-subprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aklajnert/pytest-subprocess
COMMENT=	Pytest plugin to fake subprocess
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test>=4.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.15.1:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
