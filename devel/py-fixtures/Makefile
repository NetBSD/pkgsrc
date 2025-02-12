# $NetBSD: Makefile,v 1.15 2025/02/12 16:25:48 adam Exp $

DISTNAME=	fixtures-4.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/fixtures
COMMENT=	Fixtures, reusable state for writing clean tests and more
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-pbr>=5.7.0:../../devel/py-pbr
# needs py-testtools for testing, but that depends on this
#TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
