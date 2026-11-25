# $NetBSD: Makefile,v 1.47 2026/11/25 06:37:12 adam Exp $

DISTNAME=	babel-2.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://babel.pocoo.org/
COMMENT=	Collection of tools for internationalizing Python applications
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.0:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pybabel

# as of 2.16.0
# 1 failed, 6012 passed, 1076 skipped, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
