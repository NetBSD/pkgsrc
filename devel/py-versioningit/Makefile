# $NetBSD: Makefile,v 1.12 2026/10/16 17:14:42 adam Exp $

DISTNAME=	versioningit-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/versioningit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jwodder/versioningit
COMMENT=	Use version control tags to discover version numbers
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=17.1:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.0:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	versioningit

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
