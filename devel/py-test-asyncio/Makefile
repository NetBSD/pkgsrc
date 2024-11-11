# $NetBSD: Makefile,v 1.33 2024/11/11 07:28:24 wiz Exp $

DISTNAME=	pytest_asyncio-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=51.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=8.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.7.1:../../devel/py-hypothesis

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
