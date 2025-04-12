# $NetBSD: Makefile,v 1.5 2025/04/12 21:10:58 adam Exp $

DISTNAME=	pytest_subprocess-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-subprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aklajnert/pytest-subprocess
COMMENT=	Pytest plugin to fake subprocess
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test>=4.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures-[0-9]*:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.15.1:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
