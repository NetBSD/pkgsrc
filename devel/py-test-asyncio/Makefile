# $NetBSD: Makefile,v 1.45 2026/10/26 05:25:29 adam Exp $

DISTNAME=	pytest_asyncio-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=8.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.7.1:../../devel/py-hypothesis

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12:../../devel/py-typing-extensions
.endif

# test status as of 1.1.0 after 'make install'
# 168 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
