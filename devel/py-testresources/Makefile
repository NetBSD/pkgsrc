# $NetBSD: Makefile,v 1.15 2026/07/02 08:33:04 adam Exp $

DISTNAME=	testresources-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testresources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testresources
COMMENT=	Pyunit extension for managing expensive test resources
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
