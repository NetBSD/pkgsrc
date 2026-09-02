# $NetBSD: Makefile,v 1.30 2026/09/02 19:27:46 adam Exp $

DISTNAME=	sqlparse-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andialbrecht/sqlparse
COMMENT=	Non-validating SQL parser
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	sqlformat

REPLACE_PYTHON+=	sqlparse/cli.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
