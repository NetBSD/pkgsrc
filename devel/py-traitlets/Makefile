# $NetBSD: Makefile,v 1.36 2026/05/11 06:26:07 adam Exp $

DISTNAME=	traitlets-5.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/traitlets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/traitlets
COMMENT=	Traitlets Python config system
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-argcomplete>=3.0.3:../../devel/py-argcomplete
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-testing-[0-9]*:../../lang/py-test-mypy-testing

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
