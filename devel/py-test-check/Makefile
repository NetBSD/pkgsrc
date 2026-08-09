# $NetBSD: Makefile,v 1.19 2026/08/09 06:23:38 adam Exp $

DISTNAME=	pytest_check-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-check/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/okken/pytest-check
COMMENT=	Pytest plugin that allows multiple failures per test
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
