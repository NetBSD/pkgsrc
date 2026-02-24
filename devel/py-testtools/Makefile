# $NetBSD: Makefile,v 1.30 2026/02/24 20:02:48 adam Exp $

DISTNAME=	testtools-2.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-fixtures>=2.0:../../devel/py-fixtures
# circular test dependency
# https://github.com/testing-cabal/testscenarios/issues/4
#TEST_DEPENDS+=	${PYPKGPREFIX}-testresources-[0-9]*:../../devel/py-testresources
#TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
