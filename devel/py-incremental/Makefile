# $NetBSD: Makefile,v 1.12 2026/10/16 17:15:27 adam Exp $

DISTNAME=	incremental-24.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/incremental/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hawkowl/incremental
COMMENT=	Small library that versions your Python projects
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.6.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=17.0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	incremental

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
