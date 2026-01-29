# $NetBSD: Makefile,v 1.4 2026/01/29 14:08:22 adam Exp $

DISTNAME=	pytest_mypy_testing-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy-testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidfritzsche/pytest-mypy-testing
COMMENT=	Pytest plugin to check mypy output
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-mypy>=1.0:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-test>=8:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
