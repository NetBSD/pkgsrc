# $NetBSD: Makefile,v 1.37 2026/10/16 17:36:00 adam Exp $

DISTNAME=	hatchling-1.32.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatchling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hatch.pypa.io/
COMMENT=	Modern, extensible Python build backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.1:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-trove-classifiers>=0:../../misc/py-trove-classifiers

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	hatchling

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
